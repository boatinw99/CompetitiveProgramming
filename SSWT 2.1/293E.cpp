#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define fi first
#define se second
#define mid ((l+r)>>1)
const int N = 1e5+9,LOG=log2(N)+1;
struct T
{
    int node,par,wi,depth;
};
vector<pii> g[N];
int le,w,n,sub[N],root[N],id=1,bid;
int st[N*LOG*2],L[N*LOG*2],R[N*LOG*2],mxdepth=0;
queue<T> q ;
bool vst[N];
vector<int> cc ; ///coordinate compression
ll ans=0,ans1=0,ans2=0;
void construct(int l,int r,int m)
{
    if(l==r)
    {
        st[m]=0;
        return ;
    }
    L[m]=++id,R[m]=++id;
    construct(l,mid,L[m]),construct(mid+1,r,R[m]);
    st[m]=0;
}
int update(int l,int r,int x,int m)
{
    if(r<x||l>x)return m;
    int tmp=++id ;
    if(l==r)
    {
        st[tmp]=st[m]+1;
        return tmp ;
    }
    L[tmp]=update(l,mid,x,L[m]);
    R[tmp]=update(mid+1,r,x,R[m]);
    st[tmp]=st[L[tmp]]+st[R[tmp]];
    return tmp ;
}
int findsum(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return 0;
    if(l>=x&&r<=y)return st[m];
    return findsum(l,mid,x,y,L[m])+findsum(mid+1,r,x,y,R[m]);
}
void dfs1(int u)
{
    sub[u]=1;
    vst[u]++;
    for(auto it:g[u])if(!vst[it.fi])
        dfs1(it.fi),sub[u]+=sub[it.fi];
    vst[u]=0;
}
int dfs2(int u,int v,int sz)
{
    for(auto it:g[u])if(it.fi!=v&&!vst[it.fi]&&sub[it.fi]>sz/2)
        return dfs2(it.fi,u,sz);
    return u ;
}
void dfs3(int u,int cst,int depth)
{
    if(depth>le||cst>w)return ;
    int len=min(mxdepth,le-depth);
    int pos=upper_bound(cc.begin(),cc.end(),w-cst)-cc.begin();
    ans1+=findsum(1,n,1,pos,root[len]);
    vst[u]++;
    for(auto it:g[u])if(!vst[it.fi])dfs3(it.fi,cst+it.se,depth+1);
    vst[u]=0;
}
void dfs4(int u,int cst)
{
    cc.emplace_back(cst);
    vst[u]++;
    for(auto it:g[u])if(!vst[it.fi])dfs4(it.fi,cst+it.se);
    vst[u]=0;
}
void clearq()
{
    while(!q.empty())
    {
        T tmp = q.front();
        q.pop();
        int pos=lower_bound(cc.begin(),cc.end(),tmp.wi)-cc.begin()+1;
        mxdepth=tmp.depth;
        if(root[tmp.depth]==0)
        {
            root[tmp.depth]=update(1,n,pos,root[tmp.depth-1]);
        }
        else root[tmp.depth]=update(1,n,pos,root[tmp.depth]);
        for(auto it:g[tmp.node])
        {
            if(it.fi!=tmp.par&&!vst[it.fi])
            {
                q.push({it.fi,tmp.node,tmp.wi+it.se,tmp.depth+1});
            }
        }
    }
}
void dcp(int u)
{
    id=bid ;
    mxdepth=0 ;
    dfs1(u);
    int ctd = dfs2(u,u,sub[u]);
    vst[ctd]++;
    dfs4(ctd,0);
    vst[ctd]++;
    sort(cc.begin(),cc.end());
    for(auto it:g[ctd])if(!vst[it.fi])
    {
        q.push({it.fi,ctd,it.se,1});
        clearq();
        dfs3(it.fi,it.se,1);
        for(int i=1;root[i];i++)root[i]=0;
        id=bid ;
    }
    ans2=ans1;
    ans1=0;
    for(auto it:g[ctd])if(!vst[it.fi])
        q.push({it.fi,ctd,it.se,1});///node par weight depth
    clearq();
    for(auto it:g[ctd])if(!vst[it.fi])dfs3(it.fi,it.se,1);
    int pos=upper_bound(cc.begin(),cc.end(),w)-cc.begin();
    ans1-=ans2;
    ans+=ans1/2+findsum(1,n,1,pos,root[min(mxdepth,le)])-1;
    ans1=0;
    cc.clear();
    vst[ctd]++;
    for(int i=1;root[i];i++)root[i]=0;
    for(auto it:g[ctd])if(!vst[it.fi])dcp(it.fi);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j,u,v,x ;
    cin >> n >> le >> w ;
    for(i=2;i<=n;i++)
    {
        cin >> u >> x ;
        g[u].emplace_back(i,x);
        g[i].emplace_back(u,x);
    }
    root[0]=1;
    construct(1,n,1);
    root[0]=update(1,n,1,1);
    bid=id;
    dcp(1);
    cout << ans ;
}
