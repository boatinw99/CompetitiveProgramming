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
const int M = 1e5+9;
const int SQ = sqrt(M)+2;
// const int SQ = 2;
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

int arr[N]; 
int n;
// <jump to, how many times>
bool out[N];
pii jump[N]; 


int getblock(int idx) {
    return idx/SQ ;
}
int getleft(int bl) {
    return bl*SQ ; 
}
int getright(int bl) {
    return (bl+1)*SQ-1;
}

pii query(int idx) {
    int ans = 0 ; 
    while(1) {
        ans += jump[idx].se ; 
        if(out[idx] == 1) {
            idx = jump[idx].fi ; 
            break;
        }
        // cout << "test" << ans << " " << idx << '\n' ;
        idx = jump[idx].fi ; 
    }
    return mp(idx,ans) ; 
}

void update(int idx, int val) {
    int bl = getblock(idx);
    int l = getleft(bl);
    int r = getright(bl);
    arr[idx]=val;
    while(idx>=l) {
        if(idx+arr[idx]>=n) {
            jump[idx]=mp(idx,1);
            out[idx]=1;
        }
        else if(idx+arr[idx] > r) {
            jump[idx] = mp(idx+arr[idx],1);
            out[idx]=0;
        }
        else {
            out[idx] = out[idx+arr[idx]];
            jump[idx] = pii(jump[idx+arr[idx]]);
            jump[idx].se++;
        }
        // cout << "jump " << jump[idx].fi << " " << jump[idx].se << '\n' ;
        idx--;
    }
}

void preprocess() {
    update(n-1,arr[n-1]);
    int bl = getblock(n-1);
    for(int i=0;i<bl;i++) {
        int r = getright(i);
        update(r,arr[r]);
    }
}

void init() {
    // gen_hashprime();
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    srand(chrono::steady_clock::now().time_since_epoch().count());
    ios::sync_with_stdio(false),cin.tie(0);
    init();

    int m ; 
    cin >> n >> m ; 
    for(int i=0;i<n;i++) {
        cin >> arr[i] ; 
    }
    preprocess();
    while(m--) {
        int q ;
        cin >> q ;
        if(q==1) {
            int idx ;
            cin >> idx ; 
            idx--;
            pii ret = query(idx) ; 
            cout << ret.fi+1 << " " << ret.se << '\n' ;
        }
        else { 
            int idx, val ; 
            cin >> idx >> val ; 
            idx--;
            update(idx,val);
        }
    }



    return 0 ;
}
