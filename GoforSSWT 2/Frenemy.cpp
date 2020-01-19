#include<bits/stdc++.h>
using namespace std ;
const int N = 1009 ;
typedef long long ll ;
const int MOD=1000000007;
ll pr = 0 ;
char s[N];
int a[N][N];
int dplu[N][N],dpld[N][N],dpru[N][N],dprd[N][N];
main()
{
    int n,i,j ;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf(" %s",&s);
        for(j=0;j<n;j++)
        {
            a[i][j+1]=s[j]-'0';
        }
    }
    dplu[1][0]=1; dpld[n][0]=1; dpru[0][n]=1 ;dprd[n][n+1]=1;

    for(i=1;i<=n;i++)for(j=1;j<=n;j++)
        if(a[i][j]==1)dplu[i][j]=(dplu[i-1][j]+dplu[i][j-1])%MOD;

    for(i=n;i>0;i--)for(j=1;j<=n;j++)
        if(a[i][j]==1)dpld[i][j]=(dpld[i+1][j]+dpld[i][j-1])%MOD;

    for(i=n;i>0;i--)for(j=n;j>0;j--)
        if(a[i][j]==1)dprd[i][j]=(dprd[i+1][j]+dprd[i][j+1])%MOD;

    for(i=1;i<=n;i++)for(j=n;j>0;j--)
        if(a[i][j]==1)dpru[i][j]=(dpru[i-1][j]+dpru[i][j+1])%MOD;

    ll x,y,c1,c2 ;
    for(i=2;i<n;i++)
    {
        for(j=2;j<n;j++)
        {
            if(a[i][j]==1)
            {
                x=(1ll*dpld[i][j-1]*dpru[i][j+1])%MOD;
                y=(1ll*dplu[i-1][j]*dprd[i+1][j])%MOD;
                c1=(x*y)%MOD;
                ///
                x=(1ll*dpld[i+1][j]*dpru[i-1][j])%MOD;
                y=(1ll*dplu[i][j-1]*dprd[i][j+1])%MOD;
                c2=(x*y)%MOD;
                pr=(pr+c1+c2)%MOD;
            }
        }
    }
    printf("%lld\n",pr);
}
