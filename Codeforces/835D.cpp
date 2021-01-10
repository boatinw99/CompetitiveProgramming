#include<bits/stdc++.h>
using namespace std ;
const int N = 5009;
typedef long long ll ;
int dp[N][N];
string s="0",d ;
ll qs[N];
main()
{
    int i,j,n ;
    cin >> d ;
    s+=d;
    n=s.length()-1;
    for(j=1;j<=n;j++)
    {
        dp[j][j]=1;
        if(s[j]==s[j-1])dp[j-1][j]=1;
        for(i=1;i<j-1;i++)
        {
            if(s[i]==s[j])
            {
                dp[i][j]=dp[i+1][j-1]+1;
            }
        }
    }
    int x;
    for(j=1;j<=n;j++)
    {
        qs[1]++;
        for(x=1;j-x>=1&&j+x<=n&&s[j-x]==s[j+x];x++)
        {
            qs[dp[j-x][j-1]+1]++;
        }
        if(s[j]==s[j+1])
        {
            qs[2]++;
            for(x=1;j-x>=1&&j+x+1<=n&&s[j-x]==s[j+x+1];x++)
            {
                qs[dp[j-x][j]+1]++;
            }
        }
    }
    for(i=n;i>0;i--)
    {
        qs[i]+=qs[i+1];
    }
    for(i=1;i<=n;i++)
    {
        printf("%I64d ",qs[i]);
    }
}
