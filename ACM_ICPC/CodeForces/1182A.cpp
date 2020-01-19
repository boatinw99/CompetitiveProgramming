#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
typedef pair<ll,ll> pll ; 
#define fi first
#define se second
const ll INF = 1e18 ; 
const int N = 1e5+9 , mod = 1e9+7 , inf = 1e9 ;
ll dp[N]; 
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ; 
    cin >> n ;
    dp[0]=1 ;  
    for(int i=2;i<=n;i++)
    {
        if(i>=2)
        {
            dp[i]+=dp[i-2]*2;
        }
    }
    cout << dp[n] << '\n' ;
    return 0 ;
}