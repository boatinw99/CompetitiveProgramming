#include<bits/stdc++.h>
using namespace std ;
const int B=40,inf=2e9+7 ;
int F[B][B],M[B][B],z[B][B];
int dp[B][B][B];
int a[B],b[B];
int bs ;
void multi(int x[B][B],int y[B][B])
{
    int i,j,k ;
    for(i=0;i<bs;i++)for(j=0;j<bs;j++)z[i][j]=inf ;
    for(i=0;i<bs;i++)for(j=0;j<bs;j++)for(k=0;k<bs;k++)
        if(1ll*x[i][k]+y[k][j]<inf)
        z[i][j]=min(z[i][j],x[i][k]+y[k][j]);
    for(i=0;i<bs;i++)for(j=0;j<bs;j++)x[i][j]=z[i][j];
}
void pow(int n)
{
    if(n==1)return ;
    pow(n/2);
    multi(F,F);
    if(n&1)multi(F,M);
}
main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n,m,i,j,k,d ;
    cin >> n >> m ;
    bs=2*n ;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=n;i++)cin >> b[i];
    ///pre_comp
    for(i=0;i<B;i++)for(j=0;j<B;j++)for(k=0;k<B;k++)dp[i][j][k]=inf ;
    for(d=0;d<2*n;d++)
    {
        dp[d][0][d]=0 ;
        for(i=1;i<=n;i++)
        {
            dp[d][i][0]=dp[d][i-1][1]+b[i];/// ')'
            dp[d][i][2*n-1]=dp[d][i-1][2*n-2]+a[i]; /// '('
            for(j=1;j<2*n-1;j++)
                dp[d][i][j]=min(dp[d][i-1][j-1]+a[i],dp[d][i-1][j+1]+b[i]);
        }
    }
    for(i=0;i<bs;i++)for(j=0;j<bs;j++)
        M[i][j]=F[i][j]=dp[j][n][i];
    pow(m);
    cout << F[0][0] ;
}
