#include<bits/stdc++.h>
using namespace std ;
const int N = 1e3+9,md=1e9+7,B=1<<7 ;
int dp[N][N];
int t[B/2][B/2][B/2];
int dp3[12][60][60];
int F[B][B],M[B][B],c[B][B] ;
int n,m,base ;
int powx(int x,int ans)
{
    int r;
    if(x==1)return ans;
    r=powx(x>>1,ans);
    r=r*1ll*r%md;
    if(x&1)r=r*1ll*ans%md;
    return r ;
}
int solve1(int y)
{
    ///dp[i][j] -> dp[pos][consecutive] ;
    ///consecutive = 1->(y-1);
    int i,j,ans=0 ;
    dp[1][1]=2;
    for(i=2;i<=m;i++)
    {
        dp[i][1]=dp[i-1][1];
        for(j=2;j<min(y,i);j++)
        {
            dp[i][1]=(dp[i][1]+dp[i-1][j])%md;
            dp[i][j]=dp[i][j-1];
        }
    }
    for(i=1;i<min(y,i);i++)ans=(ans+dp[m][i])%md;
    ///compute ans^n
    return powx(n,ans);
}
void multi(int a[B][B],int b[B][B])
{
    for(int i=0;i<base;i++)for(int j=0;j<base;j++)for(int k=0;k<base;k++)
        c[i][j]=(c[i][j]+a[i][k]*1ll*b[k][j])%md;
    for(int i=0;i<base;i++)for(int j=0;j<base;j++)a[i][j]=c[i][j],c[i][j]=0;
}
void pow(int x)
{
    if(x==1)return ;
    pow(x>>1);
    multi(F,F);
    if(x&1)multi(F,M);
}
int checked2(int i,int j,int y)
{
    ///checked every y-length of i,j
    int b0=0,b1=0 ; ///bits0 bits1
    for(int d=0;d<m;d++,i/=2,j/=2)
    {
        if((i%2)!=(j%2))b0=0,b1=0;
        else if(i&1)b1++,b0=0;
        else b0++,b1=0;
        if(b0==y||b1==y)return 0 ;
    }
    return 1 ;
}
int checked3(int i,int j,int k,int y)
{
    ///check every y-length of i,j
    int b0=0,b1=0;
    for(int d=0;d<m;d++,i/=2,j/=2,k/=2)
    {
        if(((i%2)!=(j%2))||((i%2)!=(k%2)))b0=0,b1=0;
        else if(i&1)b1++,b0=0;
        else b0++,b1=0;
        if(b0==y||b1==y)return 0 ;
    }
    return 1 ;
}
int solve2(int y)
{
    int base=1<<m,ans=0;
    ///stored matrix
    for(int i=0;i<base;i++)for(int j=0;j<base;j++)
        F[i][j]=M[i][j]=checked2(i,j,y);
    if(n==1)return base ;
    pow(n-1);
    for(int i=0;i<base;i++)for(int j=0;j<base;j++)
        ans=(ans+F[i][j])%md;
    return ans ;
}
int solve3(int y)
{
    int i,j,k,base=1<<m,ans=0,d ;
    if(n<2)return base*n ;
    for(i=0;i<base;i++)for(j=0;j<base;j++)for(k=0;k<base;k++)
        t[i][j][k]=checked3(i,j,k,y);
    for(i=0;i<base;i++)for(j=0;j<base;j++)dp3[2][i][j]=1;
    for(d=3;d<=n;d++)
    {
        for(i=0;i<base;i++)for(j=0;j<base;j++)for(k=0;k<base;k++)
            dp3[d][i][k]=(dp3[d][i][k]+dp3[d-1][i][j]*t[i][j][k])%md;
    }
    for(i=0;i<base;i++)for(j=0;j<base;j++)
        ans=(ans+dp3[n][i][j])%md;
    return ans ;
}
main()
{
    int x,y ;
    cin >> n >> m >> x >> y ;
    base=1<<m;
    if(x==1)cout << solve1(y);
    else if(x==2)cout << solve2(y);
    else cout << solve3(y);
}
