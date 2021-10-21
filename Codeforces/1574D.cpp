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
void init() {
    // gen_hashprime();
}
int n ;
int sz[N];
vector<int> v[N];
pair<int,vector<int>> ans = {0,vector<int>()}; 

//unordered set should be faster than set 
struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (const int &i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
};
unordered_set<vector<int>,VectorHash> banList;

int getstr(const vector<int> &l) {
    int ret = 0 ;
    for(int i=0;i<n;i++) {
        ret+=v[i+1][l[i]];
    }
    return ret ; 
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    srand(chrono::steady_clock::now().time_since_epoch().count());
    ios::sync_with_stdio(false),cin.tie(0);
    init();
    cin >> n ;
    for(int i=1;i<=n;i++) {
        cin >> sz[i];
        for(int j=1;j<=sz[i];j++) {
            int x ;
            cin >> x ; 
            v[i].eb(x);
        }
    }
    int m ;
    cin >> m ; 
    for(int i=1;i<=m;i++) {
        vector<int> ban ; 
        for(int j=1;j<=n;j++) {
            int x ;
            cin >> x ;
            ban.eb(x-1);
        }
        banList.insert(ban);
    }
    vector<int> tmp ; 
    for(int i=1;i<=n;i++) {
        tmp.eb(sz[i]-1);
    } 
    if(banList.find(tmp)==banList.end()) {
        ans = mp(getstr(tmp),tmp); 
    }
    for(auto it:banList) {
        for(int i=0;i<n;i++) {
            if(it[i]>0) {
                it[i]--;
                if(banList.find(it)==banList.end()) {
                    ans = max(ans,mp(getstr(it),it));
                }
                it[i]++;
            }
        }
    }
    for(auto it:ans.se) {
        cout << it+1 << " " ;
    }
    cout << '\n'; 
    return 0 ;

}
