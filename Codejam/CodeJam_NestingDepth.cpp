#include<bits/stdc++.h>
using namespace std ;
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int T ; 
    cin >> T ;
    for(int t=1;t<=T;t++) {
        string ans="",s;
        cin >> s ; 
        s+="0";
        int numl = 0 ;
        for(int i=0;i<s.size();i++) {
            while(numl<s[i]-'0') {
                numl++;
                ans+="(";
            }
            while(numl>s[i]-'0') {
                ans+=')';
                numl--;
            }
            ans+=s[i];
        }
        ans.erase(ans.size()-1,1);
        cout << "Case #" << t << ": " << ans << '\n' ;
    }
    return 0 ; 
}