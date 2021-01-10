#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ; 
#define fi first
#define se second 
const int N = 1e3+9 ; 
vector<int> V ;
pii sche[N];
void init() {
    V.clear();
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int T ; 
    cin >> T ;
    for(int t=1;t<=T;t++) {
        init();
        int n ;
        cin >> n ; 
        vector<char> ans(n+1); 
        for(int i=1,l,r;i<=n;i++) {
            cin >> l >> r ;
            V.push_back(i);
            sche[i]={l,r}; 
        } 
        sort(V.begin(),V.end(),[&](int a,int b) {
            if(sche[a].fi!=sche[b].fi) {
                return sche[a].fi<sche[b].fi;
            }
            return sche[a].se<sche[b].se;
        });
        multiset<pair<int,char>> mt ; 
        mt.insert({0,'C'});
        mt.insert({0,'J'});
        for(auto it:V) {
            pii ti = sche[it];
            pair<int,char> val = *mt.begin();
            mt.erase(mt.begin());
            if(val.fi<=ti.fi) {
                mt.insert({ti.se,val.se});
                ans[it] = val.se;
            }
            else {
                ans[0]='I';
                break ;
            }
        }
        cout << "Case #" << t << ": " ;
        if(ans[0]=='I') {
            cout << "IMPOSSIBLE" ;
        }
        else {
            for(auto i=1;i<=n;i++) {
                cout << ans[i] ;
            }
        }
        cout << '\n' ; 
    }
    return 0 ; 
}