#include<bits/stdc++.h>
using namespace std ;
const int N = 5e3+9 ;
int dp[N][N];
bool pld[N][N];
string s ;
main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int i,j,T ;
    cin >> s ;
    int sz=s.size();
    for(i=sz;i>=1;i--)
    {
        dp[i][i]=1;
        for(j=i+1;j<=sz;j++)
        {
            dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
            pld[i][j]=1;
            if(s[i-1]==s[j-1]&&pld[i+1][j-1]==0)pld[i][j]=0,dp[i][j]++;
        }
    }
    cin >> T ;
    while(T--)
    {
        cin >> i >> j ;
        cout << dp[i][j] << '\n' ;
    }
}
