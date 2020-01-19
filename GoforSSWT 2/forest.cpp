#include<bits/stdc++.h>
using namespace std ;
const int N = 23;
int a[N][N];
int dp[N][N][N];
pair<int,int> di[4]={{0,1},{0,-1},{1,0},{-1,0}};
vector<pair<int,int> > ex[N][N];
vector<pair<int,int> > ::iterator it ;
priority_queue<pair<int,pair<pair<int,int>,int> > > pq ;
main()
{
    int n,k,p,i,j,x1,y1,x2,y2,d,val,x,y ;
    scanf("%d %d %d",&n,&p,&k);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<p;i++)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        ex[x1][y1].push_back({x2,y2});
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(d=0;d<=p;d++)dp[i][j][d]=1e9;
        }
    }
    dp[0][0][0]=0; pq.push({0,{{0,0},0}});
    while(!pq.empty())
    {
        val=pq.top().first*-1 ; x=pq.top().second.first.first;
        y=pq.top().second.first.second ; d=pq.top().second.second;
        pq.pop();
        if(dp[x][y][d]!=val)
        {
            continue ;
        }
        for(i=0;i<4;i++)
        {
            x1=x+di[i].first; y1=y+di[i].second;
            if(x1>=0&&x1<n&&y1>=0&&y1<n&&
               val+a[x1][y1]<dp[x1][y1][d])
            {
                dp[x1][y1][d]=val+a[x1][y1];
                pq.push({-val-a[x1][y1],{{x1,y1},d}});
            }
        }
        if(d<k&&!ex[x][y].empty())
        {
            for(it=ex[x][y].begin();it!=ex[x][y].end();it++)
            {
                x1=it->first; y1=it->second;
                if(val<dp[x1][y1][d+1])
                {
                    dp[x1][y1][d+1]=val;
                    pq.push({-val,{{x1,y1},d+1}});
                }
            }
        }
    }
    int ans = INT_MAX;
    for(d=0;d<=p;d++)
    {
        ans=min(ans,dp[n-1][n-1][d]);
    }
    printf("%d",ans);
}
