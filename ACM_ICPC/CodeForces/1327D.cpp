/* 
    14:47 -> 16.00
    problem statement misunderstanding 
    16:10  
    *** Hints : GCD 
    *** remark : should have read problem statement clearly !!! every time !! no matter how much difficult problems are 
*/ 
#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+9 ; 
int p[N],clr[N];
bool vst[N],vst1[N];
vector<vector<int>> V ; 
void init() {
    memset(vst1,0,sizeof vst1);
    V.clear();
}
void dfs(int u) {
    V[V.size()-1].push_back(u);
    vst1[u]++;
    if(!vst1[p[u]]) {
        dfs(p[u]);
    }
}
bool check(vector<int> &v,int dist) {
    for(auto it:v) {
        vst[it] = 0 ; 
    }
    for(int i=0;i<v.size();i++) {
        int idx = i,cl = clr[v[i]];
        bool good = 0 ;
        while(!vst[v[idx]]) {
            vst[v[idx]]++;
            if(clr[v[idx]]!=cl) {
                break;
            }
            idx = (idx+dist)%(v.size());
            if(idx==i) {
                good = 1 ; 
            }
            // printf("w8 what %d %d %d v[idx]=%d %d\n",i,idx,dist,v[idx],vst[v[idx]]);
        }
        if(good) {
            return 1 ; 
        }
    }
    return 0 ; 
}
int comp(vector<int> &u) {
    for(int i=1;i<=u.size();i++) {
        if(u.size()%i==0) {
            if(check(u,i)) {
                return i ;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int T ; 
    cin >> T ; 
    while(T--) {
        init();
        int n ;
        cin >> n ; 
        for(int i=1;i<=n;i++) {
            cin >> p[i] ;
        }
        for(int i=1;i<=n;i++) {
            cin >> clr[i] ;
        }
        int mx = n ; 
        for(int i=1;i<=n;i++) {
            if(!vst1[i]) {
                V.emplace_back(vector<int>());
                dfs(i);
                mx = min(mx,comp(V[V.size()-1]));
            }
        }
        cout << mx << '\n' ; 
    }
    return 0 ; 
}