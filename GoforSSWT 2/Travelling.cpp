#include<bits/stdc++.h>
using namespace std ;
int dp[209][209];
int dij[16][1<<16];
int a[20];
priority_queue<pair<int,pair<int,int> > > pq;
///T node mask
main()
{
    int n,m,K,i,j,d,k,u,v,t,town,mask ;
    scanf("%d %d %d",&n,&m,&K);
    for(i=1;i<=K;i++)scanf("%d",&a[i]);
    a[0]=1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            dp[i][j]=1e6;
        }
    }
    int x=1<<(K+1);
    for(i=0;i<=K;i++)for(j=0;j<x;j++)dij[i][j]=2e6;
    while(m--)
    {
        scanf("%d %d %d",&u,&v,&t);
        dp[u][v]=t;
        dp[v][u]=t;
    }
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    pq.push({0,{0,1}});
    dij[0][1]=0;
    int ans=2e6;
    while(!pq.empty())
    {
        t=pq.top().first*-1;
        town=pq.top().second.first;
        mask=pq.top().second.second;
        pq.pop();
        if(mask==x-1)ans=min(ans,t+dp[a[town]][n]);
        if(t!=dij[town][mask])continue;
        for(i=0;i<=K;i++)
        {
            if(t+dp[a[town]][a[i]]<dij[i][mask|(1<<i)])
            {
                dij[i][mask|(1<<i)]=t+dp[a[town]][a[i]];
                pq.push({-t-dp[a[town]][a[i]],{i,mask|(1<<i)}});
            }
        }
    }
    printf("%d",ans);
}
