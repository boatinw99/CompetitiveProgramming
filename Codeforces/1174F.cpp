#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+9 ; 
vector<int> g[N];
int n,dr,par[N],sz[N],depth[N];
bool vst[N];
int getdist(int x)
{
    printf("d %d\n",x),fflush(stdout);
    scanf("%d",&x);
    return x ; 
}
int next(int x)
{
    printf("s %d\n",x),fflush(stdout);
    scanf("%d",&x);
    return x ;
}
void dfs(int u,int v)
{
    par[u]=v;
    depth[u]=depth[v]+1;
    for(auto it:g[u])
    {
        if(it!=v)
        {
            dfs(it,u); 
        }
    }
}
void dfs0(int u)
{
    sz[u]=1;
    vst[u]++;
    for(auto it:g[u])
    {
        if(!vst[it])
        {
            dfs0(it);
            sz[u]+=sz[it];
        }
    }
    vst[u]=0;
}
int dfs1(int u,int v,int size)
{
    for(auto it:g[u])
    {
        if(it!=v&&!vst[it]&&sz[it]>size/2)
        {
            return dfs1(it,u,size);
        }
    }
    return u ; 
}
int comp(int u)
{
    dfs0(u);
    int ctd = dfs1(u,u,sz[u]);
    int d = getdist(ctd);
    if(d==0)return ctd ;
    vst[ctd]++;
    if(dr==depth[ctd]+d)return comp(next(ctd)); 
    else return comp(par[ctd]);
}
int main()
{
    scanf("%d",&n);
    for(int i=1,u,v ;i<n;i++)
    {
        scanf("%d %d",&u,&v);
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dr = getdist(1);
    depth[0]=-1;
    dfs(1,0);
    printf("! %d\n",comp(1));
    return 0 ;
}