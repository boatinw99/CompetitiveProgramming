#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const ll INF = 1e18 ;
const int N = 5e3+9 , inf = 2e9 ; 
vector<int> cc ; 
int arr[N];
ll dp[2][N]; ///dp idx = i , mx value = cc[j]
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        cin >> arr[i] ;
        cc.push_back(arr[i]);
    }
    cc.push_back(-inf);
    sort(cc.begin(),cc.end());
    for(int i=0;i<2;i++)for(int j=0;j<=n;j++)dp[i][j]=INF; 
    for(int i=0;i<=n;i++)dp[0][i]=0;
    for(int i=1;i<=n;i++)
    {
        int idx = i&1 ; 
        for(int j=1;j<=n;j++)
        {
            dp[idx][j]=min(dp[idx][j-1],dp[idx^1][j]+abs(arr[i]-cc[j]));
        }
        for(int j=0;j<=n;j++)dp[idx^1][j]=INF;
    }
    ll ans = INF ; 
    for(int i=1;i<=n;i++)ans=min(ans,dp[n&1][i]);
    cout << ans << '\n' ;
    return 0 ;
}