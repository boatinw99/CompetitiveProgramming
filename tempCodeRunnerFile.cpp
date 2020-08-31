#include<bits/stdc++.h>
using namespae std ;
typedef vector<int> vi ; 
#define mid (l+r>>1)
const int N = 1e6+9 ; 
vector<int> a(N),b(N) ; 
int n ; 
void init() {

}
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int T ; 
    cin >> T ; 
    while(T--) {
        init();
        cin >>  n ; 
        for(int i=1;i<=n;i++) {
            cin >> a[i];
        }
        for(int i=1;i<=n;i++) {
            cin >> b[i];
        }
        int l = 0 , r = max(a[1],b[1]);
        while(l<r) {
            int good = 1 ; 
            a1 = a ;
            b1 = b ;
            a1[1] -= mid ; 
            b1[1] -= mid ; 
            a1[2] = max(0,a1[2]-b1[1]);
            a1[n+1] = a1[1];
            for(int i=2;i<=n;i++) {
                int inc = min(a1[i],b1[i]);
                a1[i]-=inc;
                b1[i]-=inc;
                a1[i+1] = max(0,a1[i+1]-b1[i]);
                if(a1[i]>0) {
                    good = 0 ;
                }
                if(i==n && a1[n+1]>0) {
                    good = 1 ;
                }
                else if(i==n && a1[n+1]==0) {
                    good = 2 ;
                }
            }
            printf("check %d %d \n",mid,good);
            if(good == 0) {
                l=mid+1;
            }
            else if(good == 1) {
                r=mid-1;
            }
            else {
                cout << "YES" << '\n';
                return 0 ;
            }
        }
    }
    cout << "NO" << '\n' ; 
    return 0 ; 
}