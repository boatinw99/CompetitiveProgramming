#include<bits/stdc++.h>
using namespace std ;
int n,k ;
const int N = 1e5+9;
vector<pair<int,int> > path[N];
int a[N],pr=0;
priority_queue<int> pq;
void dfs(int u,int v)
{
    vector<pair<int,int> > ::iterator it;
    a[u]=1;
    for(it=path[u].begin();it!=path[u].end();it++)
    {
        if(it->first!=v)
        {
            dfs(it->first,u);
            a[u]+=a[it->first];
        }
    }
}
void dfs1(int u,int v)
{
    vector<pair<int,int> > ::iterator it;
    for(it=path[u].begin();it!=path[u].end();it++)
    {
        if(it->first!=v)
        {
            if(it->second==0)
            {
                dfs1(it->first,u);
            }
            else
            {
                pq.push(a[it->first]);
            }
        }
    }
}
main()
{
    int i,j,u,v,wi ;
    scanf("%d %d",&n,&k);
    for(i=1;i<n;i++)
    {
        scanf("%d %d %d",&u,&v,&wi);
        path[u].push_back({v,wi});
        path[v].push_back({u,wi});
    }
    dfs(1,1);
    dfs1(1,1);
    int K=n;
    while(!pq.empty()&&K>k)
    {
        K-=pq.top();
        pq.pop();
        pr++;
    }
    printf("%d",K<=k?pr:-1);
}
