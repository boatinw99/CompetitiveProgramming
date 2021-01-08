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
const int N = 1e4+9 , inf = 1e9 , mod = 1e9+7 ; 
int n,d ; 
ll arr[N];
vector<pll> V ; 
ll my_rand() {
    ll a = rand();
    ll b = rand();
    return a*(RAND_MAX+1)+b ; 
}
void add(ll &a,ll b) {
    a+=b;
    a%=mod ;
}
void init() {
    ///clear the last test mem 
    V.clear();
}
int cnt(ll x) {
    int num = 0 ;
    for(int i=1;i<=n;i++) {
        if(arr[i]==x) {
            num++;
        }
        else if(arr[i]>x) {
            if(arr[i]%x==0) {
                V.pb({arr[i]/x,arr[i]/x-1});
            }
            else V.pb({arr[i]/x,arr[i]/x});
        }
    }
    if(num>=d) return 0 ; 
    for(int i=1;i<=n;i++) {
        if(num>=d-1&&arr[i]>x) return 1 ;
        if(num>=d-2&&arr[i]==x*2) return 1 ;
    }
    return 2 ;
    // int ret = 0 ; 
    // sort(V.begin(),V.end(),[&](pll a,pll b){
    //     if(a.fi==a.se+1 && b.fi == b.se+1) {
    //         return a.fi < b.fi ; 
    //     }
    //     else if(a.fi==a.se+1 || b.fi == b.se+1) {
    //         return (a.fi==a.se+1) ; 
    //     }
    //     return a.fi < b.fi ; 
    // });
    // trav(it,V) {
    //     pll tmp = it ;
    //     // printf("checkkk %lld %lld \n",tmp.fi,tmp.se);
    //     while(num<d) {
    //         if(tmp.se>0) {
    //             tmp.fi-- ;
    //             tmp.se--;
    //             num++;
    //             ret++;
    //         }
    //         if(tmp.se==0) {
    //             num+=tmp.fi ;
    //             break ; 
    //         }
    //     }
    // }
    // // printf("\n");
    // if(num>=d) return ret ; 
    // else return inf ;  
}
void solve() {
    // start here 
    init();
    cin >> n >> d ; 
    for(int i=1;i<=n;i++) {
        cin >> arr[i] ; 
    }
    sort(arr+1,arr+1+n);
    int ans = d-1 ; 
    for(int i=1;i<=n;i++) {
        ans = min(ans,cnt(arr[i]));
    }
    cout << ans ; 
}
int main() {
    srand(chrono::steady_clock::now().time_since_epoch().count());
    ios::sync_with_stdio(false),cin.tie(0);
    int T ; 
    cin >> T ;
    for(int t=1;t<=T;t++) {
        cout << "Case #" << t << ": " ;  
        solve();
        cout << '\n' ; 
    }
    return 0 ;
}

// 1
// 2 3
// 8 4