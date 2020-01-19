#include<bits/stdc++.h>
using namespace std ;
const int M = 400 , md = 1e9+7;
int dp[2][M][M];
void upd(int &ret,int cst)
{
    ret=(ret+cst)%md;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,i,j,x,k ;
    cin >> n >> m >> x ;
    if(n>m)
    {
        cout << "0" ;
        return 0 ;
    }
    dp[0][0][0]=1;
    for(i=1;i<=m;i++)
    {
        int now=i&1,prev=now^1;
        for(j=0;j<=n;j++)for(k=0;k<=n;k++)dp[now][j][k]=0;
        for(j=0;j<=n;j++)
        {
            for(k=0;k<=j;k++)
            {
                if(i!=x)///close interval
                {
                    upd(dp[now][j][k],dp[prev][j][k]);
                    if(k<j)upd(dp[now][j][k+1],dp[prev][j][k]);
                }
                if(j<n)///open interval
                {
                    upd(dp[now][j+1][k],dp[prev][j][k]); ///open
                    upd(dp[now][j+1][k+1],dp[prev][j][k]); ///open and close
                }
            }
        }
    }
    int ans = dp[m&1][n][n];
    for(i=1;i<=n;i++)ans=(ans*1ll*i)%md;
    cout << ans ;
}
