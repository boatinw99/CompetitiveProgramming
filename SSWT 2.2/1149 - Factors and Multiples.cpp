#include<bits/stdc++.h>
using namespace std ;
const int N = 209 ,inf = 1e9+7;
int a[N],b[N],n,m,dist[N],match[N] ;
queue<int> q ;
vector<int> g[N];
void init()
{
    for(int i=0;i<N;i++)g[i].clear();
    memset(match,0,sizeof match);
}
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
        int u=q.front(); q.pop();
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
    if(!u)return 1 ;
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
    int ans = 0 ;
    while(bfs())for(int i=1;i<=n;i++)if(!match[i]&&dfs0(i))ans++;
    return ans ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int T ;
    cin >> T ;
    for(int t=1;t<=T;t++)
    {
        cin >> n ;
        for(int i=1;i<=n;i++)cin >> a[i];
        cin >> m ;
        for(int j=1;j<=m;j++)cin >> b[j];
        init();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(b[j]%a[i]==0)g[i].emplace_back(j+n);
            }
        }
        cout << "Case " << t << ": " << hopcroft_carp() << '\n' ;
    }
    return 0 ;
}
