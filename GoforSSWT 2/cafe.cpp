#include<bits/stdc++.h>
using namespace std ;
const int N = 1e3+9;
vector<int> path[N];
struct P
{
    int x,y,z ;
};
P dp[N];
void dfs(int u,int v)
{
    vector<int>::iterator it ;
    int max1=0;
    dp[u].x = 1 ; dp[u].y=0; dp[u].z=0;
    for(it=path[u].begin();it!=path[u].end();it++)
    {
        if(*it!=v)
        {
            dfs(*it,u);
            dp[u].z+=dp[*it].y;
            dp[u].y+=dp[*it].x;
            dp[u].x+=dp[*it].y;
            max1=max(max1,dp[*it].z+1-dp[*it].y);
        }
    }
    dp[u].x+=max1;
    dp[u].y=max(dp[u].y,dp[u].z);
    dp[u].x=max(dp[u].x,dp[u].y);
}
main()
{
    int Q,i,j,n,u,v ;
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%d",&n);
        for(i=1;i<n;i++)
        {
            scanf("%d %d",&u,&v);
            path[u].push_back(v);
            path[v].push_back(u);
        }
        dfs(1,1);
        printf("%d\n",dp[1].x);
        for(i=1;i<=n;i++)path[i].clear();
    }
}
