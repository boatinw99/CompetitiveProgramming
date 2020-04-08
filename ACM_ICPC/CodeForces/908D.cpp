/* 
    implement 15 min 
    dp expected time + math + prob 
*/
#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const ll mod = 1e9+7 ;
const int N = 1e3+9 ; 
ll dp[N][N];
ll pow2(ll a,ll p) {
    if(p==0) {
        return 1 ;
    }
    ll res = pow2(a,p>>1);
    res=res*res%mod ; 
    if(p&1) {
        res = res*a %mod ;
    }
    return res ; 
}
ll divide(ll a,ll b) {
    return a*pow2(b,mod-2)%mod ; 
}
void add(ll &a,ll b) {
    a+=b;
    a%=mod ;
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    ll pa,pb,sa,sb ; 
    int k;
    cin >> k >> pa >> pb ; 
    ll gc = __gcd(pa,pb) ;
    pa/=gc ;
    pb/=gc ; 
    sa = divide(pa,pa+pb);
    sb = divide(pb,pa+pb);
    ll ans = 0 ;
    dp[0][0] = divide(1,sa) ; 
    for(int x=0;x<=k;x++) {
        for(int num=0;num<k;num++) {
            if(x+num>=k) {
                /// cal some ans  
                add(ans,dp[x][num]*(num+x+divide(sa,sb))%mod); 
                // printf("checkans %d %d ||%lld\n",x,num,dp[x][num]);
                continue ; 
            }
            add(dp[x+1][num],dp[x][num]*sa%mod);
            add(dp[x][num+x],dp[x][num]*sb%mod);
            // printf("check %lld %lld\n",dp[x+1][num],dp[x][num+x]);
        }
    }
    cout << ans << '\n' ;
    return 0 ; 
}