#include<bits/stdc++.h>
using namespace std ; 
typedef pair<int,int> pii ; 
#define fi first
#define se second 
const int N = 16 ; 
const int inf = 1e9 ; 
double dp[1<<N+1];
pii arr[N]; 
double dist(pii l, pii r) {
    return sqrt((l.fi-r.fi)*(l.fi-r.fi)+(l.se-r.se)*(l.se-r.se));
}

void init() {
    for(int i=0;i<1<<N+1;i++) {
        dp[i]=inf ;     
    }
    dp[0]=0;
}
double solve(int n) {
    for(int mask=0;mask<(1<<n);mask++) {
        for(int j=0;j<n;j++) {
            for(int k=0;k<n;k++) {
                if(mask&(1<<j) && mask&(1<<k) && k!=j) {
                    dp[mask]=min(dp[mask],dp[mask-(1<<j)-(1<<k)]+dist(arr[j],arr[k]));
                    // printf("%d %d %d\n",mask,j,k);
                }
            }
        }
    }
    return dp[(1<<n)-1];
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int n ; 
    int t = 1 ; 
    while(cin >> n) {
        if(n==0)return 0; 
        n<<=1;
        for(int i=0;i<n;i++) {
            init();
            string s ;
            int x,y ; 
            cin >> s >> x >> y ; 
            arr[i]={x,y};
        }
        cout << "Case " << t++ << ": " ; 
        cout << fixed << setprecision(2) << solve(n) << '\n' ; 
    }
    return 0 ; 
}