#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
vector<pair<int,int> > path[100009];
ll a[100009];
bool b[100009];
ll query[100009];
int times=0;
int low[100009],disc[100009];
ll n;
int dfs(int i)
{
    vector<pair<int,int> > ::iterator it;
    b[i]++;
    a[i]=1;
    int x=0;
    for(it=path[i].begin();it!=path[i].end();it++)
    {
        if(b[it->first]==0)
        {
            x+=dfs(it->first);

        }
    }
    a[i]+=x;
    return a[i];
}
void dfs1(int u,int v)
{
    vector<pair<int,int> > ::iterator it;
    low[u]=disc[u]=++times;
    for(it=path[u].begin();it!=path[u].end();it++)
    {
        if(disc[it->first]==0)
        {
            dfs1(it->first,u);
            low[u]=min(low[u],low[it->first]);
            if(disc[u]<low[it->first])
            {
                query[it->second]=a[it->first]*(n-a[it->first]);
            }
        }
        else if(it->first!=v)
        {
            low[u]=min(low[u],disc[it->first]);
        }
    }
}
main()
{
    int m,i,j,u,v ;
    scanf("%lld %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&u,&v);
        path[u].push_back({v,i});
        path[v].push_back({u,i});
    }
    for(i=1;i<=n;i++)
    {
        if(path[i].size()==1)
        {
            dfs(i);
            dfs1(i,i);
            break ;
        }
    }
    for(i=1;i<=m;i++)
    {
        printf("%lld ",query[i]);
    }
}
