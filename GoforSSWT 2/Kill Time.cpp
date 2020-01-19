#include<bits/stdc++.h>
using namespace std ;
int dp[309][3009];
struct path
{
    int a,b,c,w;
};
path p[5009];
main()
{
    int n,m,K,k,i,j,S,T,x,y,t,wi ;
    scanf("%d %d %d",&n,&m,&K);
    scanf("%d %d",&S,&T);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d %d",&p[i].a,&p[i].b,&p[i].c,&p[i].w);
    }
    for(i=1;i<=n;i++)
    {
        for(k=0;k<=K;k++)dp[i][k]=-1;
    }
    dp[S][0]=0;
    for(k=0;k<K;k++)
    {
        for(i=1;i<=m;i++)
        {
            x=p[i].a; y=p[i].b; t=p[i].w;  wi=p[i].c;
            if(dp[x][k]>=0)
            dp[y][k+t]=max(dp[x][k]+wi,dp[y][k+t]);
            if(dp[y][k]>=0)
            dp[x][k+t]=max(dp[y][k]+wi,dp[x][k+t]);
        }
    }
    int ans=0;
    for(i=1;i<=K;i++)
    {
        ans=max(ans,dp[T][i]);
    }
    if(ans==0)printf("Impossible");
    else printf("%d",ans);
}
