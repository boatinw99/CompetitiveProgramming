#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 ;
int dp[N];
char s[4];
main()
{
    int n,k,m,i,j,max1=0 ;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%s",&s);
        m=strlen(s);
        dp[i]=dp[i-1];
        if(m==2&&s[0]=='U'&&s[1]=='R')dp[i]++;
    }
    for(i=k;i<=n;i++)max1=max(max1,dp[i]-dp[i-k]);
    printf("%d",max1);
}
