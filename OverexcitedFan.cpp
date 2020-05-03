#include<bits/stdc++.h>
using namespace std ;
typedef unsigned long long ull ;
typedef long long ll ; 
typedef double db ; 
typedef pair<ull,ull> puu ; 
typedef pair<ll,ll> pll ;
typedef pair<int,int> pii ;
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
const int N = 3e3+9 , inf = 1e9 , mod = 1e9+7 ; 
const int st = 1005;
map<char,pii> dir ; 
queue<pair<pii,int>> q ; 
int dista[N][N] ; 
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
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            dista[i][j] = inf ; 
        }
    }
}
void solve() {
    // start here 
    init();
    string s ; 
    int x,y ; 
    cin >> x >> y >> s ;
    x+=st; 
    y+=st; 
    dir['S'] = mp(0,-1);
    dir['N'] = mp(0,1);
    dir['W'] = mp(-1,0);
    dir['E'] = mp(1,0);
    int ans = inf ; 
    q.push(mp(mp(st,st),0));
    dista[st][st] = 0 ;
    while(!q.empty()) {
        pair<pii,int> p = q.front();
        q.pop();
        if(p.se > 1000) {
            continue ; 
        }
        pii point = p.fi ; 
        trav(it,dir) {
            pii tmp = point ; 
            tmp.fi += it.se.fi ; 
            tmp.se += it.se.se ; 
            if(dista[tmp.fi][tmp.se]==inf) {
                dista[tmp.fi][tmp.se] = p.se+1 ; 
                q.push(mp(tmp,p.se+1));
            }
        }
    }

    for(int i=0;i<s.size();i++) {
        x+=dir[s[i]].fi ;
        y+=dir[s[i]].se ;
        if(dista[x][y]<=i+1) {
            ans = min(ans,i+1);
        }
    }
    if(ans==inf) {
        cout << "IMPOSSIBLE" ; 
    }
    else cout << ans ; 
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