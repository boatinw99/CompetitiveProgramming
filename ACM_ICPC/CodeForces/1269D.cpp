#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second 
const ll INF = 1e16 ; 
const int N = 3e5+9 , mod = 1e9+7 ; 
ll dp[N][3] ; 
ll a[N];
ll getmx(int i)
{
    return max({dp[i][0],dp[i][1],dp[i][2]});
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ; 
    cin >> n ;
    for(int i=1;i<=n;i++)cin>>a[i];
    dp[n+1][1]=-INF;
    for(int i=n;i>=1;i--)
    {
        dp[i][0]=max(a[i]/2+getmx(i+1),(a[i]-1)/2+dp[i+1][1]+1);
        dp[i][1]=(a[i]-1)/2+dp[i+1][0];
        if(a[i]>=1&&a[i]&1)
        {
            dp[i][1]=max(dp[i][1],(a[i]-2)/2+dp[i+1][1]+1);
        }
    }
    cout << getmx(1) << '\n' ;
    return 0 ;
}