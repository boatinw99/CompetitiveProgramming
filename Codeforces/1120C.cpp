#include<bits/stdc++.h>
using namespace std ;
typedef unsigned long long ull ;
typedef pair<ull,ull> puu ; 
typedef long long ll ; 
typedef pair<ll,ll> pll ;
#define mid (l+r>>1)
#define fi first
#define se second 
const ll INF = 1e18 ; 
const ull MOD1 = 1e9+7 , MOD2 = 1e9+9 , MMOD1 = MOD1*MOD1 , MMOD2 = MOD2*MOD2; 
const int N = 5e3+9 , inf = 1e9 ; 
puu hsh[N],pwhsh[N];
int str[N];
ull PRIME1,PRIME2; 
int n,a,b,nxt[N]; 
ll dp[N];
void updatehash(int x) {
    hsh[x] = {(hsh[x-1].fi*PRIME1+str[x])%MOD1,(hsh[x-1].se*PRIME2+str[x])%MOD2};
}
inline puu gethash(int l,int r) {
    int len = r-l+1 ; 
    return make_pair((hsh[r].fi - hsh[l-1].fi*pwhsh[len].fi+MMOD1)%MOD1,(hsh[r].se-hsh[l-1].se*pwhsh[len].se+MMOD2)%MOD2); 
}
/// rolling hash
ll gen_prime() {
    PRIME1 = rand() + rand() ;
    PRIME2 = rand() + rand() ;
    pwhsh[0] = make_pair(1,1);
    for(int i=1;i<N;i++) {
        pwhsh[i] = make_pair((pwhsh[i-1].fi*PRIME1)%MOD1,(pwhsh[i-1].se*PRIME2)%MOD2);
    }
}
ll my_rand() {
    ll a = rand();
    ll b = rand();
    return a*(RAND_MAX+1)+b ; 
}
void init() {
    fill(dp,dp+N,inf);
}
int main() {
    srand(chrono::steady_clock::now().time_since_epoch().count());
    ios::sync_with_stdio(false),cin.tie(0);
    init();
    gen_prime();
    cin >> n >> a >> b ; 
    for(int i=1;i<=n;i++) {
        char c ; 
        cin >> c ;
        str[i] = c-'a';
        updatehash(i);
    }
    int prev = 1 ; 
    for(int i=1;i<=n;i++) {
        int l = max(prev-1,0) , r = i ; 
        while(l+1<r) {
            bool ok = 0 ; 
            for(int j=1;j+mid-1<i&&i+mid-1<=n;j++) {
                if(gethash(i,i+mid-1)==gethash(j,j+mid-1)) {
                    ok++; 
                }
            }
            ok?l=mid:r=mid; 
        }
        prev = l ; 
        if(l==0) {
            nxt[i] = 0 ; 
        }
        else nxt[i] = i+l-1 ;
    }
    dp[0] = 0 ; 
    for(int i=1;i<=n;i++) {
        dp[i] = min(dp[i],dp[i-1]+a);
        dp[nxt[i]] = min(dp[nxt[i]],dp[i-1]+b);
    }
    cout << dp[n] << '\n' ; 
    return 0 ; 
}