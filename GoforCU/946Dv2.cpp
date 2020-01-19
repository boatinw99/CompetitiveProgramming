#include<bits/stdc++.h>
using namespace std ;
const int N = 509;
char s[N];
int a[N];
int skip[N];
int dp[N][N];
main()
{
    int n,m,k,len,l,i,j,pr=0,d,q ;
    scanf("%d %d %d ",&n,&m,&k);
    for(i=1;i<=n;i++)
    {
        gets(s);
        l=0;
        for(j=0;j<m;j++)
        {
            if(s[j]=='1')
            {
                skip[++l]=j;
            }
        }
        a[0]=0;
        for(d=1;d<=l;d++)
        {
            a[d]=N;
            for(j=l;j-d+1>0;j--)
            {
                a[d]=min(a[d],skip[j]-skip[j-d+1]+1);
            }
        }
        dp[i][0]=a[l]+dp[i-1][0];
        for(j=1;j<=k;j++)
        {
            dp[i][j]=N*i;
            for(d=max(l-j,0);d<=l;d++)
            {
                dp[i][j]=min(dp[i][j],dp[i-1][j-l+d]+a[d]);
            }
        }
    }
    printf("%d",dp[n][k]);
}
