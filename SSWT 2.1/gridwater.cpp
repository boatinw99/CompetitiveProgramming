#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+9,L=19 ;
#define f first
#define s second
#define pii pair<int,int>
vector<pii> g[N],tree[N];
vector<pair<pii,int> > notin;
priority_queue<pair<int,pii> > pq;
bool b[N];
int tin[N],tout[N],up[N][L],path[N][L];
int times=0;
void dfs(int u,int v)
{
    tin[u]=++times;
    up[u][0]=v;
    for(int i=1;i<L;i++)
    {
        up[u][i]=up[up[u][i-1]][i-1];
        path[u][i]=max(path[u][i-1],path[up[u][i-1]][i-1]);
    }
    for(auto it:tree[u])
    {
        if(it.f!=v)
        {
            path[it.f][0]=it.s;
            dfs(it.f,u);
        }
    }
    tout[u]=++times;
}
bool Islca(int u,int v)
{
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
int findpath(int u,int v)
{
    int max1 = 0 ;
    for(int i=L-1;i>=0;i--)
    {
        if(Islca(u,up[v][i]))
        {
            max1=max(max1,path[v][i]);
            v=up[v][i];
        }
    }
    return max1 ;
}
int findmax(int u,int v)
{
    if(Islca(u,v))
    {
        ///u is lca of v
        return findpath(u,v);
    }
    if(Islca(v,u))
    {
        return findpath(v,u);
    }
    int max1=0;
    for(int i=L-1;i>=0;i--)
    {
        if(!Islca(up[u][i],v))
        {
            max1=max(max1,path[u][i]);
            u=up[u][i];
        }
    }
    max1=max(max1,path[u][0]);
    return max(max1,findpath(up[u][0],v));
}
main()
{
    int n,m,i,j,wi,x,y,p,u,v ;
    scanf("%d %d",&n,&m);
    for(i=1;i<=2*n-1;i++)
    {
        if(i&1)
        {
            for(j=1;j<m;j++)
            {
                scanf("%d",&wi);
                g[(i/2)*m+j].push_back({(i/2)*m+j+1,wi});
                g[(i/2)*m+j+1].push_back({(i/2)*m+j,wi});
            }
        }
        else
        {
            for(j=1;j<=m;j++)
            {
                scanf("%d",&wi);
                g[(i-1)/2*m+j].push_back({(i-1)/2*m+j+m,wi});
                g[(i-1)/2*m+j+m].push_back({(i-1)/2*m+j,wi});
            }
        }
    }
    pq.push({0,{1,1}});
    while(!pq.empty())
    {
        x=pq.top().f*-1;
        y=pq.top().s.f;
        p=pq.top().s.s;
        pq.pop();
        if(!b[y]++)
        {
            tree[y].push_back({p,x});
            tree[p].push_back({y,x});
            for(auto it:g[y])
            {
                if(b[it.f]==0)
                {
                    pq.push({it.s*-1,{it.f,y}});
                }
            }
        }
        else
        {
            notin.push_back({{y,p},x});
        }
    }
    dfs(1,1);
    int ans=INT_MAX,max1 ;
    for(auto it : notin)
    {
        u=it.f.f ; v=it.f.s ; wi=it.s ;
        max1=findmax(u,v);
        ans=min(ans,wi-max1);
    }
    printf("%d ",ans);
}
