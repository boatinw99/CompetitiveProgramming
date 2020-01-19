#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 1e5+9,MIN=-1e8 ;
struct Tree
{
    int pre,suf,ans;
};
multiset<int> spre[N],ssuf[N],sans[N];
vector<pii> G[N];
vector<int> chain[N];
bool b[N];
int maxpre[N],maxsuf[N],ANS[N],numb=0;
int pos[N],path[N],par[N],ch[N],hy[N],sub[N],depth[N];
int n,no=1,p=1,x,y ;
Tree st[N*4];
void dfs(int u)
{
    int max1=0,ind=0;
    sub[u]=1;
    depth[u]=depth[par[u]]+1;
    for(auto it:G[u])
    {
        if(it.first!=par[u])
        {
            par[it.fi]=u;
            path[it.fi]=path[u]+it.se;
            dfs(it.fi);
            sub[u]+=sub[it.fi];
            if(max1<sub[it.fi])max1=sub[it.fi],ind=it.fi;
        }
    }
    hy[u]=ind ;
}
void hld(int u)
{
    chain[no].emplace_back(u);
    pos[u]=p++;
    ch[u]=no;
    if(hy[u])hld(hy[u]);
    for(auto it:G[u])
    {
        if(it.fi!=par[u]&&it.fi!=hy[u])
        {
            no++;
            hld(it.fi);
        }
    }
}
Tree operate(Tree t1,Tree t2)
{
    Tree t;
    t.ans=max(t1.ans,t2.ans);
    t.ans=max(t.ans,t1.pre+t2.suf);
    t.pre=max(t1.pre,t2.pre);
    t.suf=max(t1.suf,t2.suf);
    return t;
}
void construct(int l,int r,int m)
{
    int mid=l+r>>1;
    if(l==r)st[m]={maxpre[l],maxsuf[l],0};
    else
    {
        construct(l,mid,m*2); construct(mid+1,r,m*2+1);
        st[m]=operate(st[m*2],st[m*2+1]);
    }
}
void update(int l,int r,int m)
{
    int mid=l+r>>1;
    if(r<x||l>x)return ;
    if(l==x&&r==x)
    {
        st[m]={maxpre[l],maxsuf[l],ANS[l]};
        return ;
    }
    update(l,mid,m*2); update(mid+1,r,m*2+1);
    st[m]=operate(st[m*2],st[m*2+1]);
}
Tree findans(int l,int r,int m)
{
    int mid=l+r>>1;
    if(r<x||l>y)return {MIN,MIN,MIN} ;
    if(l>=x&&r<=y)return st[m];
    return operate(findans(l,mid,m*2),findans(mid+1,r,m*2+1));
}
void color(int u)
{
    multiset<int>::iterator itmt;
    int px,py,pz,temp1,temp2,i ;
    Tree t ;
    i=u;

    if(b[i]==0)
    {
        numb++;
        b[i]=1;
        /// itself
        px=pos[i];
        itmt=spre[i].find(-path[i]);
        spre[i].erase(itmt);
        spre[i].insert(MIN);
        itmt=ssuf[i].find(path[i]);
        ssuf[i].erase(itmt);
        ssuf[i].insert(MIN);
        itmt = ssuf[i].end(); itmt--; temp1=*itmt;
        if(ssuf[i].size()>1){itmt--; temp2=*itmt;}
        if(ssuf[i].size()==1)ANS[px]=0;
        else ANS[px]=max(temp1+temp2-2*path[i],
                            *sans[i].rbegin());
        maxsuf[px]=temp1;
    }
    else
    {
        b[i]=0;
        numb--;
        px=pos[i];
        itmt=spre[i].find(MIN);
        spre[i].erase(itmt);
        spre[i].insert(-path[i]);
        itmt=ssuf[i].find(MIN);
        ssuf[i].erase(itmt);
        ssuf[i].insert(path[i]);
        itmt = ssuf[i].end(); itmt--; temp1=*itmt;
        if(ssuf[i].size()>1){itmt--; temp2=*itmt;}
        if(ssuf[i].size()==1)ANS[px]=0;
        else ANS[px]=max(temp1+temp2-2*path[i],
                            *sans[i].rbegin());
        maxsuf[px]=temp1;
    }
    while(ch[i]!=1)
    {
        px=*chain[ch[i]].begin(); py=chain[ch[i]].size(); pz=pos[px];
        x=pz; y=pz+py-1;
        t=findans(1,n,1);
        pz=par[px];
        itmt=spre[pz].find(t.suf-2*path[pz]);
        spre[pz].erase(itmt);
        itmt=ssuf[pz].find(t.suf);
        ssuf[pz].erase(itmt);
        itmt=sans[pz].find(t.ans);
        sans[pz].erase(itmt);
        i=pz;
    }
    i=u ;
    while(ch[i]!=0)
    {
        px=*chain[ch[i]].begin(); py=chain[ch[i]].size();pz=par[px];
        maxpre[pos[i]]=*spre[i].rbegin();
        x=pos[i];
        update(1,n,1);
        if(ch[i]==1)break;
        i=pz ;
        x=pos[px]; y=pos[px]+py-1;
        t=findans(1,n,1);
        spre[pz].insert(t.suf-2*path[pz]);
        ssuf[pz].insert(t.suf);
        sans[pz].insert(t.ans);
        itmt = ssuf[pz].end(); itmt--; temp1=*itmt;
        maxsuf[pos[pz]]=temp1;
        if(ssuf[pz].size()>1){itmt--; temp2=*itmt;}
        if(ssuf[pz].size()==1)ANS[pos[pz]]=0;
        else ANS[pos[pz]]=max(temp1+temp2-2*path[pz],
                            *sans[pz].rbegin());
    }
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    multiset<int>::iterator itmt;
    Tree t ;
    int i,j,u,v,wi,px,py,pz,T,temp1,temp2,z ;
    char c ;
    cin >> n ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v >> wi ;;
        G[u].emplace_back(v,wi);
        G[v].emplace_back(u,wi);
    }
    dfs(1); hld(1);
    for(i=1;i<=n;i++)
    {
        px=pos[i];
        maxpre[px]=-path[i];
        maxsuf[px]=path[i];
        ANS[px]=0 ;
        sans[i].insert(0);
        spre[i].insert(-path[i]);
        ssuf[i].insert(path[i]);
    }
    construct(1,n,1);
    vector<pii> schain;
    for(i=2;i<=no;i++)schain.emplace_back(depth[chain[i][0]],i);
    sort(schain.begin(),schain.end(),greater<pii>());
    for(pii it : schain)
    {
        i=it.se;
        px=*chain[i].begin();
        py=chain[i].size();
        pz=pos[px]; /// pos of head chain[i];
        x=pz; y=pz+py-1;
        t=findans(1,n,1);
        pz=par[px];
        py=pos[pz];/// pos of parent head chain[i];
        spre[pz].insert(t.suf-2*path[pz]);
        maxpre[py]=*spre[pz].rbegin();
        sans[pz].insert(t.ans);
        ssuf[pz].insert(t.suf);
        itmt = ssuf[pz].end(); itmt--; temp1=*itmt;
        itmt--; temp2=*itmt;
        ANS[py]=max(ANS[py],t.ans);
        ANS[py]=max(ANS[py],temp1+temp2-2*path[pz]);
        maxsuf[py]=temp1;
        x=py;
        update(1,n,1);
    }
    cin >> T ;
    while(T--)
    {
        cin >> c ;
        if(c=='A')
        {
            x=1,y=chain[1].size();
            if(numb==n)cout << "They have disappeared." << '\n';
            else
            {
                z=findans(1,n,1).ans;
                z=max(z,0);
                cout << z << '\n';
            }
        }
        else {cin>> u ;color(u);}
    }
}
