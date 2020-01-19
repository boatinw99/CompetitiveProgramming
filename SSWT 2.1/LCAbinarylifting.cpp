#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9,L=18 ;
#define pii pair<int,int>
vector<int> G[N];
int tin[N],tout[N],times=0;
int up[N][L];
void dfs(int u,int v)
{
    tin[u]=++times;
    up[u][0]=v;
    for(int i=1;i<L;i++)
    {
        up[u][i]=up[up[u][i-1]][i-1];
    }
    for(auto it:G[u])
    {
        if(it!=v)
        {
            dfs(it,u);
        }
    }
    tout[u]=++times;
}
bool IsA(int u,int v)
{
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
int findlca(int u,int v)
{
    if(IsA(u,v))return u;
    if(IsA(v,u))return v;
    for(int i=L-1;i>=0;i--)
    {
        if(!IsA(up[u][i],v))
        {
            u=up[u][i];
        }
    }
    return up[u][0];
}
main()
{
    int n,i,j,m,u,v ;
    scanf("%d %d",&n,&m);
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,1);
    while(m--)
    {
        scanf("%d %d",&u,&v);
        printf("%d\n",findlca(u,v));
    }
}
