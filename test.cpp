#include<bits/stdc++.h>
using namespace std ;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") 
#define fi first
#define se second 
const int N = 1e7+9 ; 
int a[N];
int main() {
    long long cnt=0; 
    int n=1e5; 
    // int n ; 
    // cin >> n ; 
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cnt++;
            a[i]=j;
        }
    }
    cout << cnt << '\n' ;
    return 0 ; 
}