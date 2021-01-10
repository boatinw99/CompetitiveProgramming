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
const int N = 1e5+9 , inf = 1e9 ; 
const int mod = 1e9+7 ;///998244353


// rolling hash
puu hsh[N],pwhsh[N];
ull PRIME1,PRIME2; 
int str[N];
void updatehash(int x) {
    hsh[x] = {(hsh[x-1].fi*PRIME1+str[x])%MOD1,(hsh[x-1].se*PRIME2+str[x])%MOD2};
}
puu gethash(int l,int r) {
    int len = r-l+1 ; 
    return make_pair((hsh[r].fi - hsh[l-1].fi*pwhsh[len].fi+MMOD1)%MOD1,(hsh[r].se-hsh[l-1].se*pwhsh[len].se+MMOD2)%MOD2); 
}
ll gen_hashprime() {
    PRIME1 = rand() + rand() ;
    PRIME2 = rand() + rand() ;
    pwhsh[0] = make_pair(1,1);
    for(int i=1;i<N;i++) {
        pwhsh[i] = make_pair((pwhsh[i-1].fi*PRIME1)%MOD1,(pwhsh[i-1].se*PRIME2)%MOD2);
    }
}
///end rolling hash
ll powap(ll a,ll p) {
    if(p==0)return 1 ;
    ll ret = powap(a,p>>1);
    ret = ret*ret %mod ; 
    if(p&1) {
        ret = ret*a %mod ; 
    }
    return ret ; 
}
void add(ll &a,ll b) {
    a+=b+mod;
    a%=mod ;
}
ll mul(ll a,ll b) {
    return (a%mod)*(b%mod)%mod ;
}
ll sum(ll x) {
    ll ret ; 
    if(x%2==0) {
        ret = (x/2)%mod*((x+1)%mod)%mod ; 
    }
    else {
        ret = (x+1)/2%mod*(x%mod)%mod;
    }
    return ret ; 
}
ll my_rand() {
    ll a = rand();
    ll b = rand();
    return a*(RAND_MAX+1)+b ; 
}
void init() {
    // gen_hashprime();
}
int main() {
    srand(chrono::steady_clock::now().time_since_epoch().count());
    ios::sync_with_stdio(false),cin.tie(0);
    ll n,m ; 
    init();
    cin >> n >> m ; 
    ll st = sqrt(n); 
    ll ans = mul(n,m);
    m = min(m,n);
    ll sq = n/st;
    for(int i=1;i<=min(sq,m);i++) {
        add(ans,-mul((n/i),i));
    }
    ll prev = sq ; 
    for(int x=st-1;x>=1&&prev<=m;x--) {
        ll nw = n/x ;
        ll tmp = nw ;
        nw = min(m,nw);
        ll sump = (sum(nw)-sum(prev)+mod)%mod;
        // printf("check %lld %lld %d sump = %lld \n",nw,prev,x,sump);
        add(ans,-mul(sump,x));
        prev = tmp ; 
    }
    cout << ans << '\n' ;
    return 0 ;
}