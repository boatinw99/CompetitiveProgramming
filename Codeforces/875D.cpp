#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
typedef pair<int,int> pii ;
#define fi first
#define se second 
const int N = 2e5+9 , BIT = 31 , inf = 1e9 ;
set<int> s;
vector<pii> V ;
int mx[N][BIT],mn[N][BIT],arr[N];
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    ll ans = 0 ; 
    int n ;
    cin >> n ; 
    for(int i=1 ;i<=n;i++) {
        cin >> arr[i] ;
        for(int j=0;j<BIT;j++) {
            mx[i][j] = mx[i-1][j];
            if(arr[i]&(1<<j)) {
                mx[i][j] = i ; 
            }
        }
        V.emplace_back(arr[i],i);
    }
    sort(V.begin(),V.end(),greater<pii>());
    for(int j=0;j<BIT;j++) {
        mn[n+1][j] = inf ; 
    }
    for(int i=n;i>=1;i--) {
        for(int j=0;j<BIT;j++) {
            mn[i][j] = mn[i+1][j] ;
            if(arr[i]&(1<<j)) {
                mn[i][j] = i ; 
            }
        }
    }
    s.insert(0);
    s.insert(n+1);
    for(auto it:V) {
        int idx = it.se ; 
        s.insert(idx);
        auto ptr = s.lower_bound(idx);
        ptr-- ; 
        int l = *ptr ; 
        ptr = s.upper_bound(idx);
        int r = *ptr ; 
        int x=l,y=r;
        for(int j=0;j<BIT;j++) {
            if((it.fi&(1<<j))==0) {
                x = max(x,mx[idx][j]);
                y = min(y,mn[idx][j]);
            }
        }
        ans += 1ll*(idx-l)*(r-idx);
        ans -= 1ll*(idx-x)*(y-idx) ;
    }
    cout << ans << '\n' ; 
    return 0 ;
}