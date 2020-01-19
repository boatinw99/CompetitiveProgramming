#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
const int N = 10009;
vector<pii> G[N],edge;
pii hy[N];
int chhd[N],chno[N],no=1,p=1,n;///hld
int par[N],hi[N],sub[N],pos[N];///dfs
int st[N*4];///segment tree max
void update(int l,int r,int x,int val,int m)
{
    int mid=l+r>>1;
    if(l>x||r<x)return ;
    if(l==r&&l==x)st[m]=val;
    else
    {
        update(l,mid,x,val,m*2),update(mid+1,r,x,val,m*2+1);
        st[m]=max(st[m*2],st[m*2+1]);
    }
}
int findmax(int l,int r,int x,int y,int m)
{
    int mid=l+r>>1;
    if(r<x||l>y||x>y)return 0;
    if(l>=x&&r<=y)return st[m];
    return max(findmax(l,mid,x,y,m*2),findmax(mid+1,r,x,y,m*2+1));
}
int findlca(int u,int v)
{
    int max1=0,x,y;
    while(chno[u]!=chno[v])
    {
        if(hi[chhd[chno[u]]]<hi[chhd[chno[v]]])swap(u,v);
        max1=max(max1,findmax(1,n,pos[chhd[chno[u]]],pos[u],1));
        u=par[chhd[chno[u]]];
    }
    if(hi[u]<hi[v])swap(u,v);
    return max(max1,findmax(1,n,pos[v]+1,pos[u],1));
}
void re()
{
    no=1; p=1;
    memset(st,0,sizeof st);
    memset(chhd,0,sizeof chhd);
    memset(chno,0,sizeof chno);
    memset(hy,0,sizeof hy);
    edge.clear();
    for(int i=0;i<N;i++)G[i].clear();
}
void dfs(int u)
{
    int max1=0,ind=0,path=0;
    sub[u]=1;
    hi[u]=hi[par[u]]+1;
    for(auto it:G[u])
    {
        if(it.first!=par[u])
        {
            par[it.first]=u;
            dfs(it.first);
            sub[u]+=sub[it.first];
            if(sub[it.first]>max1)
                max1=sub[it.first],ind=it.first,path=it.second;
        }
    }
    hy[u]={path,ind};
}
void hld(int u)
{
    if(!chhd[no])chhd[no]=u;
    pos[u]=p++;
    chno[u]=no;
    if(hy[u].second)update(1,n,p,hy[u].first,1),hld(hy[u].second);
    for(auto it:G[u])
    {
        if(it.first!=par[u]&&it.first!=hy[u].second)
        {
            no++;
            update(1,n,p,it.second,1);
            hld(it.first);
        }
    }
}
main()
{
    int T,i,j,u,v,wi ;
    char s[10];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        re();
        edge.emplace_back(0,0);
        for(i=1;i<n;i++)
        {
            cin >> u >> v >> wi ;
            G[u].emplace_back(v,wi);
            G[v].emplace_back(u,wi);
            edge.push_back({u,v});
        }
        dfs(1);
        hld(1);
        while(scanf("%s",&s),s[0]!='D')
        {
            scanf("%d %d",&u,&v);
            if(s[0]=='C')
                update(1,n,max(pos[edge[u].first],pos[edge[u].second]),v,1);
            else printf("%d\n",findlca(u,v));
        }
    }
}
