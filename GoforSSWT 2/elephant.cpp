#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
int a[N],dp[N];
main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    dp[3]=a[3];
    for(i=4;i<=n;i++)
    {
        dp[i]=max(dp[i-1],dp[i-3]+a[i]);
    }
    printf("%d",dp[n]);
}
