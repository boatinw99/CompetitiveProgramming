#include<bits/stdc++.h>
using namespace std ;
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
const int N = 1e3+9 , inf = 1e9 ; 
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
tuple<int,int,int> arr[N];
int main() {
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    srand(chrono::steady_clock::now().time_since_epoch().count());
    ios::sync_with_stdio(false),cin.tie(0);
    init();
    int n ; 
    for(int i=0;i<N;i++) {
        arr[i] = make_tuple(-1,-1,-1);
    }
    arr[0]=make_tuple(0,0,0);
    cin >> n ;
    for(int i=3;i<N;i++) {
        if(get<0>(arr[i-3])!=-1) {
            arr[i]=make_tuple(1+get<0>(arr[i-3]),get<1>(arr[i-3]),get<2>(arr[i-3]));
        }
    }
    for(int i=5;i<N;i++) {
        if(get<0>(arr[i-5])!=-1) {
            arr[i]=make_tuple(get<0>(arr[i-5]),get<1>(arr[i-5])+1,get<2>(arr[i-5]));
        }
    }
    for(int i=7;i<N;i++) {
        if(get<0>(arr[i-7])!=-1) {
            arr[i]=make_tuple(get<0>(arr[i-7]),get<1>(arr[i-7]),get<2>(arr[i-7])+1);
        }
    }
    while(n--) {
        int x ; 
        cin >> x ;
        if(get<0>(arr[x])!=-1) {
            cout << get<0>(arr[x]) << " " << get<1>(arr[x]) << " " << get<2>(arr[x]) << '\n' ; 
        }
        else cout << "-1" << '\n' ; 
    }
    return 0 ;
}