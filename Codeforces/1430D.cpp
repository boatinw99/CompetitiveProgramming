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
const int N = 1e5+9 , inf = 1e9 ; 
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
vector<int> v ; 
set<int> s;  
void init() {
    // gen_hashprime();
    v.clear();
    s.clear();
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    srand(chrono::steady_clock::now().time_since_epoch().count());
    ios::sync_with_stdio(false),cin.tie(0);
    int t;  
    cin >> t ; 
    while(t--) {
        init();
        int n ; 
        cin >> n ;
        char c ; 
        cin >> c;  
        int x = c-'0'; 
        int cnt = 1 ; 
        for(int i=2;i<=n;i++) {
            cin >> c ; 
            assert(c=='0'||c=='1');
            if(c-'0'==x){
                cnt++;
            }
            else v.push_back(cnt),cnt=1,x^=1;
        }
        v.push_back(cnt);
        for(int i=0;i<v.size();i++) {
            if(v[i]>1)s.insert(i);
            assert(v[i]>=1);
        }
        int ans = 0 ;
        for(int i=0;i<v.size();i++) {
            if(!s.empty()) {
                v[*s.begin()]--;
                if(v[*s.begin()]==1) {
                    s.erase(*s.begin());
                }
            }
            else i++;
            if(s.find(i)!=s.end())s.erase(i);
            ans++;
        }
        cout << ans << '\n' ; 
    }
    return 0 ;
}