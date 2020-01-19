/**
 *    author : boatinw99
 *    created : 30.04.2019 18:00:00
 *
**/
#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const ll inf = 1e18 ;
const int N = 5009 ;
string s ;
ll dp[N][N];
void add(ll &a,ll b)
{
    a+=b;
    if(a>inf)a=inf;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    ll k ;
    cin >> s >> k ;
    s="#"+s;
    int n = s.size()-1;
    while(n&1);
    dp[n+1][0]=1;
    for(int i=n;i>=1;i--)
    {
        if(s[i]!='(')for(int j=1;j<=n;j++)add(dp[i][j],dp[i+1][j-1]);
        if(s[i]!=')')for(int j=n;j>=0;j--)add(dp[i][j],dp[i+1][j+1]);
    }
    int cst = 0 ;
    for(int i=1;i<=n;i++)
    {
        int add = 0 ;
        if(s[i]=='(')add=1;
        else if(s[i]==')')
        {
            add=-1;
        }
        else if(dp[i+1][cst+1]>=k)add=1;
        else
        {
            add=-1;
            k-=dp[i+1][cst+1];
        }
        cst+=add;
        cout << (add==1?"(":")");
    }
    return 0 ;
}
