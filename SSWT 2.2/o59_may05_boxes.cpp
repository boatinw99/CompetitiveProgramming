#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 209 ;
int p = 0 ;
pii a[N];
int dp[N][N];
int cost(int x)
{
    return x*x*x ;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,k,c ;
    cin >> n ;
    for(i=1;i<=n;i++)
    {
        cin >> c ;
        if(c!=a[p].fi)p++;
        a[p].fi=c ;
        a[p].se++;
    }
    for(i=p;i>=1;i--)
    {
        dp[i][i]=cost(a[i].se);
        for(j=i+1;j<=p;j++)
        {
            ///[i,j];
            for(k=i;k<=j;k++)
            {
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
        }
    }
    cout << dp[1][p];
}
