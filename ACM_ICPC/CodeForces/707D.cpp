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
const int mod = 1e9+7 ;///998244353
const int N = 1e3+9 , Q = 1e5+9 ,inf = 1e9 ; 
int arr[N][N];
pair<int,pii> query[Q] ; 
int val[N],states[N],ans[Q];
bool vst[Q];
vector<int> g[Q];
int n,m,q ; 
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
ll gen_hashprime() {
    PRIME1 = rand() + rand() ;
    PRIME2 = rand() + rand() ;
    pwhsh[0] = make_pair(1,1);
    for(int i=1;i<N;i++) {
        pwhsh[i] = make_pair((pwhsh[i-1].fi*PRIME1)%MOD1,(pwhsh[i-1].se*PRIME2)%MOD2);
    }
}
void dfs(int l,int r,int res); 
///end rolling hash

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
void next(int l,int r,int res) {
    assert(ans[l]==0);
    // printf("check %d %d\n",l,r,res);
    ans[l] = res;
    trav(it,g[l]) {
        dfs(it,r,res);
    }
    if(l<r&&!vst[l+1]&&query[l+1].fi!=4) {
        dfs(l+1,r,res);      
    }
}
void dfs(int l,int r,int res) {
    vst[l]++;
    int typ = query[l].fi ;
    if(typ==1) {
        int x = query[l].se.fi ; 
        int y = query[r].se.se ;
        if(states[x]==0&&arr[x][y]==0) {
            arr[x][y]=1; 
            val[x]++;
            assert(val[x]<=m&&val[x]>=0);
            next(l,r,res+1);
            assert(arr[x][y]==1);
            val[x]--;
            arr[x][y]=0;
        } 
        else if(states[x]==1&&arr[x][y]==1) {
            arr[x][y]=0;
            val[x]--;
            assert(val[x]<=m&&val[x]>=0);
            next(l,r,res+1);
            assert(arr[x][y]==0);
            val[x]++;
            arr[x][y]=1;
        }
        else next(l,r,res);
    }
    else if(typ==2) {
        int x = query[l].se.fi ;
        int y = query[l].se.se ;  
        if(states[x]==0&&arr[x][y]==1) {
            arr[x][y] = 0 ;
            val[x]--;
            assert(val[x]<=m&&val[x]>=0);
            next(l,r,res-1);
            assert(arr[x][y]==0);
            val[x]++;
            arr[x][y] = 1 ;
        }
        else if(states[x]==1&&arr[x][y]==0) {
            arr[x][y] = 1 ;
            val[x]++;
            assert(val[x]<=m&&val[x]>=0);
            next(l,r,res-1);
            assert(arr[x][y]==1);
            val[x]--;
            arr[x][y]=0;
        }
        else next(l,r,res);
    }
    else if(typ==3) {
        int x = query[l].se.fi ; 
        states[x]^=1;
        int dif ;
        if(states[x]==1) {
            dif = m-2*val[x];
            assert(val[x]<=m&&val[x]>=0);
            next(l,r,res+dif);
        }
        else {
            dif = -m+2*val[x];
            assert(val[x]<=m&&val[x]>=0);
            next(l,r,res+dif);
        }
        states[x]^=1;
    }
    else {
        next(l,r,res);
    }
}
int main() {
    srand(chrono::steady_clock::now().time_since_epoch().count());
    ios::sync_with_stdio(false),cin.tie(0);
    init();
    cin >> n >> m >> q ;
    for(int i=1;i<=q;i++) {
        int typ ; 
        cin >> typ ; 
        if(typ==1) {
            int x,y ; 
            cin >> x >> y ; 
            query[i] = mp(1,mp(x,y));
        }
        else if(typ==2) {
            int x,y ; 
            cin >> x >> y ; 
            query[i] = mp(2,mp(x,y));
        }
        else if(typ==3) {
            int x ; 
            cin >> x; 
            query[i] = mp(3,mp(x,0));
        }
        else {
            int x ; 
            cin >> x ; 
            g[x].pb(i);
            query[i] = mp(4,mp(x,0));
        }
    }
    dfs(0,q,0);
    for(int i=1;i<=q;i++) {
        assert(vst[i]==1);
        assert(ans[i]>=0);
        cout << ans[i] << '\n' ;
    }
    return 0 ;
}
