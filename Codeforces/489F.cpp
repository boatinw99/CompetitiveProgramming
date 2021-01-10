#include<bits/stdc++.h>
using namespace std ;
const int N = 509 ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
int n,m,mod,nw = 0 ;
int dp[N][N];
char s[N][N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m >> mod ; 
    int cnt0=n,cnt1=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> s[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        int cnt = 0 ;
        for(int j=1;j<=m;j++)
        {
            cnt+=s[j][i]-'0';
        }
        if(cnt==1)cnt0--,cnt1++;
        if(cnt==2)cnt0--;
    }
    dp[cnt0][cnt1]++;
    for(int j=n;j>=0;j--)
    {
        for(int k=n;k>=0;k--)
        {
            if(j>=1&&k>=1)
            {
                dp[j-1][k]=(dp[j-1][k]+dp[j][k]*1ll*j*k%mod)%mod;
            }
            if(k>=2)
            {
            //    printf("check %d %d %d || %d \n",i,j,k,dp[nw^1][j][k]);
                dp[j][k-2]=(dp[j][k-2]+dp[j][k]*1ll*(k*(k-1)/2)%mod)%mod;
            }
            if(j>=2)
            {
                dp[j-2][k+2]=(dp[j-2][k+2]+dp[j][k]*1ll*(j*(j-1)/2)%mod)%mod;
            }
        }
    }
    cout << dp[0][0] << '\n' ;
    return 0 ;
}