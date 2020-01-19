#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int md = 1e9+7,B=60 ;
int F[B][B],M[B][B],c[B][B],no=0;
bool vis[B];
int dp[25][25];
void multi(int a[B][B],int b[B][B])
{
    int i,j,k ;
    for(i=0;i<no;i++)for(j=0;j<no;j++)for(k=0;k<no;k++)
        c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j])%md ;
    for(i=0;i<no;i++)for(j=0;j<no;j++)a[i][j]=c[i][j],c[i][j]=0;
}
void pow(ll n)
{
    if(n==1)return ;
    pow(n/2);
    multi(F,F);
    if(n&1)multi(F,M);
}
void sqr(int i,int j)
{
    dp[i][i]=dp[i][j]=dp[j][i]=dp[j][j]=no ;
    int dist = (j-i)/2 ;
    no+=dist+1 ;
    for(int x=1;x<=dist;x++)dp[i][i+x]=dp[i+x][i]=dp[i][j-x]=dp[i+x][j]
        =dp[j-x][i]=dp[j][i+x]=dp[j][j-x]=dp[j-x][j]=x+dp[i][i];
    if(i+1>=j)return ;
    sqr(i+1,j-1);
}
void pre_comp(int n)
{
    ///process dp[n][n] and F[n][n],M[n][n]
    sqr(1,n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x = dp[i][j];
            if(!vis[x]++)
            {
                for(int u=1;u<=n;u++)for(int v=1;v<=n;v++)
                    if(max(abs(i-u),abs(j-v))>=1&&
                       max(abs(i-u),abs(j-v))<=2)
                    F[dp[u][v]][x]++;
            }
        }
    }
    for(int i=0;i<no;i++)for(int j=0;j<no;j++)M[i][j]=F[i][j];
}
main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n,T,x,y,i,j  ;
    ll w ;
    cin >> n >> w >> T ;
    pre_comp(n);
    pow(w);
    while(T--)
    {
        cin >> x >> y ;
        int d = dp[x][y] ;
        int ans = 0 ;
        for(i=0;i<no;i++)ans=(ans+F[i][d])%md ;
        cout << ans << '\n' ;
    }
}
