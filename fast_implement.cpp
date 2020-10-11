#include<bits/stdc++.h>
using namespace std ;
const long double PI = 3.1415926535897932384626433 ; 
vector<tuple<int,int,int>> v ; 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    srand(chrono::steady_clock::now().time_since_epoch().count());
    ios::sync_with_stdio(false),cin.tie(0);
    string s ;  
    while(cin >> s) {

        cout << s << '\n' ; 
    }
    // int n ; 
    // cin >> n ; 
    // vector<int> v;  
    // for(int i=1;i<=n;i++) {
    //     int x ; 
    //     cin >> x ; 
    //     v.emplace_back(x);
    // }
    // for(auto it:v) cout << it << '\n' ; 
    return 0 ; 
}