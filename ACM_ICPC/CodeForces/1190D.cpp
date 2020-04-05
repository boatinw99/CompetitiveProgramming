/*
    analysis 
    - take too little time to think and screwed up because sol is wrong 
    - implement speed is acceptable 
    - fix bug speed is acceptable  
    - not being cautious enough -> ll, use it instead of idx 
    - 8 submissions which is really really bad
    dur 
    - take 40 min to realize that sol is wrong 
    - implement 15 min 
*/ 
#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
#define fi first
#define se second 
const int N = 2e5+9 ; 
vector<int> cc ; 
map<int,vector<int>> mp ; 
map<int,int> vst ; 
int f[N],m;
void update(int x,int val) {
    for(;x<N;x+=x&-x) {
        f[x]+=val;
    }
}
int getsum(int x) {
    int sum = 0 ; 
    for(;x;x-=x&-x) {
        sum += f[x] ;
    }
    return sum ; 
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int n ; 
    cin >> n ;
    for(int i=1,x,y ;i<=n;i++) {
        cin >> x >> y ;
        mp[y].emplace_back(x);
        cc.emplace_back(x);
    }
    cc.push_back(0);
    sort(cc.begin(),cc.end());
    cc.resize(unique(cc.begin(),cc.end())-cc.begin());
    m = cc.size()-1;
    ll ans = 0 ; 
    for(auto ptr=mp.rbegin();ptr!=mp.rend();ptr++) {
        sort(ptr->se.begin(),ptr->se.end());
        int preidx = 0 ;
        for(auto it:ptr->se) {
            if(!vst[it]++) {
                int idx = lower_bound(cc.begin(),cc.end(),it)-cc.begin();
                update(idx,1);
            }
        }
        for(auto it:ptr->se) {
            int idx = lower_bound(cc.begin(),cc.end(),it)-cc.begin();
            ans += 1ll*(getsum(m)-getsum(idx)+1)*(getsum(idx-1)-getsum(preidx)+1); 
            preidx = idx ; 
        }
    }
    cout << ans << '\n' ; 
    return 0 ; 
}