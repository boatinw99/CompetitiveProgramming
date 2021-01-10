#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 59 , M = 3000 , mod = 998244353 ; 
int n,m,sa,sb;
int inv[M];
int W[N],dp[N][N][N];///round SA SB 
bool B[N];
int pow2(int a,int p)
{
    if(p==0)return 1 ;
    int ret = pow2(a,p>>1);
    ret=1ll*ret*ret%mod ;
    if(p&1)ret=ret*1ll*a%mod;
    return ret ;
}
void precomp()
{
    for(int i=0;i<M;i++)
    {
        inv[i]=pow2(i,mod-2);
    }
}
void add(int &a,int b)
{
    a=(a+b)%mod;
}
int comp0(int x)
{
    memset(dp,0,sizeof dp);
    int wi = W[x];
    dp[0][0][0]=1;
    sb-=wi;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<m;k++)
            {
                int rmn = wi-(i-j-k) ;
                if(rmn<0)continue ;
                int tmp = inv[sa+sb+rmn+j-k];
                add(dp[i+1][j+1][k],1ll*dp[i][j][k]*tmp%mod*(j+sa)%mod);
                add(dp[i+1][j][k+1],1ll*dp[i][j][k]*tmp%mod*max(sb-k,0)%mod);
                add(dp[i+1][j][k],1ll*dp[i][j][k]*tmp%mod*max(rmn,0)%mod);
            }
        }
    }
    int ret = 0 ;
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=m;j++)
        {
            int rmn = max(wi-(m-i-j),0);
            ret = (ret+1ll*rmn*dp[m][i][j]%mod)%mod;
        }
    }
    sb+=wi ;
    return ret ; 
}
int comp1(int x)
{
    memset(dp,0,sizeof dp);
    int wi = W[x]; 
    dp[0][0][0]=1;
    sa-=wi ;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<m;k++)
            {
                int rmn = wi+(i-j-k); 
                int tmp=inv[sa+sb+rmn+j-k];
                add(dp[i+1][j+1][k],1ll*dp[i][j][k]*tmp%mod*(j+sa)%mod);
                add(dp[i+1][j][k+1],1ll*dp[i][j][k]*tmp%mod*max(sb-k,0)%mod);
                add(dp[i+1][j][k],1ll*dp[i][j][k]*tmp%mod*max(rmn,0)%mod);
            }
        }
    }
    int ret = 0 ;
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=m;j++)
        {
            int rmn = wi+(m-i-j);
            ret=(ret+1ll*rmn*dp[m][i][j]%mod)%mod;
        }
    }
    sa+=wi ;
    return ret ; 
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    precomp();
    cin >> n >> m ;
    for(int i=1;i<=n;i++)
    {
        cin >> B[i] ;
    }
    for(int i=1;i<=n;i++)
    {
        cin >> W[i] ;
        if(B[i]==0)sb+=W[i];
        else sa+=W[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(B[i]==0)cout << comp0(i) ;
        else cout << comp1(i) ;
        cout << '\n' ;
    }
    return 0 ;
}