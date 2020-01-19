#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 2009 ,inf = 2e9 ;
int n,m ;
queue<int> q ;
vector<int> L,R,g[N];
vector<pii> edge ;
int dist[N],match[N] ;
void init()
{
    L.clear();
    R.clear();
    edge.clear();
    memset(match,0,sizeof match);
    for(int i=0;i<N;i++)g[i].clear();
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
    if(!u)return 1 ;
    for(auto it:g[u])
    {
        if(dist[match[it]]==dist[u]+1)
        {
            if(dfs0(match[it]))
            {
                match[it]=u ;
                match[u]=it ;
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
    while(T--)
    {
        int p,u,v ;
        cin >> p ;
        init();
        for(int i=1;i<=p;i++)
        {
            cin >> u >> v ;
            edge.emplace_back(u,v);
            L.emplace_back(u);
            R.emplace_back(v);
        }
        sort(L.begin(),L.end());
        sort(R.begin(),R.end());
        L.resize(unique(L.begin(),L.end())-L.begin());
        R.resize(unique(R.begin(),R.end())-R.begin());
        n=L.size();
        m=R.size();
        for(auto it:edge)
        {
            int l = lower_bound(L.begin(),L.end(),it.fi)-L.begin()+1;
            int r = lower_bound(R.begin(),R.end(),it.se)-R.begin()+1;
            g[l].emplace_back(n+r);
        }
        cout << hopcroft_carp() << '\n' ;
    }
    return 0 ;
}
