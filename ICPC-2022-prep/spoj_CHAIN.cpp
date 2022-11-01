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
const int N = 5e4+9 , inf = 1e9 ; 
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

int par[N],sz[N],col[N];
vector<pii> g[N];

int find_par(int u) {
    return (u==par[u])?(u):(par[u]=find_par(par[u]));
}
void dfs(int u,int v) {
    // assign color before entering node 
    for(auto it:g[u]) {
        if(it.fi!=v) {
            col[it.fi] = (col[u]+it.se+3)%3;
            dfs(it.fi,u);
        }
    }
}
void union_find(int u,int v, int val) {
    if(find_par(u)==find_par(v));
    else {
        g[u].pb(mp(v,val));
        g[v].pb(mp(u,-val));
        if(sz[find_par(u)]<sz[find_par(v)]) {
            col[u]=(col[v]-val+3)%3;
            swap(u,v);
        }
        else {
            col[v] = (col[u]+val)%3;
        }
        int pu = find_par(u);
        int pv = find_par(v);
        sz[pu]+=sz[pv];
        par[pv]=pu;
        dfs(v,u);    
    }
}
void init(int n) {
    // gen_hashprime();
    for(int i=1;i<=n;i++) {
        par[i]=i;
        sz[i]=1;
        col[i]=0;
        g[i].clear();
    }
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
        int n,q ; 
        cin >> n >> q ; 
        init(n);
        int ans = 0 ;
        for(int i=1;i<=q;i++) {
            int type,u,v ; 
            cin >> type >> u >> v ; 
            // cout << ans << '\n' ; 
            if(u>n || v>n) {
                ans++;
                continue ; 
            }
            if(type==1) {
                if(find_par(u)==find_par(v)) {
                    if(col[u]==col[v]);
                    else ans++;
                }
                else {
                    union_find(u,v,0);
                }
            }
            else { 
                if(find_par(u)==find_par(v)) {
                    if((col[u]+1)%3 == col[v]) {
                        
                    }
                    else {
                        ans++;
                    }
                }
                else { 
                    union_find(u,v,1);
                }
            }
        }
        cout << ans << '\n' ; 
    }
    return 0 ;
}
