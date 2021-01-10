#include<bits/stdc++.h>
using namespace std ;
const int N = 1e6+9 , inf = 1e9 ; 
int arr[N];
int dp[N][3][3];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m ;
    cin >> n >> m ;
    for(int i=1,u;i<=n;i++)
    {
        cin >> u ;
        arr[u]++;
    }
    for(int k=0;k<=m;k++)for(int i=0;i<3;i++)for(int j=0;j<3;j++)dp[k][i][j]=-inf ; 
    dp[0][0][0]=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                for(int d=0;d<3;d++)
                {
                    /// d -> itself in i idx 
                    if(j+k+d<=arr[i]&&k+d<=arr[i+1])
                    {
                        dp[i][k][d]=max(dp[i][k][d],dp[i-1][j][k]+(arr[i]-j-k-d)/3+d);
                    }
                }
            }
        }
    }
    //printf("check %d\n",dp[3][0][2]);
    int ans = 0 ;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)ans=max(ans,dp[m][i][j]);
    }
    cout << ans << '\n' ; 
    return 0 ;
}