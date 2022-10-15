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

const int sq = sqrt(N)+2;
const int K = 3e6+9;
// const int sq = 2;
int arr[N],pref[N];
vector<pair<pii,int>> query;
int cnt[K];
ll ans[N];
ll sum = 0 ; 

int k ; 

void addl(int idx) {
    sum+=cnt[k^pref[idx-1]];
    cnt[pref[idx-1]]++;
}
void addr(int idx) {
    sum+=cnt[k^pref[idx]];
    cnt[pref[idx]]++; 
}
void removel(int idx) {
    cnt[pref[idx-1]]--;
    sum-=cnt[k^pref[idx-1]];
}
void remover(int idx) {
    cnt[pref[idx]]--;
    sum-=cnt[k^pref[idx]];
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    srand(chrono::steady_clock::now().time_since_epoch().count());
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m ;
    cin >> n >> m >> k ; 
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
        pref[i] = pref[i-1]^arr[i];
    }
    // for(int i=n;i>=1;i--) {
    //     suff[i] = arr[i]^suff[i+1];
    // }
    for(int i=1;i<=m;i++) {
        int l,r;
        cin >> l >> r ; 
        query.pb(mp(mp(l,r),i));
    } 
    sort(query.begin(),query.end(), [&](const pair<pii,int> lhs, const pair<pii,int> rhs){
        if(lhs.fi.fi/sq == rhs.fi.fi/sq) {
            return lhs.fi.se < rhs.fi.se ;
        }
        else { 
            return lhs.fi.fi/sq < rhs.fi.fi/sq ; 
        }
    });
    int curl=1,curr = 1 ;
    addl(1);
    addr(1);
    for(auto q:query) {
        int l = q.fi.fi ; 
        int r = q.fi.se ; 
        assert(l>=1 && l<=n && l<=r && r<=n);
        while(l<curl) {
            curl--;
            addl(curl);
        }
        while(curr<r) {
            curr++;
            addr(curr);
        }
        while(curl<l) {
            removel(curl);
            curl++;
        }
        while(r<curr) {
            remover(curr);
            curr--;
        }
        ans[q.se] = sum ; 
    }
    for(int i=1;i<=m;i++){
        cout << ans[i] << '\n' ; 
    }
    return 0 ;
}
