#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 ,inf = 2e9 ;
queue<int> q ;
vector<int> g[N];
int match[N],dist[N],n,m ;
bool bfs()
{
    for(int i=1;i<=n;i++)
    {
        if(!match[i])
        {
            dist[i]=0;
            q.push(i);
        }
        else dist[i]=inf ;
    }
    dist[0]=inf ;
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        if(!u)continue ;
        for(auto it:g[u])
        {
            if(dist[match[it]]==inf)
            {
                dist[match[it]]=dist[u]+1;
                q.push(match[it]);
            }
        }
    }
    return dist[0]!=inf ;
}
bool dfs0(int u)
{
    if(!u)return 1;
    for(auto it:g[u])
    {
        if(dist[match[it]]==dist[u]+1)
        {
            if(dfs0(match[it]))
            {
                match[it]=u;
                match[u]=it;
                return 1 ;
            }
        }
    }
    dist[u]=inf ;
    return 0 ;
}
int hopcroft_carp()
{
    int ret = 0 ;
    while(bfs())for(int i=1;i<=n;i++)if(!match[i]&&dfs0(i))ret++;
    return ret ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int p,u,v ;
    cin >> n >> m >> p ;
    for(int i=1;i<=p;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v+n);
    }
    cout << hopcroft_carp() ;
    return 0 ;
}
