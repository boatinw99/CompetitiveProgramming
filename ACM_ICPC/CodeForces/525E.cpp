/*
    dur : 22 min 
    MEM_PROB const int N is too small   
*/
#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define fi first
#define se second 
const int N = 26 ; 
map<ll,int> mp[N];
int n,K,arr[N],m=1;
ll fact[N],S,ans = 0 ; 
void dfs1(int x,int y,int k,ll sum) {
    if(sum>S||k>K) {
        return ; 
    }
    if(x>y) {
        mp[k][sum]++;
        return ;
    }
    if(arr[x]<=m) {
        dfs1(x+1,y,k+1,sum+fact[arr[x]]);
    }
    dfs1(x+1,y,k,sum+arr[x]);
    dfs1(x+1,y,k,sum);
}
void dfs2(int x,int y,int k,ll sum) {
    if(sum>S||k>K) {
        return ; 
    }
    if(x>y) {
        ans+=mp[min(K-k,n/2)][S-sum];
        return ; 
    }
    if(arr[x]<=m) {
        dfs2(x+1,y,k+1,sum+fact[arr[x]]);
    }
    dfs2(x+1,y,k,sum+arr[x]);
    dfs2(x+1,y,k,sum);
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> K >> S ; 
    for(int i=1;i<=n;i++) {
        cin >> arr[i] ;
    }
    fact[1]=1;
    for(int i=2;;i++) {
        fact[i] = 1ll*i*fact[i-1];
        if(fact[i]>S) {
            break ; 
        }
        m++;
    }
    dfs1(1,n/2,0,0);
    for(int i=0;i<=min(K,n/2-1);i++) {
        for(auto it:mp[i]) {
            mp[i+1][it.fi]+=it.se ; 
        }
    }
    dfs2(n/2+1,n,0,0);
    cout << ans << '\n' ; 
    return 0 ; 
}