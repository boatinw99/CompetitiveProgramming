#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii;
const int N = 1e5+9 , LOG = log2(N)+1;
vector<pair<pii,int> > query ;
vector<pii> G[N],doct ;
int up[N][LOG],MAX[N][LOG] ;
int DAG[N],tin[N],tout[N];
int times=0;
void dfs(int u,int v)
{
    up[u][0]=v;
    tin[u]=++times;
    for(int i=1;i<LOG;i++)
    {
        up[u][i]=up[up[u][i-1]][i-1];
        MAX[u][i]=max(MAX[u][i-1],MAX[up[u][i-1]][i-1]);
    }
    for(auto it:G[u])
    {
        MAX[it.first][0]=it.second ;
        dfs(it.first,u);
    }
    tout[u]=++times;
}
bool Islca(int u,int v){return tin[u]<=tout[v]&&tout[u]>=tout[v] ;}
int lca(int u,int v)
{
    int max1=0 ;
    for(int i=LOG-1;i>=0;i--)
        if(!Islca(up[v][i],u))max1=max(max1,MAX[v][i]),v=up[v][i];
    return max(max1,MAX[v][0]) ;
}
int findlca(int u,int v)
{
    if(Islca(u,v))return lca(u,v);
    return INT_MAX ;
}
main()
{
    int n,i,j,type,T,u,v,x ;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> T ;
    for(i=1;i<=T;i++)
    {
        cin >> type;
        if(type==1)
        {
            cin >> u >> v ;
            DAG[u]++;
            G[v].push_back({u,i});
        }
        else if(type==2)
        {
            cin >> u ;
            doct.push_back({u,i});
        }
        else
        {
            cin >> u >> v ;
            query.push_back({{u,v},i});
        }
    }
    for(i=1;i<=n;i++)
    {
        if(!DAG[i])dfs(i,i);
    }
    for(auto it:query)
    {
        ///employee doc times
        u=it.first.first; v=it.first.second ; i=it.second;
        if(u==doct[v-1].first)
        {
            cout << "YES" << '\n';
            continue ;
        }
        x=findlca(u,doct[v-1].first);
        if(x<=i&&x<=doct[v-1].second)cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
}
