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
const int N = 2e5+9 , inf = 1e9 ; 
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
void gen_hashprime() {
    PRIME1 = rand() + rand() ;
    PRIME2 = rand() + rand() ;
    pwhsh[0] = make_pair(1,1);
    for(int i=1;i<N;i++) {
        pwhsh[i] = make_pair((pwhsh[i-1].fi*PRIME1)%MOD1,(pwhsh[i-1].se*PRIME2)%MOD2);
    }
}
///end rolling hash

void add(ll &a,ll b) {
    a+=b;
    a%=mod ;
}
ll my_rand() {
    ll a = rand();
    ll b = rand();
    return a*(1ll*RAND_MAX+1)+b ; 
}
vector<int> g[N];
set<pii> s;
int par[N];
int d[N];
bool mark[N];
void init(int n) {
    // gen_hashprime();
    s.clear();
    for(int i=0;i<=n;i++) {
        g[i].clear();
        d[i]=0;
        par[i]=0;
        mark[i]=0;
    }
}
void dfs(int u, int v) {
    d[u]=d[v]+1;
    par[u]=v;
    s.insert(mp(d[u],u));
    for(auto it:g[u]) {
        if(it!=v) {
            dfs(it,u);
        }
    }
}
void solve(int n) {
    d[1]=-1;
    dfs(1,1);
    int cntBud = 0 ;
    int L = 0;
    bool haveNonBud = 0;
    while(s.size()!=1) {
        pii x = *s.rbegin();
        int depth = x.fi;
        if(x.fi==1) {
            haveNonBud=1;
            L++;
            s.erase(x);
            mark[x.se]=1;
        } 
        else {
            cntBud++;
            int v = par[x.se];
            for(auto it:g[v]) {
                if(it!=par[v]&&mark[it]==0) {
                    L++;
                    mark[it]=1;
                    s.erase(mp(d[it],it));
                }
            } 
            s.erase(mp(d[v],v));
            mark[v]=1;
        } 

    }
    int ans = L-cntBud; 
    if(haveNonBud==0) { 
        ans=ans+1;
    }
    cout << ans << '\n' ;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    srand(chrono::steady_clock::now().time_since_epoch().count());
    ios::sync_with_stdio(false),cin.tie(0);
    int T ;
    cin >> T ; 
    while(T--) {
        int n ;
        cin >> n ;
        init(n);
        for(int i=1;i<n;i++) {
            int u,v ;
            cin >> u >> v ;
            g[u].eb(v);
            g[v].eb(u);
        }
        solve(n);
    }

    return 0 ;
}
