#include<bits/stdc++.h>
using namespace std ;
const int N = 49;
int dp[N][N][N][N],sum[N][N];
char s[N][N];
main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,T,i,j,k,l ;
    cin >> n >> m >> T ;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin >> s[i][j];
            sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+(s[i][j]-'0');
        }
    }
    for(i=n;i>=1;i--)for(j=m;j>=1;j--)
    {
        for(k=i;k<=n;k++)for(l=j;l<=m;l++)
        {
            int cnt=0;
            cnt+=dp[i][j][k-1][l]+dp[i+1][j][k][l];
            cnt+=-dp[i+1][j][k-1][l];
            cnt+=dp[i][j][k][l-1];
            cnt+=-dp[i][j][k-1][l-1];
            cnt+=-dp[i+1][j][k][l-1];
            cnt+=dp[i+1][j][k-1][l-1];
            cnt+=dp[i][j+1][k][l];
            cnt+=-dp[i][j+1][k-1][l];
            cnt+=-dp[i+1][j+1][k][l];
            cnt+=dp[i+1][j+1][k-1][l];
            cnt-=dp[i][j+1][k][l-1];
            cnt+=dp[i][j+1][k-1][l-1];
            cnt+=dp[i+1][j+1][k][l-1];
            cnt-=dp[i+1][j+1][k-1][l-1];
            if(sum[k][l]-sum[k][j-1]-sum[i-1][l]+sum[i-1][j-1]==0)cnt++;
            dp[i][j][k][l]+=cnt;
        }
    }
    while(T--)
    {
        cin >> i >> j >> k >> l ;
        cout << dp[i][j][k][l] << '\n' ;
    }
}
