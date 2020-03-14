/* 
    DATE 14-03-20 
    START 10:53 -> 11:23 , 11.44 -> 12.20 
    DURATION : 1.06 hours 
    dp bitmasks O(N*2^k) 
*/
#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
const int N = 2e5+9 , MAXBIT = 8 , M = 1<<8 , INF = 1e9 ;  
int n,m,k,bits[N],mx,dp[N][M],cnt[M];
bool ava[MAXBIT];
vector<pair<int,pii>> V ; /// st , ed , num 
int getbit() {
    for(int i=0;i<k;i++) {
        if(!ava[i]) {
            ava[i]++;
            return i ; 
        }
    }
}
void init() {
    for(int i=0;i<M;i++) {
        cnt[i] = __builtin_popcount(i)%2 ;
        for(int j=0;j<N;j++) {
            dp[j][i] = -INF ; 
        }
    }
    dp[0][0] = 0 ;
}
int main() { 
    ios::sync_with_stdio(false),cin.tie(0);
    init() ;
    cin >> n >> m >> k ; 
    mx = 1<< k ; 
    for(int i=1,L,R ;i<=n;i++) { 
        cin >> L >> R ;  
        V.push_back({L,{i,0}}); // open 
        V.push_back({R+1,{i,1}}); // end 
    }
    sort(V.begin(),V.end(),[&](pair<int,pii> a,pair<int,pii> b){
        if(a.fi!=b.fi) return a.fi<b.fi ;
        if(a.se.se!=b.se.se) return a.se.se > b.se.se ; 
        return a.se.fi < b.se.fi ;
    });
    int preidx = 0 , ptr = 1 ;
    for(auto it:V) {
        int idx = it.fi ;
        int range = idx-preidx ; 
        if(it.se.se==0) {
            int ret = getbit() ;
           // printf("check %d %d \n",ret);
            bits[it.se.fi] = ret ;
            for(int bit=0;bit<mx;bit++) {
                if(((1<<ret)&bit)==0) {
                    /// 1st case -> not add 
                    dp[ptr][bit] = max(dp[ptr][bit],dp[ptr-1][bit]+range*cnt[bit]);
                    /// 2nd case -> add 
                    dp[ptr][(1<<ret)|bit] = max(dp[ptr][(1<<ret)|bit],dp[ptr-1][bit]+(range-1)*cnt[bit]+(cnt[bit]^1)); 
                }
            }
            //for(int bit=0;bit<mx;bit++)printf("check %d %d ret%d dp%d pidx %d idx %d\n",ptr,bit,1<<ret,dp[ptr][bit],preidx,idx);
        }
        else {
            int ret = bits[it.se.fi] ; 
            ava[ret] = 0 ; 
            for(int bit=0;bit<mx;bit++) {
                if((1<<ret)&bit) {
                    dp[ptr][bit-(1<<ret)] = max(dp[ptr][bit-(1<<ret)],dp[ptr-1][bit]+(range-1)*cnt[bit]+(cnt[bit]^1)) ; 
                }
                else dp[ptr][bit] = max(dp[ptr][bit],dp[ptr-1][bit]+(range)*cnt[bit]);
            } 
            // for(int bit=0;bit<mx;bit++)printf("check %d %d  ret = %d dp = %d \n",ptr,bit,1<<ret,dp[ptr][bit]);
        }
        preidx = idx ; 
        ptr++ ; 
    }
    int ans = 0 ;
    for(int i=0;i<mx;i++) {
        ans = max(ans,dp[ptr-1][i]);
    }
    cout << ans << '\n' ;
    return 0 ; 
}