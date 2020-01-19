#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pll ;
typedef pair<ll,int> pli ;
typedef pair<int,ll> pil ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
const ll INF = 1e18 ;
const int N = 259 , inf = 1e9 , mod = 1e9+7 ;
ll dp[N][N],comb[N][N],powK[2][N];///powK,pow(K-1)
void add(ll &a,ll b)
{
    a+=b;
    a%=mod ;
}
void pre_compute(ll K)
{
    comb[0][0]=1;
    for(int i=1;i<N;i++)
    {
        comb[i][0]=1;
        for(int j=1;j<=i;j++)
        {
            comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%mod;
        }
    }
    powK[0][0]=1;
    powK[1][0]=1;
    for(int i=1;i<N;i++)
    {
        powK[0][i]=powK[0][i-1]*K%mod;
        powK[1][i]=powK[1][i-1]*(K-1)%mod ;
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n;
    ll K ;
    cin >> n >> K ;
    if(K==1)
    {
        cout << "1" << '\n' ;
        return 0 ;
    }
    pre_compute(K);
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        int num=1; 
        if(i==1)num=0;
        for(num;num<=n;num++)
        {
            add(dp[i][num],dp[i-1][num]*powK[1][n-num]%mod*(powK[0][num]-powK[1][num]+mod)%mod);
            for(int k=num+1;k<=n;k++)
            {
                int all = n-num ;
                int inc = k-num ;
                int rmn = n-k ;
                add(dp[i][k],dp[i-1][num]*powK[1][rmn]%mod*powK[0][num]%mod*comb[all][inc]%mod);
            }
        }
    }
    cout << dp[n][n] ;
    return 0 ; 
}