#include<bits/stdc++.h>
using namespace std ;
const int MOD = 1e9+7,B=52 ;
typedef long long ll ;
int base ;
int F[B][B],M[B][B],c[B][B];
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
    int i,j,m,c1,c2,k ;
    ll n ;
    char d1,d2;
    scanf("%I64d %d %d",&n,&base,&k);
    m=base ;
    for(i=0;i<m;i++)for(j=0;j<m;j++)
        F[i][j]=M[i][j]=1;
    while(k--)
    {
        scanf(" %c %c",&d1,&d2);
        c1=d1; c2=d2;
        if(c1>='a'&&c1<='z')c1-='a';
        else c1-='A'-26;
        if(c2>='a'&&c2<='z')c2-='a';
        else c2-='A'-26 ;
        F[c2][c1]=M[c2][c1]=0;
    }
    if(n==1)
    {
        printf("%d",m);
        return 0;
    }
    pow(n-1);
    ll ans=0;
    for(i=0;i<base;i++)for(j=0;j<base;j++)
        ans=(ans+F[i][j])%MOD;
    printf("%4d",ans);

}
