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
const ll mod = 998244353 ; 
const double pi = 3.14159265358979 ; 
const int N = 1e5+9 , inf = 1e9 ; 
int n,k ; 
void add(ll &a,ll b) {
    a+=b;
    a+=mod ; 
    a%=mod ;
}
void mul(ll &a,ll b) {
    a*=b;
    a+=mod*mod ;
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
ll powap(ll a,ll p) {
    if(p==0)return 1 ;
    ll res = powap(a,p>>1);
    mul(res,res) ;
    if(p&1)mul(res,a);
    return res ; 
}
ll solve(vi v) {
    // printf("solvee\n");
    ll ans = 1 ; 
    for(int i=1;i<v.size()-1;) {
        if(v[i]!=-1) {
            if(v[i-1]==v[i]||v[i]==v[i+1]) {
                return 0 ;
            }
            i++;
            continue ;
        }
        int l = i,r=i;
        while(v[r+1]==-1&&r<v.size()-2) {
            r++;
        } 
        int x = v[l-1],y = v[r+1];
        int num = 0 ;
        int len = r-l+1 ;
        if(x!=-1)num++;
        if(y!=-1)num++;
        if(num==0) {
            mul(ans,k);
            mul(ans,powap(k-1,len-1));
        }
        else if(num==1) {
            mul(ans,k-1);
            mul(ans,powap(k-1,len-1));
        }
        else {
            ll tmp = 0 ; 
            int incl = 1 ;
            if(x==y&&x!=-1)num--; 
            for(int i=len;i>=0;i--) {
                if(i==1) {
                    add(tmp,incl*(k-num));
                    break ; 
                }
                add(tmp,incl*powap(k-1,i));
                incl*=-1;
            } 
            mul(ans,tmp);
        }
        i=r+1;
    }
    return ans ; 
}
int main() {
    srand(chrono::steady_clock::now().time_since_epoch().count());
    ios::sync_with_stdio(false),cin.tie(0);
    init();
    vi v,u ; 
    u.eb(-1);
    v.eb(-1);
    cin >> n >> k ; 
    for(int i=1;i<=n;i++) {
        int x ; 
        cin >> x ; 
        if(i&1) {
            u.eb(x);
        }
        else v.eb(x);
    }
    u.eb(-1);
    v.eb(-1);
    cout << solve(v)*solve(u)%mod << '\n' ; 
    return 0 ;
}