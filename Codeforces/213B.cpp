#include<bits/stdc++.h>
using namespace std ;
typedef unsigned long long ull ;
typedef long long ll ; 
typedef double db ; 
typedef pair<ull,ull> puu ; 
typedef pair<ll,ll> pll ;
typedef vector<int> vi ; 
typedef vector<ll> vl ;
#define mid (l+r>>1)
#define fi first
#define se second 
#define trav(it,x) for(auto&it:x) 
#define mp make_pair
#define sz(x) int()x.size()
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define up upper_bound
const ull MOD1 = 1e9+7 , MOD2 = 1e9+9 , MMOD1 = MOD1*MOD1 , MMOD2 = MOD2*MOD2; 
const ll INF = 1e18 ; 
const double pi = 3.14159265358979 ; 
const int N = 1e2+9 , inf = 1e9 , mod = 1e9+7 ; 
ll dp[12][N],comb[N][N],tmp[N][N];
int cnt[N];
void add(ll &a,ll b) {
    a+=b;
    a%=mod ;
}
ll my_rand() {
    ll a = rand();
    ll b = rand();
    return a*(RAND_MAX+1)+b ; 
}
void init() {
    //// comb add element with space len  
    for(int x=0;x<N;x++) {
        memset(tmp,0,sizeof tmp);
        tmp[0][0] = 1 ;
        for(int i=1;i<N;i++) {
            ll sum = 0 ; 
            for(int k=0;k<=x;k++) {
                add(sum,tmp[i-1][k]);
                add(tmp[i][k],sum);
            }
            add(comb[x][i],tmp[i][x]); 
        }
    }
    // printf("check %lld %lld \n",comb[2][1],comb[2][2]);
}
int main() {
    srand(chrono::steady_clock::now().time_since_epoch().count());
    ios::sync_with_stdio(false),cin.tie(0);
    int n ; 
    cin >> n ; 
    for(int i=0;i<=9;i++) {
        cin >> cnt[i] ; 
    }
    init();
    dp[10][0] = 1 ; 
    for(int i=9;i>0;i--) {
        for(int x=cnt[i];x<=n;x++) {
            for(int j=0;j+x<=n;j++) {
                add(dp[i][j+x],dp[i+1][j]*comb[x][j+1]%mod);
                // printf("check dp[i=%d] %d %d || %lld %lld\n",i,j,x,dp[i+1][j],comb[x][j]);
            }
        }
    }
    for(int x=cnt[0];x<=n;x++) {
        for(int j=0;j+x<=n;j++) {
            add(dp[0][j+x],dp[1][j]*comb[x][j]%mod);
        }
    }
    ll ans = 0 ; 
    for(int i=0;i<=n;i++) {
        add(ans,dp[0][i]);
        // printf("checkans %lld \n",dp[0][i]);
    }
    cout << ans << '\n' ; 
    return 0 ;
}