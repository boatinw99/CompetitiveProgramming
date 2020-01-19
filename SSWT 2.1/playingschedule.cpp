#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MOD = 1e9+7,B=64 ;
int F[B][B],M[B][B],c[B][B];
int base,f[B] ;
void multi(int a[B][B],int b[B][B])
{
    int i,j,k ;
    for(i=0;i<base;i++)for(j=0;j<base;j++)for(k=0;k<base;k++)
        c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j])%MOD;
    for(i=0;i<base;i++)for(j=0;j<base;j++)
        a[i][j]=c[i][j],c[i][j]=0;
}
void pow(ll n)
{
    if(n==1)return ;
    pow(n/2);
    multi(F,F);
    if(n&1)multi(F,M);
}
main()
{
    ll T ;
    int a,b,i,j ;
    scanf("%d %lld %d %d",&base,&T,&a,&b);
    a--; b-- ;
    if(T==2)
    {
        printf("2");
        return  0 ;
    }
    if(T==3)
    {
        printf("%d",2*(base-2));
        return 0 ;
    }
    for(i=0;i<base;i++)f[i]=1;
    f[a]=0;
    for(i=0;i<base;i++)
    {
        for(j=0;j<base;j++)
        {
            F[i][j]=M[i][j]=1;
        }
        F[i][i]=M[i][i]=0 ;
    }
    int ans = 0 ;
    pow(T-3);
    for(i=0;i<base;i++)
    {
        if(i!=b)
        for(j=0;j<base;j++)
        {
            ans=(ans+F[i][j]*f[j])%MOD;
        }
    }
    ans=ans*2;
    printf("%d",ans%MOD);
}
