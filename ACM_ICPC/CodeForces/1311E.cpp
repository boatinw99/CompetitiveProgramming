/* 
    DATE : 14-03-20 
    ST_TIME : 16.25 
    ED_TIME : 16.40
*/
#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
const int N = 5e3+9 , INF = 1e9 ; 
int ch[N],par[N],depth[N],n;  
void init(int n) {
    memset(par,0,sizeof par);
    for(int i=1;i<=n;i++) {
        ch[i] = 1 ;
        depth[i] = i-1 ;
        par[i] = i-1 ;
    }
    ch[n] = 0 ; 
}
int changepar(int u,int dist) {
    pii mx = {0,0} ;
    for(int i=1;i<=n;i++) {
        if(ch[i]<2&&depth[u]-depth[i]-1<=dist) {
            mx = max(mx,{depth[u]-depth[i]-1,i});
        }
    }
    if(mx.se) {
        ch[par[u]]--;
        par[u] = mx.se ;
        ch[par[u]]++;
        depth[u] -= mx.fi ;
        return mx.fi ; 
    }
    else return INF ; 
    
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int T ; 
    cin >> T ; 
    while(T--) {
        int d ; 
        cin >> n >> d ; 
        init(n);
        int dist = n*(n-1)/2 ; 
        for(int i=n;i>=1&&dist>d;i--) {
            if(ch[i]==0)dist -= changepar(i,dist-d);
        }
        if(d==dist) {
            cout << "YES" << '\n' ;
            for(int i=2;i<=n;i++) {
                cout << par[i] << " " ;
            }
            cout << '\n' ;
        }
        else {
            cout << "NO" << '\n' ;
        }
    }
    return 0 ; 
}