#include<bits/stdc++.h>
using namespace std ;
typedef unsigned long long ull ;
typedef long long ll ; 
typedef double db ; 
typedef pair<ull,ull> puu ; 
typedef pair<ll,ll> pll ;
typedef vector<int> vi ; 
typedef vector<ll> vl ;
#define mid (l+r>>1)
#define fi first
#define se second 
#define trav(it,x) for(auto&it:x) 
#define mp make_pair
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define up upper_bound
const ull MOD1 = 1e9+7 , MOD2 = 1e9+9 , MMOD1 = MOD1*MOD1 , MMOD2 = MOD2*MOD2; 
const ll INF = 1e18 ; 
const double pi = 3.14159265358979 ; 
const int N = 709 , inf = 1e9 , mod = 1e9+7 ; 
string s ; 
int nxt[N];
void add(ll &a,ll b) {
    a+=b;
    a%=mod ;
}
ll my_rand() {
    ll a = rand();
    ll b = rand();
    return a*(RAND_MAX+1)+b ; 
}
void init() {
    // gen_hashprime();
}
vector<vl> cont(vector<vl> tmp) {
    vector<vl> res ; 
    for(int i=0;i<3;i++) {
        res.eb(vl(3));
    }
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            for(int k=0;k<3;k++) {
                for(int d=0;d<3;d++) {
                    if((i==k&&i!=0)||(j==d&&j!=0)) {

                    }
                    else if((i==0&&j!=0)||(i!=0&&j==0)) {
                        add(res[i][j],tmp[k][d]);
                    }
                }
            }
        }
    }
    return res ; 
}
vector<vl> merge(vector<vl> dp,vector<vl> tmp) {
    vector<vl> res ; 
    for(int i=0;i<3;i++) {
        res.eb(vl(3));
    }
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            for(int k=0;k<3;k++) {
                for(int d=0;d<3;d++) {
                    if(j!=k||(j==0)||k==0) {
                        add(res[i][d],dp[i][j]*tmp[k][d]); 
                    }   
                }
            }
        }
    }
    return res ; 
}
vector<vl> dfs(int l,int r) {
    vector<vl> dp,res ; 
    for(int i=0;i<3;i++) {
        dp.eb(vl(3));
    }
    if(l+1==r) {
        dp[1][0]++;
        dp[0][1]++;
        dp[2][0]++;
        dp[0][2]++;
        return dp ; 
    }
    if(nxt[l]<r) {
        dp = merge(dfs(l,nxt[l]),dfs(nxt[l]+1,r));   
    }
    else dp = cont(dfs(l+1,nxt[l]-1));
    // printf("l,r %d %d -> ",l,r);
    // for(int i=0;i<3;i++) {
    //     for(int j=0;j<3;j++) {
    //         printf("%d ",dp[i][j]);
    //     }
    // }
    // printf("\n");
    return dp ;
}
int main() {
    srand(chrono::steady_clock::now().time_since_epoch().count());
    ios::sync_with_stdio(false),cin.tie(0);
    init();
    cin >> s ;
    vector<int> V ; 
    for(int i=0;i<sz(s);i++) {
        if(s[i]=='(') {
            V.eb(i+1);
        }
        else {
            nxt[V.back()]=i+1;
            V.pop_back();
        }
    }
    vector<vl> dp;  
    // printf("check \n");
    dp = dfs(1,sz(s));
    ll ans = 0 ;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            add(ans,dp[i][j]);
        }
    }
    cout << ans << '\n' ;
    return 0 ;
}