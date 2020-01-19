#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 2e5+9 ;
const ll inf = 1e10 ;
ll dp[N][3];///0 1 2
int a[N];
char b[N];
string s ;
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    cin >> n ;
    for(int i=1;i<=n+n-1;i++)
    {
        char c ;
        if(i&1)
        {
            cin >> a[i/2+1];
        }
        else
        {
            cin >> c ;
            b[i/2]=c;
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=2;j++)dp[i][j]=-inf;
    }
    dp[1][0]=a[1];
    for(int i=2;i<=n;i++)
    {
        if(b[i-1]=='+')
        {
            dp[i][0]=dp[i-1][0]+a[i];
            dp[i][1]=max(dp[i-1][1]-a[i],dp[i-1][2]+a[i]);
            dp[i][2]=dp[i-1][2]+a[i];
        }
        else if(b[i-1]=='-')
        {
            dp[i][0]=max(dp[i-1][0]-a[i],dp[i-1][1]+a[i]);
            dp[i][1]=max(dp[i-1][0]-a[i],dp[i-1][1]+a[i]);
            dp[i][2]=max(dp[i-1][1]+a[i],dp[i-1][2]-a[i]);
        }
        else while(1);
        ///while(a[i]<=0);
        //printf("aa %lld %lld %lld \n",dp[i][0],dp[i][1],dp[i][2]);
    }
    cout << dp[n][0];
    return 0 ;
}
