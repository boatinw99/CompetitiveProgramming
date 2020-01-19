#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 2e3+9 , mod = 1e9+7 ;
int arr[N];
bool occured[N];
ll dp[N][N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        cin >> arr[i];
        if(arr[i]>0)
        {
            occured[arr[i]]++;
        }
    }
    int num = 0 ;
    dp[0][0] = 1 ;
    /// dp[i][j] -> index i and have j duplicates
    for(int i=1;i<=n;i++)
    {
        if(arr[i]>0)
        {
            for(int j=0;j<=n;j++)dp[i][j]=dp[i-1][j];
            continue ;
        }
        if(occured[i])
        {
            for(int j=0;j<=n;j++)dp[i][j]=dp[i-1][j];
            for(int j=0;j<=n;j++)
            {
                ///swap to decrese 1 duplicates
                if(j)
                {
                    dp[i][j-1]+=dp[i][j]*j%mod;
                    dp[i][j-1]%=mod ;
                }
                 ///swap and not decrese 
                if(num-j>0)dp[i][j]=(dp[i][j]+dp[i][j]*(num-j))%mod;
            }
        }
        else 
        {
            for(int j=1;j<=n;j++)dp[i][j]=dp[i-1][j-1];
            for(int j=1;j<=n;j++)
            {
                //swap to decrese 2 
                if(j>=2)
                {
                    dp[i][j-2]+=dp[i][j]*(j-1)%mod ;
                    dp[i][j-2]%=mod ;
                }
                //swap to decrese 1 
                if(num-j+1>0)
                {
                    dp[i][j-1]+=dp[i][j]*(num-j+1)%mod;
                    dp[i][j-1]%=mod ;
                }
            }
        }
        num++; 
    }
    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            printf("check %d %d -> %lld \n",i,j,dp[i][j]);
        }
    }*/
    cout << dp[n][0] << '\n' ;
    return 0 ;
}
