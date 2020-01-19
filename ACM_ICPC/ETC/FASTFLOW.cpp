#include<bits/stdc++.h>
using namespace std ;
const int N = 5e3+9 , inf = 1e9 ;
struct Edge
{
    int u,v,f,c ;
};
long long mflow = 0 ; 
vector<Edge> e;
vector<int> g[N];
queue<int> q ;
int s,t,n,m,lim,depth[N],pt[N];
void addedge(int u,int v,int x)
{
    Edge ed ; 
    ed.u=u,ed.v=v,ed.f=0,ed.c=x;
    g[u].push_back(e.size());
    e.push_back(ed);
    ed.u=v,ed.v=u,ed.f=x,ed.c=x;
    g[v].push_back(e.size());
    e.push_back(ed);
}
bool bfs()
{
    fill(depth,depth+n+1,inf);
    depth[s]=0;
    for(q.push(s);!q.empty();)
    {
        int u = q.front(); q.pop();
        for(auto it:g[u])
        {
            int v = e[it].v ;
            if(depth[v]==inf&&e[it].c-e[it].f>=lim)
            {
                depth[v]=depth[u]+1;
                q.push(v);
            }
        }
    }
    return depth[t]!=inf ;
}
bool dfs(int u,int flow)
{
    if(u==t)return 1 ;
    for(;pt[u]<g[u].size();pt[u]++)
    {
        int id = g[u][pt[u]];
        int v = e[id].v;
        if(depth[v]==depth[u]+1&&e[id].c-e[id].f>=flow)
        {
            if(dfs(v,flow))
            {
                e[id].f+=flow;
                e[id^1].f-=flow;
                return 1 ;
            }
        }
    }
    return 0 ;
}
void dinic()
{
    for(lim=1<<30;lim;)
    {
        if(!bfs())
        {
            lim>>=1;
            continue; 
        }
        memset(pt,0,sizeof pt);
        while(dfs(s,lim))mflow+=lim;
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m ;
    for(int i=1,u,v,x ;i<=m;i++)
    {
        cin >> u >> v >> x ;
        addedge(u,v,x);
        addedge(v,u,x);
    }
    s=1,t=n ;
    dinic();
    cout << mflow << '\n' ;
    return 0 ;
}