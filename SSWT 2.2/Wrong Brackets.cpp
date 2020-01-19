#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 39 ;
ll comb[N<<1][N<<1],dp[N<<1][N<<1];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    ll k ;
    cin >> n >> k ;
    /// n,k = n-1,k-1 + n-1,k;
    comb[0][0]=1;
    for(int i=1;i<2*N;i++)
    {
        comb[i][0]=1;
        for(int j=1;j<=i;j++)comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
    }
    for(int i=2*n-2;i>=0;i--)
    {
        if(i%2==0)dp[i][0]=dp[i+1][1]+comb[2*n-i-1][(2*n-i)/2];
        for(int j=1;j<=i;j++)dp[i][j]=dp[i+1][j+1]+dp[i+1][j-1];
    }
    int sum = 0 , l = n , r = n , i ;
    for(i=1;i<=2*n;i++)
    {
        int cur = 0 ;/// ( , )
        if(dp[i][sum+1]>=k)cur = 1;
        else cur = -1,k-=dp[i][sum+1];
        sum+=cur;
        l-=(cur==1);
        r-=(cur==-1);
        cout << (cur==1?"(":")") ;
        if(sum<0)break;
    }
    for(i++;i<=2*n;i++)
    {
        int cur = 0 ;
        if(comb[2*n-i][l-1]>=k)cur = 1 ;
        else cur = -1,k-=comb[2*n-i][l-1];
        l-=(cur==1);
        r-=(cur==-1);
        cout << (cur==1?"(":")");
        if(l==0||r==0)break;
    }
    while(l)cout << "(",l--;
    while(r)cout << ")",r--;
    return 0 ;
}
