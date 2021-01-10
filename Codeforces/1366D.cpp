#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ; 
#define fi first
#define se second 
const int N = 1e7+9, M = 5e5+9 ;  
int V[N];
pii ans[M];
void init() {
    for(int i=2;i<N;i++) {
        if(V[i]==0) {
            for(int j=i;j<N;j+=i) {
                if(V[j]==0)V[j]=i;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    init();
    int n ;
    cin >> n ;
    for(int i=1;i<=n;i++) {
        int x ;
        cin >> x ; 
        while(V[x]!=x) {
            if(__gcd(x,(x/V[x]+V[x]))==1) {
                ans[i] = {x/V[x],V[x]};
                break ; 
            }
            x/=V[x];
        }
        if(ans[i].fi==0) {
            ans[i] = {-1,-1};
        }
    }
    for(int i=1;i<=n;i++) {
        cout << ans[i].fi << " " ; 
    }
    cout << '\n' ; 
    for(int i=1;i<=n;i++) {
        cout << ans[i].se << " " ; 
    }
    cout << '\n' ; 
    return 0 ; 
}