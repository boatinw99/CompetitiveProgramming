#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
const int N = 1e6+9 ; 
set<int> g[N];
vector<pii> E,ans,euler[N]; 
int n,m,deg[N];
bool masked[N],del[N];
void dfs0(int u,int v,int par)
{
    if(u!=v)
    {
        g[u].erase(v);
        g[v].erase(u);
        euler[par].push_back({v,u});
    }
    if(!g[u].empty())
    {
        dfs0(*g[u].rbegin(),u,par);
    }
}
void push(int u)
{
    if(masked[u]++)return ;
    for(auto it:euler[u])
    {
        E.push_back(it);
        push(it.se);
    }
}
void comp()
{
    for(int i=0;i<E.size();i+=2)
    {
        if(E[i].fi!=0&&E[i].se!=0)ans.push_back(E[i]);
    }
    for(int i=1;i<E.size();i+=2)
    {
        pii it = E[i] ;
        if(it.fi==0||it.se==0)
        {
            del[it.fi]++;
            del[it.se]++;
        }
    }
    for(int i=1;i<E.size();i+=2)
    {
        pii it = E[i] ;
        if((deg[it.fi]&1)&&del[it.fi]==0)
        {
            del[it.fi]++;
            ans.push_back(it);
        }
        else if((deg[it.se]&1)&&del[it.se]==0)
        {
            del[it.se]++;
            ans.push_back(it);
        }
    }
    E.clear();
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m ;
    for(int i=1,u,v ;i<=m;i++)
    {
        cin >> u >> v ;
        g[u].insert(v);
        g[v].insert(u);
        deg[u]++;
        deg[v]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(deg[i]&1)
        {
            g[0].insert(i);
            g[i].insert(0);
        }
    }
    for(int i=1;i<=n;i++)
    {
        dfs0(i,i,i);
    }
    for(int i=1;i<=n;i++)
    {
        push(i);
        comp();
    }
    cout << ans.size() << '\n' ;
    for(auto it:ans)
    {
        cout << it.fi << " " << it.se << '\n' ;
    }
    return 0 ;
}