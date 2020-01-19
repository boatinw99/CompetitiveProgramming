#include<bits/stdc++.h>
using namespace std ;
const int N = 10009;
vector<int> path[N];
vector<int>::iterator it ;
queue<pair<int,int> > pq;
int degodd[16];
int visited[N];
int dijks[16][16];
int dp[1<<16],k=0,K;
void Dijkstra(int i,int par)
{
    ///but not dijkstra
    int x,y,*q;
    pq.push({0,i});
    visited[i]=0;
    while(!pq.empty())
    {
        x=pq.front().first;
        y=pq.front().second;
        pq.pop();
        if(visited[y]==x)
        {
            if(path[y].size()%2==1)
            {
                q=lower_bound(degodd,degodd+k,y);
                dijks[par][q-degodd]=x;
            }
            for(it=path[y].begin();it!=path[y].end();it++)
            {
                if(x+1<visited[*it])
                {
                    visited[*it]=x+1;
                    pq.push({x+1,*it});
                }
            }
        }
    }
}
int tsp(int size,int mask)
{
    int i,j,x=0,y=0 ;
    if(size==2)
    {
        for(i=0;i<k;i++)
        {
            for(j=0;j<k;j++)
            {
                if(((1<<i)&mask)!=0&&((1<<j)&mask)!=0&&i!=j)
                {
                    dp[mask]=dijks[i][j];
                    return dp[mask];
                }
            }
        }
    }
    if(dp[mask]>0)return dp[mask];
    dp[mask]=INT_MAX;
    for(i=0;i<k;i++)
    {
        for(j=0;j<k;j++)
        {
            if(((1<<i)&mask)!=0&&((1<<j)&mask)!=0&&i!=j)
            {
                dp[mask]=min(dijks[i][j]+
            tsp(size-2,mask-(1<<i)-(1<<j)),
                             dp[mask]);
            }
        }
    }
    return dp[mask];
}
main()
{
    int n,m,u,v,p=0,i,j,x,y,ans ;
    scanf("%d %d",&n,&m);
    ans=m;
    while(m--)
    {
        scanf("%d %d",&u,&v);
        path[u].push_back(v);
        path[v].push_back(u);
    }
    for(i=1;i<=n;i++)
    {
        if(path[i].size()%2==1)
        {
            degodd[p++]=i;
            k++;
        }
    }
    for(i=0;i<k;i++)
    {
        for(j=1;j<=n;j++)visited[j]=INT_MAX;
        Dijkstra(degodd[i],i);
    }
    K=(1<<k)-1;
    printf("%d",ans-tsp(k,K));
}
