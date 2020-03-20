/* 
    DATE 16-03-20 
    START 13.55 
    END 14.??
*/ 
#include<bits/stdc++.h>
using namespace std ;
const int N = 89 , TIMES = 512*20 , INF = 1e9+7 , K = 6 ; 
int n,k ; 
int dist[N][N],clr[N],dp[N][K];
void init() {
    for(int i=2;i<=n;i++) {
        clr[i] = rand()%2 ;
    }
    for(int i=1;i<=n;i++) {
        for(int j=0;j<K;j++) {
            dp[i][j] = INF ; 
        }
    }
    clr[1] = 0 ; 
    dp[1][0] = 0 ;
}
int comp() {
    for(int ti=0;ti<k/2;ti++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(clr[i]==0&&clr[j]==1) {
                    dp[j][ti] = min(dp[j][ti],dp[i][ti]+dist[i][j]);
                }
            }   
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(clr[i]==1&&clr[j]==0) {
                    dp[j][ti+1] = min(dp[j][ti+1],dp[i][ti]+dist[i][j]);
                }
            }   
        }
    }
    return dp[1][k/2];
}
int main() { 
    srand(time(NULL)) ;
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> k ; 
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> dist[i][j];
        }
    }
    int ans = INF ;
    int times = TIMES ; 
    while(times--) {
        init();
        ans = min(ans,comp());
    }
    cout << ans << '\n' ;
    return 0 ; 
}