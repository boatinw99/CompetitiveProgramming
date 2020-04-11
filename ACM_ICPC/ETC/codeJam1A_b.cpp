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
const int N = 31 , inf = 1e9 , mod = 1e9+7 ; 
int x=1,y=1 ; 
int pas[N][N];
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
    pas[1][1] = 1 ;
    for(int i=2;i<N;i++) {
        // int sum = 0 ;
        for(int j=1;j<=i;j++) {
            pas[i][j] = pas[i-1][j]+pas[i-1][j-1];
            // sum+=pas[i][j];
        }
    }
}
void solve() {
    // start here
    int n,cnt=0;
    cin >> n ; 
    x = 1 , y = 1 ;
    cout << x << " " << y << '\n' ;  
    n--;
    if(n==0)return ;
    x=2,y=2 ;  
    cout << x << " " << y << '\n' ; 
    n--; 
    if(n==0)return ; 
    while(x<=n) {
        x++;
        n-=x-1; 
        cout << x << " " << y << '\n' ; 
        cnt++;
    }
    y--;
    while(n>0) {
        cout << x << " " << y << '\n' ; 
        x--;
        n--;
        cnt++;
    }
    assert(cnt<=500&&n==0);
}

// 1
// 100000
// 50000000
// 1000000000

int main() {
    srand(chrono::steady_clock::now().time_since_epoch().count());
    ios::sync_with_stdio(false),cin.tie(0);
    init();
    int T ; 
    cin >> T ;
    for(int t=1;t<=T;t++) {
        cout << "Case #" << t << ":" ;  
        cout << '\n' ; 
        solve();
    }
    return 0 ;
}