/* 
    waste ~ 30 min wrong sol 
*/ 
#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
typedef pair<ll,ll> pll ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
const ll mod = 1e9+7 ; 
const int N = 2e5+9 , p1 = 31 , p2 = 47 ; 
pll hsh[N];
pii qs[N];
ll P1[N],P2[N];
int arr[N],lst[N];
void updatehash(int x) {
    hsh[x] = {(hsh[x-1].fi*p1+arr[x])%mod,(hsh[x-1].se*p2+arr[x])%mod};
}
pll gethash(int l1,int r1) {
    int len = r1-l1+1;
    return {(hsh[r1].fi-hsh[l1-1].fi*P1[len]+mod*mod)%mod,(hsh[r1].se-hsh[l1-1].se*P2[len]+mod*mod)%mod};
}
void init() {
    P1[0] = P2[0] = 1 ; 
    for(int i=1;i<N;i++) {
        P1[i] = P1[i-1]*p1%mod;
        P2[i] = P2[i-1]*p2%mod;
    }
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int n,q ; 
    cin >> n ; 
    init();
    for(int i=1;i<=n;i++) {
        char c ; 
        cin >> c ;
        arr[i] = c-'0' ;
        qs[i]=qs[i-1];
        qs[i].fi+=(arr[i]==0&&i%2);
        qs[i].se+=(arr[i]==0&&i%2==0);
        // printf("check%d %d\n",qs[i].fi,qs[i].se);
        lst[i]=lst[i-1];
        if(arr[i]==1&&arr[i-1]==1) {
            lst[i]=i-1;
        }
        updatehash(i);
    }
    cin >> q ; 
    for(int i=1,l,r,len ;i<=q;i++) {
        bool good = 0 ;
        cin >> l >> r >> len ; 
        if(gethash(l,l+len-1)==gethash(r,r+len-1)) {
            good++;
        }
        else if(lst[l+len-1]>=l&&lst[r+len-1]>=r) {
            if(r%2==l%2) {
                good+=(qs[l+len-1].se-qs[l-1].se==qs[r+len-1].se-qs[r-1].se&&qs[l+len-1].fi-qs[l-1].fi==qs[r+len-1].fi-qs[r-1].fi);
            }
            else {
                good+=(qs[l+len-1].se-qs[l-1].se==qs[r+len-1].fi-qs[r-1].fi&&qs[l+len-1].fi-qs[l-1].fi==qs[r+len-1].se-qs[r-1].se);
            } 
        }
        cout << (good?"Yes":"No") << '\n' ; 
    }
    return 0 ; 
}
