#include<bits/stdc++.h>
using namespace std ;
const int N = 1e6+9 ;
typedef long long ll ; 
const int mod = 1e9+7 ; 
vector<int> V ; 
deque<int> V1,V2;
ll pow2ap(int a,int p) {
    if(p==0)return 1; 
    ll ret = pow2ap(a,p>>1) ;
    ret=ret*ret%mod;
    if(p&1) {
        ret=ret*a%mod;
    }
    return ret ; 
}
void init() {
    V.clear();
    V1.clear();
    V2.clear();
}
void query() {
    int n,p;
    cin >> n >> p ;
    for(int i=1;i<=n;i++) {
        int x ; 
        cin >> x ;
        V.emplace_back(x);
    }
    if(p==1) {
        cout << n%2 << '\n' ;
        return ; 
    }
    sort(V.begin(),V.end(),greater<int>());
    for(auto it:V) {
        if(V1.empty()) {
            V1.push_back(it);
        }
        else if(V2.empty()) {
            V2.push_back(it);
        }
        else {
            if(V1.front()>V2.front()) {
                // printf("whatttttttt %d %d\n",V1.front(),V2.front());
                V2.push_back(it);
            }
            else V1.push_back(it);
        }
        while(V1.size()>=p&&V1.back()==V1[V1.size()-p]) {
            int tmp = V1.back();
            // printf("delete %d %d \n",V1[V1.size()-p],V1.back());
            for(int i=1;i<=p;i++)V1.pop_back();
            V1.push_back(tmp+1); 
        }
        while(V2.size()>=p&&V2.back()==V2[V2.size()-p]) {
            int tmp = V2.back();
            // printf("delll \n");
            for(int i=1;i<=p;i++)V2.pop_back();
            V2.push_back(tmp+1); 
        }
        if(!V1.empty()&&!V2.empty()&&V1.front()==V2.front()) {
            V1.pop_front();
            V2.pop_front();
        }
        assert((V1.size()==1&&V2.size()>=0)||(V2.size()==1&&V1.size()>=0)||(V1.size()==0&&V2.size()==0));
    }
    int sumx = 0 ;
    int sumy = 0 ;
    for(auto it:V1) {
        sumx+=pow2ap(p,it);
        sumx%=mod;
        // printf("check1 %d\n",it);
    }
    for(auto it:V2) {
        sumy+=pow2ap(p,it);
        sumy%=mod;
        // printf("check2 %d\n",it);
    }
    // printf("--------------------\n");
    if(V1.size()==1) {
        cout << (sumx-sumy+mod)%mod << '\n' ;
    }
    else {
        cout << (sumy-sumx+mod)%mod << '\n' ;
    }
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t ;
    cin >> t; 
    while(t--) {
        init();
        query();
    }
    return 0 ; 
}