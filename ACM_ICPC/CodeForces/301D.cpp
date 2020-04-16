/*

*/
#include<bits/stdc++.h>
using namespace std ;
typedef unsigned long long ull ;
typedef long long ll ; 
typedef double db ; 
typedef pair<ull,ull> puu ;
typedef pair<int,int> pii ; 
typedef pair<ll,ll> pll ;
typedef vector<int> vi ; 
// typedef vector<ll> vl ;
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
#define ub upper_bound
const ull MOD1 = 1e9+7 , MOD2 = 1e9+9 , MMOD1 = MOD1*MOD1 , MMOD2 = MOD2*MOD2; 
const ll INF = 1e18 ; 
const double pi = 3.14159265358979 ; 
const int N = 2e5+9 , inf = 1e9 , BLOCK = sqrt(N)+1 ; 
const int mod = 1e9+7 ;///998244353

vector<pii> Q[N] ; 
vi V[N] ; 
int pos[N],arr[N],f[N];
// pii query[N];
ll ans[N];

void update(int x) {
    for(;x<N;x+=x&-x) {
        f[x]++;
    }
}
int getsum(int x) { 
    int sum = 0 ;
    for(;x;x-=x&-x) {
        sum += f[x];
    }
    return sum ; 
}
void add(ll &a,ll b) {
    a+=b;
    a%=mod ;
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
    init();
    int n,m ;
    cin >> n >> m ; 
    for(int i=1;i<=n;i++) {
        cin >> arr[i] ;
        pos[arr[i]]=i ;
    }
    for(int i=1,x,y ;i<=m;i++) {
        cin >> x >> y ;
        Q[x].eb(y,i);
    }
    for(int i=1;i<N;i++) {
        sort(all(Q[i]));
    }
    for(int i=1;i<=n;i++) {
        for(int j=arr[i];j<=n;j+=arr[i]) {
            int x = i ; 
            int y = pos[j];
            if(y<=x) {
                swap(x,y);
            }
            V[x].eb(y);
        }
    }
    for(int i=n;i>=1;i--) {
        trav(it,V[i]) {
            update(it);
        }
        trav(it,Q[i]) {
            ans[it.se] = getsum(it.fi);
        }
    }
    for(int i=1;i<=m;i++) {
        cout << ans[i] << '\n' ; 
    }
    return 0 ;
}