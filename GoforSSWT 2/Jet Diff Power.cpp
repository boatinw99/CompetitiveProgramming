#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+9,M=100 ;
int a[N],pre[M+9],post[M+9],dp[M+9];
main()
{
    int n,i,j,A ;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    scanf("%d",&A);
    for(j=1;j<=M;j++)dp[j]=2e9;
    for(j=a[1];j<=M;j++)
    {
        dp[j]=(j-a[1])*(j-a[1]);
    }
    pre[0]=2e9;
    for(i=2;i<=n;i++)
    {
        for(j=1;j<=M;j++)
        {
            pre[j]=post[j]=dp[j];
            pre[j]+=(M-j)*A;
            post[j]+=abs(j-a[i])*A;
            pre[j]=min(pre[j],pre[j-1]);
            dp[j]=2e9;
        }
        for(j=M-1;j>=a[i];j--)
        {
            post[j]=min(post[j],post[j+1]);
        }
        for(j=a[i];j<=M;j++)
        {
            dp[j]=post[j]-(j-a[i])*A+(j-a[i])*(j-a[i]);
        }
        for(j=M;j>=a[i];j--)
        {
            dp[j]=min(dp[j],pre[j]-(M-j)*A+(j-a[i])*(j-a[i]));
        }
    }
    int ans=INT_MAX;
    for(j=1;j<=M;j++)ans=min(ans,dp[j]);
    printf("%d",ans);
}
