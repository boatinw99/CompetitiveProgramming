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
const int N = 1e5+9 , inf = 1e9 , mod = 1e9+7 ; 
map<char,int> num;
map<char,int> tt ;   
vector<char> V ; 
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
    num.clear();
    tt.clear();
    V.clear();
}
void solve() {
    // start here 
    init();
    int U ; /// digit 
    cin >> U ;
    int times = 10000 ; 
    for(int i=1;i<=times;i++) {
        ll mi ; 
        string s ; 
        cin >> mi >> s ; 
        for(int i=0;i<s.size();i++) {
            tt[s[i]]++;
        }
        num[s[0]]++;
    }
    trav(it,tt) {
        if(num[it.fi]==0) {
            cout << it.fi ;
        }
        else V.emplace_back(it.fi);
    }
    sort(V.begin(),V.end(),[&](char a, char b) {
        return num[a]>num[b];
    });
    for(int i=0;i<V.size();i++) {
        cout << V[i] ; 
    }
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