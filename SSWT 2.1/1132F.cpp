#include<bits/stdc++.h>
using namespace std ;
const int N = 509 ,MAX = 1e9 ;
vector<char> a;
int dp[N][N];
main()
{
    int n,i,j,k ;
    char c ;
    a.emplace_back('0');
    cin >> n ;
    for(i=1;i<=n;i++)
    {
        cin >> c;
        while(!a.empty()&&a.back()==c)a.pop_back();
        a.push_back(c);
    }
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)dp[i][j]=MAX;
    n=a.size()-1;
    for(i=n;i>=1;i--)
    {
        dp[i][i]=1;
        for(j=i+1;j<=n;j++)
        {
            for(k=i;k<=j;k++)
            {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                if(a[i]==a[k])dp[i][j]=min(dp[i][j],dp[i+1][k-1]+dp[k][j]);
            }
        }
    }
    cout << dp[1][n];
}
