#include<bits/stdc++.h>
using namespace std ;
const int B = 100,modans=1e9+7;
int F[B][B];
int M[B][B];
int c[B][B];
int f[B],MOD ;
void multi(int a[B][B],int b[B][B])
{
    int i,j,k ;
    for(i=0;i<MOD;i++)for(j=0;j<MOD;j++)for(k=0;k<MOD;k++)
        c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j])%modans;
    for(i=0;i<MOD;i++)for(j=0;j<MOD;j++)
        a[i][j]=c[i][j],c[i][j]=0;
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
    int n,b,k,x,ai,i,j,y,x1,x2 ;
    scanf("%d %d %d %d",&n,&b,&k,&MOD);
    while(n--)
    {
        scanf("%d",&ai);
        f[(ai%MOD)]++;
    }
    if(b==1)
    {
        printf("%d",f[k]);
        return 0 ;
    }
    for(i=0;i<B;i++)
    {
        for(j=0;j<B;j++)
        {
            y=(j*10)%MOD;
            x1=max(i-y,0); x2=min(MOD+i-y,99);
            F[i][j]=M[i][j]=f[x1]+f[x2];
        }
    }
    pow(b-1);
    int ans = 0 ;
    for(j=0;j<B;j++)
    {
        ans=(ans+1ll*F[k][j]*f[j])%modans;
    }
    printf("%d",ans);
}
