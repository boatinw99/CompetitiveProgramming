#include<bits/stdc++.h>
using namespace std ;
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma") 
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

typedef unsigned long long ull ;
typedef long long ll ; 
typedef double db ; 
typedef pair<int,int> pii ; 
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
const int N = 1e5+9 , inf = 1e9 ; 
const int mod = 1e9+7 ;///998244353

const int lg = 20;
int arr[N];
pii tab[N][lg];

// rolling hash
// puu hsh[N],pwhsh[N];
// ull PRIME1,PRIME2; 
// int str[N];
// void updatehash(int x) {
//     hsh[x] = {(hsh[x-1].fi*PRIME1+str[x])%MOD1,(hsh[x-1].se*PRIME2+str[x])%MOD2};
// }
// puu gethash(int l,int r) {
//     int len = r-l+1 ; 
//     return make_pair((hsh[r].fi - hsh[l-1].fi*pwhsh[len].fi+MMOD1)%MOD1,(hsh[r].se-hsh[l-1].se*pwhsh[len].se+MMOD2)%MOD2); 
// }
// void gen_hashprime() {
//     PRIME1 = rand() + rand() ;
//     PRIME2 = rand() + rand() ;
//     pwhsh[0] = make_pair(1,1);
//     for(int i=1;i<N;i++) {
//         pwhsh[i] = make_pair((pwhsh[i-1].fi*PRIME1)%MOD1,(pwhsh[i-1].se*PRIME2)%MOD2);
//     }
// }
// ///end rolling hash

// void add(ll &a,ll b) {
//     a+=b;
//     a%=mod ;
// }
// ll my_rand() {
//     ll a = rand();
//     ll b = rand();
//     return a*(1ll*RAND_MAX+1)+b ; 
// }
// void init() {
//     // gen_hashprime();
// }
pii getmax(int l, int r) {
    int len = r-l+1;
    int j = log2(len);
    return max(tab[l][j],tab[r-(1<<j)+1][j]);
}
ll dp[N];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    srand(chrono::steady_clock::now().time_since_epoch().count());
    ios::sync_with_stdio(false),cin.tie(0);
    // init();
    int n ; 
    cin >> n ; 
    for(int i=1;i<n;i++) { 
        cin >> arr[i];
        tab[i][0]=mp(arr[i],i);
    }
    tab[n][0] = mp(n,n) ; 
    for(int j=1;j<lg;j++) {
        for(int i=1;i+(1<<j)-1<=n;i++) {
            tab[i][j] = max(tab[i][j-1],tab[i+(1<<(j-1))][j-1]);
        }
    }
    ll sum = 0 ;
    for(int i=n-1;i>=1;i--) {
        int r = arr[i];
        pii mx = getmax(i+1,r);
        int inter = mx.se ; 
        int redun = r-inter; 
        dp[i] = r-i + dp[inter] - redun + (n-r); 
        sum += dp[i];
        // cout << inter << " " << dp[i] << '\n' ; 
    }
    cout << sum << '\n' ;
    return 0 ;
}
