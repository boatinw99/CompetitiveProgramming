#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+9,LOG=log2(N)+1;
typedef pair<int,int> pii;
typedef long long ll ;
vector<pair<int,pii> > G[N],tree[N];
vector<pair<pii,pii> > non;
priority_queue<pair<int,pair<pii,int> > > pq ;
int up[N][LOG];
int MAX[N][LOG];
int tin[N],tout[N];
ll ans[N];
bool b[N];
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
    for(it : tree[u])
    {
        if(it.first!=v)
        {
            MAX[it.first][0]=it.second.first;
            dfs(it.first,u);
        }
    }
    tout[u]=++times;
}
bool Islca(int u,int v)
{
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
int findlca(int u,int v)
{
    int LCA=0,max1=0,u1=u ;
    if(Islca(u,v))LCA=u;
    if(Islca(v,u))LCA=v,swap(u,v);
    if(LCA==u)
    {
        for(int i=LOG-1;i>=0;i--)
        {
            if(!Islca(up[v][i],u))
            {
                max1=max(max1,MAX[v][i]);
                v=up[v][i];
            }
        }
        return max(max1,MAX[v][0]);
    }
    for(int i=LOG-1;i>=0;i--)
    {
        if(!Islca(up[u1][i],v))
        {
            max1=max(max1,MAX[u1][i]);
            u1=up[u1][i];
        }
    }
    max1=max(max1,MAX[u1][0]);
    for(int i=LOG-1;i>=0;i--)
    {
        if(!Islca(up[v][i],u))
        {
            max1=max(max1,MAX[v][i]);
            v=up[v][i];
        }
    }
    return max(max1,MAX[v][0]);
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i,j,n,m,u,v,x,y,numb,wi ;
    ll mst=0 ;
    cin >> n >> m ;
    for(i=1;i<=m;i++)
    {
        cin >> u >> v >> wi;
        G[u].push_back({v,{wi,i}});
        G[v].push_back({u,{wi,i}});
    }
    ///terminate weight numb
    ///pq -> wi / u,v / numb
    pq.push({0,{{1,1},0}});
    while(!pq.empty())
    {
        x=-pq.top().first;
        u=pq.top().second.first.first;
        v=pq.top().second.first.second;
        numb=pq.top().second.second;
        pq.pop();
        if(!b[u]++)
        {
            mst+=x;
            tree[u].push_back({v,{x,numb}});
            tree[v].push_back({u,{x,numb}});
            for(it:G[u])
            {
                if(b[it.first]==0)
                {
                    pq.push({-it.second.first,
                        {{it.first,u},it.second.second}});
                }
            }
        }
        else
        {
            non.push_back({{u,v},{x,numb}});
        }
    }
    for(i=1;i<=n;i++)
    {
        for(it:tree[i])
        {
            ans[it.second.second]=mst;
        }
    }
    dfs(1,1);
    for(it:non)
    {
        ans[it.second.second]=mst+
            -findlca(it.first.first,it.first.second)+it.second.first;
        //cout <<"a"<<findlca(it.first.first,it.first.second) <<'\n';
    }
    for(i=1;i<=m;i++)cout << ans[i] << '\n';
}
