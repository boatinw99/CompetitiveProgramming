/*
    wrong sol -> 13min 
*/
#include<bits/stdc++.h>
using namespace std ;
const int N = 409 ; 
string s,t ; 
int dp[N];
int comp(int x) {
    memset(dp,0,sizeof dp);
    dp[0] = x ;
    for(int i=1;i<s.size();i++) {
        char c = s[i] ;
        for(int j=x-1;j>=0;j--) {
            if(dp[j]>=x&&c==t[j+1]&&j<x-1) {
                dp[j+1]=max(dp[j+1],dp[j]);
            }
            if(dp[j]>=x&&c==t[dp[j]]) {
                dp[j]++;
            }
        }
    }
    // for(int i=0;i<t.size();i++) {
    //     printf("%d ",dp[i]);
    // }
    // printf("\n");
    return dp[x-1]==t.size();
}
int main() { 
    ios::sync_with_stdio(false),cin.tie(0);
    int T ; 
    cin >> T ;
    while(T--) {
        int ok = 0 ;
        cin >> s >> t ;
        s = "+" + s ;
        t = '+' + t ;
        for(int i=1;i<t.size();i++) {
            ok = max(ok,comp(i));
        }
        cout << (ok?"YES":"NO") << '\n' ;
    }
    return 0 ;
}