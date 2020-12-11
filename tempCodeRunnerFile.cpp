#include<bits/stdc++.h>
using namespace std ;
#define fi first
#define se second 
map<int,int> mp ; 
int main() {
    mp[2]=3;
    mp[4]=1;
    mp[5]=5;
    for(auto it=mp.begin();it!=mp.end();it++) {
        cout << it->first << " " << it->second << '\n' ; 
    }
    return 0 ; 
}