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

ll p[N];
ll dp[N];
vector<pii> seg ; 
vector<pii> range[N];
map<pii,int> segMap ; 
auto cmp = [](const pii &lhs, const pii &rhs) {
    if(lhs.se!=rhs.se) return lhs.se<rhs.se; 
    else return lhs.fi<rhs.fi;
};
set<pii,decltype(cmp)> s(cmp) ; 
void init(int n,int m) {
    // gen_hashprime();
    seg.clear();
    s.clear();
    for(int i=0;i<=n;i++) {
        range[i].clear();
    }
    for(int i=0;i<=m;i++) {
        dp[i] = INF ;
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
        int n,m ;
        cin >> n >> m ;
        init(n,m);
        for(int i=1;i<=n;i++) {
            cin >> p[i];
        }
        sort(p+1,p+1+n);
        for(int i=1;i<=m;i++) {
            int l,r ;
            cin >> l >> r ;
            seg.push_back(mp(l,r)); 
        }
        vector<int> v;
        sort(seg.begin(),seg.end(),[&](const pii &lhs, const pii &rhs) {
            if(lhs.fi!=rhs.fi) return lhs.fi < rhs.fi;
            else return lhs.se > rhs.se;
        });
        for(auto it:seg) {
            while(!s.empty()) {
                auto lastptr = s.rbegin();
                if(it.se<=lastptr->se) {
                    s.erase(*lastptr);                    
                }
                else break ;
            }
            s.insert(it); 
        }
        //check point in segment 
        m = 0 ;
        for(auto segment:s) {
            auto it = lower_bound(p+1,p+1+n,segment.fi);
            if(it==p+1+n) {
                //right-most
                range[n].pb(segment); 
                segMap[segment]=++m;
            }
            else {
                if(*it<=segment.se) {
                    //do nothing 
                }
                else {
                    int pos = it-p;
                    range[pos-1].pb(segment);
                    segMap[segment]=++m;
                }
            }
        }
        dp[0]=0;
        for(int i=1;i<=n;i++) {
            ll x = p[i];
            ll walkL = INF;
            ll walkBack = INF;
            if(!range[i-1].empty()) {
                for(auto segment:range[i-1]) {
                    int k = segMap[segment];
                    walkL = min(walkL,dp[k-1]+(x-segment.se));
                    walkBack = min(walkBack,dp[k-1]+2ll*(x-segment.se));
                }
            }
            if(!range[i].empty()) {
                int lastIdx = segMap[range[i][0]]-1;
                int k = lastIdx ; 
                for(auto segment:range[i]) {
                    k++;
                    dp[k] = min(dp[k],dp[lastIdx]+segment.fi-x);
                    dp[k] = min(dp[k],walkL+2ll*(segment.fi-x));
                    dp[k] = min(dp[k],walkBack+(segment.fi-x));
                }
            }
            if(!range[i-1].empty()) {
                int k = segMap[range[i-1][range[i-1].size()-1]];
                dp[k] = min(dp[k],walkL);
            }
        } 
        cout << dp[m] << '\n' ; 
    }
    return 0 ;
}
