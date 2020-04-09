/*
    technically it passed since the first sub but hash is a bit slow 
*/ 
#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
typedef pair<ll,ll> pll ;
#define mid (l+r>>1)
#define fi first
#define se second 
const ll mod = 1e9+7 , p1 = 98765431 , p2 = 53 ; 
const int N = 5e3+9 , inf = 1e9 ; 
int n,a,b,arr[N]; 
ll dp[N],nxt[N];
pll hsh[N],pw[N];
ll tst[N];
void updatehash(int x) {
    // hsh[x] = {(hsh[x-1].fi*p1+arr[x])%mod,(hsh[x-1].se*p2+arr[x])%mod};
    tst[x] = tst[x-1]*p1+arr[x]; 
}
inline ll gethash(int l,int r) {
    int len = r-l+1 ; 
    return tst[r]-tst[l-1]*pw[len].fi;
    // return {(hsh[r].fi - hsh[l-1].fi*pw[len].fi+mod*mod)%mod,(hsh[r].se-hsh[l-1].se*pw[len].se+mod*mod)%mod}; 
}
void init() {
    pw[0] = {1,1} ;
    for(int i=1;i<N;i++) {
        // pw[i] = {pw[i-1].fi*p1%mod,pw[i-1].se*p2%mod};
        pw[i].fi = pw[i-1].fi*p1 ; 
    }
    fill(dp,dp+N,inf);
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    init();
    cin >> n >> a >> b ; 
    for(int i=1;i<=n;i++) {
        char c ; 
        cin >> c ;
        arr[i] = c-'a';
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
            nxt[i] = -1 ; 
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