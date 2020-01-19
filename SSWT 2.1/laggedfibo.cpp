#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 2009,md = 20092010 ;
int c[N*4][N];
int a[N],f[N*4];
int n=2000 ;
void pow(ll x)
{
    int i,j;
    if(x>=n&&x<2*n)
    {
        for(i=0;i<n;i++)a[i]=c[x][i];
        return ;
    }
    pow(x/2);
    for(i=0;i<n;i++)for(j=0;j<n;j++)f[i+j]=(f[i+j]+1ll*a[i]*a[j])%md;
    for(i=n;i<2*n;i++){
        f[i-n+1]=(f[i-n+1]+f[i])%md;
        f[i-n]=(f[i-n]+f[i])%md;
    }
    for(i=0;i<n;i++)a[i]=f[i];
    memset(f,0,sizeof f);
    if(x&1)
    {
        int g=a[n-1];
        for(i=n-1;i>0;i--)a[i]=a[i-1];
        a[0]=g; a[1]=(a[1]+g)%md;
    }
}
main()
{
    int i,j ;
    ll q=1e18 ;
    c[n][0]=1; c[n][1]=1; c[2*n-1][n-1]=c[2*n-1][1]=c[2*n-1][0]=1;
    for(i=n+1;i<=2*n-2;i++)c[i][i-n]=c[i][i-n+1]=1;
    pow(q);
    int ans=0;
    for(i=0;i<n;i++)ans=(ans+a[i])%md;
    cout << ans ;
}
