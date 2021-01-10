#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii;
#define fi first
#define se second 
const int N = 1e5+9 , inf = 1e9 ;
pii mx[N];
int dist[N];
queue<int> q ;
vector<int> g[N]; ///store num edge 
bool used_roads[N];
pair<pii,int> edge[N];
vector<int> ans ; 
void trace_back(int u)
{
    if(u==1)return ; 
    int idx = mx[u].se;
    used_roads[idx]++;
    int it = edge[idx].fi.fi;
    if(it==u)it=edge[idx].fi.se ; 
    trace_back(it);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m ; 
    cin >> n >> m ;
    for(int i=1,u,v,clr ;i<=m;i++)
    {
        cin >> u >> v >> clr ; 
        edge[i]={{u,v},clr};
        g[u].emplace_back(i);
        g[v].emplace_back(i);
    }
    fill(mx,mx+N-1,make_pair(-inf,0));
    fill(dist,dist+N-1,inf);
    mx[1]={0,0};
    dist[1]=0 ;
    for(q.push(1);!q.empty();)
    {
        int u = q.front(); q.pop();
        for(auto idx:g[u])
        {
            /// idx is number of edge 
            int it = edge[idx].fi.fi;
            int clr = edge[idx].se; 
            if(it==u)it=edge[idx].fi.se;
            if(dist[u]+1<=dist[it])
            {
                if(dist[it]==inf)q.push(it);
                dist[it]=dist[u]+1;
                mx[it]=max(mx[it],{mx[u].fi+clr,idx});
            }
        }
    }
    trace_back(n);
    for(int i=1;i<=m;i++)
    {
        if(used_roads[i]&&edge[i].se==0)ans.push_back(i);
        if(!used_roads[i]&&edge[i].se==1)ans.push_back(i);
    }
    cout << ans.size() << '\n' ;
    for(auto it:ans)
    {
        cout << edge[it].fi.fi << " " << edge[it].fi.se << " " << (edge[it].se^1) << '\n' ;
    }
    return 0 ;
}