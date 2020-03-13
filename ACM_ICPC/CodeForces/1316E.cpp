/*
    STARTED_TIME 20:22 DATE 13-3-20 
    FINISHED_TIME 20:50 DATE 13-3-20 
    /// bug +-  
*/
#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
const ll INF = 1e18 ; 
const int N = 1e5+9 , bit = 7 ; 
int n,p,k,dist[N][bit];
ll dp[N][1<<bit];
vector<pii> V ; 
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> p >> k ;
    for(int i=1,sc ;i<=n;i++) { 
        cin >> sc ; 
        V.emplace_back(sc,i) ;
    }
    for(int i=1;i<=n;i++) {
        for(int j=0;j<p;j++) {
            cin >> dist[i][j];
        }
    }
    for(int i=0;i<=n;i++) {
        for(int j=0;j<(1<<bit);j++) {
            dp[i][j] = -INF ; 
        }
    }
    dp[0][0] = 0 ; 
    sort(V.begin(),V.end(),greater<pii>());
    for(int i=1;i<=n;i++) {
        pii indiv = V[i-1] ;  /// person = indiv.se 
        for(int j=0;j<(1<<p);j++) { 
            int num = i-1-__builtin_popcount(j);
            if(num<k) {
                dp[i][j]=max(dp[i][j],dp[i-1][j]+indiv.fi);
            }
            else dp[i][j] = max(dp[i][j],dp[i-1][j]);
            for(int pos=0;pos<p;pos++) {
                if(((1<<pos)&j)==0) { 
                    dp[i][(1<<pos)|j] = max(dp[i][(1<<pos)|j],dp[i-1][j]+dist[indiv.se][pos]);
                }
            }
        }
    }
    cout << dp[n][(1<<p)-1] << '\n' ;
    return 0 ;
}