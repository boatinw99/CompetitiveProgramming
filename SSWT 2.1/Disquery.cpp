#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii;
const int N = 1e5+9 , LOG=log2(N);
vector<pii> G[N];
int up[N][LOG+1];
int MIN[N][LOG+1],tin[N],tout[N];
int MAX[N][LOG+1];
int times=0;
void dfs(int u,int v)
{
    up[u][0]=v ;
    tin[u]=++times;
    for(int i=1;i<=LOG;i++)
    {
        up[u][i]=up[up[u][i-1]][i-1];
        MIN[u][i]=min(MIN[u][i-1],MIN[up[u][i-1]][i-1]);
        MAX[u][i]=max(MAX[u][i-1],MAX[up[u][i-1]][i-1]);
    }
    for(auto it:G[u])
    {
        if(it.first!=v)
        {
            MAX[it.first][0]=MIN[it.first][0]=it.second ;
            dfs(it.first,u);
        }
    }
    tout[u]=++times;
}
bool Islca(int u,int v)
{
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
pii findlca(int u,int v)
{
    int min1=INT_MAX,max1=0,u1=u,LCA=0 ;
    if(Islca(u,v))
    {
        for(int i=LOG;i>=0;i--)
        {
            if(!Islca(up[v][i],u))
            {
                min1=min(min1,MIN[v][i]);
                max1=max(max1,MAX[v][i]);
                v=up[v][i];
            }
        }
        min1=min(min1,MIN[v][0]);
        max1=max(max1,MAX[v][0]);
        return {min1,max1};
    }
    if(Islca(v,u))
    {
        swap(u,v);
        for(int i=LOG;i>=0;i--)
        {
            if(!Islca(up[v][i],u))
            {
                min1=min(min1,MIN[v][i]);
                max1=max(max1,MAX[v][i]);
                v=up[v][i];
            }
        }
        min1=min(min1,MIN[v][0]);
        max1=max(max1,MAX[v][0]);
        return {min1,max1};
    }
    for(int i=LOG;i>=0;i--)
    {
        if(!Islca(up[u1][i],v))
        {
            min1=min(min1,MIN[u1][i]);
            max1=max(max1,MAX[u1][i]);
            u1=up[u1][i];
        }
    }
    min1=min(min1,MIN[u1][0]);
    max1=max(max1,MAX[u1][0]);
    for(int i=LOG;i>=0;i--)
    {
        if(!Islca(up[v][i],u))
        {
            min1=min(min1,MIN[v][i]);
            max1=max(max1,MAX[v][i]);
            v=up[v][i];
        }
    }
    min1=min(min1,MIN[v][0]);
    max1=max(max1,MAX[v][0]);
    return {min1,max1};
}
main()
{
    int n,i,j,u,v,wi,T ;
    pii ans ;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n ;
    MIN[1][0]=INT_MAX ;
    MAX[1][0]=0;
    for(i=1;i<n;i++)
    {
        cin >> u >> v >> wi ;
        G[u].push_back({v,wi});
        G[v].push_back({u,wi});
    }
    dfs(1,1);
    cin >> T ;
    while(T--)
    {
        cin >> u >> v ;
        ans=findlca(u,v);
        cout << ans.first << " " << ans.second << '\n';
    }
}
