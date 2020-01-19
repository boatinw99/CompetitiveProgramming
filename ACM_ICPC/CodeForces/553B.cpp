#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
const ll mod = 1e18+7 ;  
const int N = 59 ; 
ll dp[N][N];/// dp[i][j] -> index i with value j
bool res[N];
int n ;
void pr(int l,int r)
{
    ///print l to r 
    for(int i=l;i>=r;i--)cout << i << " " ;
}
ll getsum(int idx)
{
    ll sum = 0 ;
    for(int i=0;i<=n;i++)sum+=dp[idx][i],sum=min(sum,mod);
    return sum ; 
}
void pre_process(int idx)
{
    if(res[idx])return ; 
    res[idx]++;
    if(idx==n+1)
    {
        dp[idx][0]=1;
        return ; 
    } 
    for(int i=idx;i<=n&&i<=idx+1;i++)
    {
        pre_process(i+1);
        dp[idx][i]=getsum(i+1);
    }
}
void solve(int idx,ll k)
{
    //printf("check %d %lld \n",idx,k);
    if(idx==n+1)
    {
        cout << '\n' ;
        return ; 
    }
    for(int i=idx;i<=n&&i<=idx+1;i++)
    {
        if(dp[idx][i]<k)k-=dp[idx][i];
        else
        {
            pr(i,idx);
            solve(i+1,k);    
            return ; 
        }
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    ll k ; 
    cin >> n >> k ;
    pre_process(1);
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            //printf("check %d -> %d \n",);
        }
    }
    solve(1,k);
    return 0 ;
}