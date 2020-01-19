#include<bits/stdc++.h>
using namespace std ;
const int B = 3 ,MOD = 1e9+7 ;
int F[B][B];
int c[B][B];
int f[B]={1,1,0};
int M[B][B]={{1,1,0},{1,2,0},{1,0,MOD-1}};
void multi(int a[B][B],int b[B][B])
{
    int i,j,k ;
    for(i=0;i<B;i++)for(j=0;j<B;j++)for(k=0;k<B;k++)
        c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j])%MOD;
    for(i=0;i<B;i++)for(j=0;j<B;j++)
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
    int T,n,i,j ;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<B;i++)for(j=0;j<B;j++)F[i][j]=M[i][j];
        pow((n+1)/2);
        int ans=0;
        for(j=0;j<B;j++)ans=(ans+1ll*F[2][j]*f[j])%MOD;
        printf("%d\n",ans);
    }
}
