/*
    Date 02-04-2020 
    Start : 20:00 
    FINISH : 20:23 
    DURATION : 23 
    open partial solution -> technique node sqrt(N) 
    O(NUM_PRIME*sqrt(MAX_VAL))
*/
#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
const int N = 1e5+9 , MAX_VAL = 1e6+9 , inf = 1e9 ;
vector<int> g[MAX_VAL],prime ;
queue<pii> q ; 
int n,sieve[MAX_VAL],dist[MAX_VAL];
void init() {
    sieve[1] = 1 ;
    prime.push_back(1);
    for(int i=2;i<MAX_VAL;i++) {
        if(sieve[i]==0) {
            prime.push_back(i);
            for(int j=i;j<MAX_VAL;j+=i) {
                sieve[j]=i;
            }
        }
    }
}
pii getval(int val) {
    vector<int> V ;
    while(val>1) {
        int div = sieve[val] ;
        int cnt = 0 ;
        while(val%div==0) {
            cnt++;
            val/=div ;
        }
        if(cnt&1) {
            V.push_back(div);
        }
    }
    V.push_back(1);
    V.push_back(1);
    return {V[0],V[1]};
}
void reset() {
    for(auto it:prime) {
        dist[it] = -1 ; 
    }
    while(!q.empty()) {
        q.pop();
    }
}
int bfs(int u) {
    dist[u] = 0 ;
    q.push({u,u});
    while(!q.empty()) {
        pii p = q.front();
        q.pop();
        if(dist[p.fi]*dist[p.fi]>MAX_VAL) {
            return inf ; 
        }
        for(auto it:g[p.fi]) {
            if(it!=p.se&&dist[it]!=-1) {
                return dist[p.fi]+dist[it]+1 ;
            }
            else if(it!=p.se&&dist[it]==-1) {
                dist[it] = dist[p.fi]+1;
                q.push({it,p.fi});
            }
        }
    }
    return inf ; 
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    init();
    int ans = inf ; 
    cin >> n ;
    for(int i=1,val ;i<=n;i++) {
        cin >> val ; 
        pii ret = getval(val) ;
        if(ret.fi==ret.se) {
            ans = 1 ; 
        }
        g[ret.fi].push_back(ret.se);
        g[ret.se].push_back(ret.fi);
    }
    for(auto it:prime) {
        if(it*it>MAX_VAL) {
            break ;
        }
        reset();
        ans = min(ans,bfs(it));
    }
    cout << (ans==inf?-1:ans) << '\n' ; 
    return 0 ;
}