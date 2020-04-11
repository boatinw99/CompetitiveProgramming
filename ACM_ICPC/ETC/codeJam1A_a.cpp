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
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define up upper_bound
const ull MOD1 = 1e9+7 , MOD2 = 1e9+9 , MMOD1 = MOD1*MOD1 , MMOD2 = MOD2*MOD2; 
const ll INF = 1e18 ; 
const double pi = 3.14159265358979 ; 
const int N = 59 , inf = 1e9 , mod = 1e9+7 ; 
string s[N]; 
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
}
bool match(string s1,string s2) {
    for(int i=0;i<min(sz(s1),sz(s2));i++) {
        if(s1[i]!=s2[i]) {
            return 0 ;
        }
    }
    return 1 ; 
}
void solve() {
    // start here 
    vector<string> V ; 
    init();
    int n ; 
    cin >> n ; 
    for(int i=1;i<=n;i++) {
        cin >> s[i] ; 
    }
    string pref = "" , suf = "" ;
    for(int i=1;i<=n;i++) {
        int l = 0, r = sz(s[i])-1; 
        string tmp1="",tmp2="" ; 
        for(l;l<sz(s[i])&s[i][l]!='*';l++) {
            tmp1+=s[i][l];
        }
        for(r;r>=0&&s[i][r]!='*';r--) {
            tmp2+=s[i][r];
        }
        string addstr = "" ;
        for(l;l<=r;l++) {
            if(s[i][l]!='*') {
                addstr += s[i][l] ;
            }
        }
        if(!match(pref,tmp1)||!match(suf,tmp2)) {
            cout << "*" ;
            return ; 
        }
        // cout << "check " << tmp1 <<  " " <<tmp2 << '\n' ; 
        if(sz(tmp1)>sz(pref)) pref = tmp1  ;
        if(sz(tmp2)>sz(suf)) suf = tmp2  ;
        V.pb(addstr);
    }
    cout << pref ; 
    trav(it,V) {
        cout << it ;
    }
    reverse(all(suf));
    cout << suf ; 
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