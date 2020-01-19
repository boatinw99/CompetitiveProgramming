#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int B= 5 , MOD= 1e9+7 ;
int F[B][B]={{2,3,3,6,3},{1,0,0,0,0},{0,0,3,6,3},{0,0,0,3,3},
{0,0,0,0,3}};
int M[B][B]={{2,3,3,6,3},{1,0,0,0,0},{0,0,3,6,3},{0,0,0,3,3},
{0,0,0,0,3}};
int c[B][B];
int f[B]={1,1,3,3,3};
void multi(int a[B][B],int b[B][B])
{
    int i,j,k ;
    for(i=0;i<B;i++)for(j=0;j<B;j++)for(k=0;k<B;k++)
        c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j])%MOD;
    for(i=0;i<B;i++)for(j=0;j<B;j++)
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
    int T,i,j ;
    ll n ;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&n);
        if(n==1)printf("1\n");
        else
        {
            int ans = 0 ;
            for(i=0;i<B;i++)for(j=0;j<B;j++)F[i][j]=M[i][j];
            pow(n-1);
            for(j=0;j<B;j++)
            {
                ans=(ans+1ll*F[0][j]*f[j])%MOD;
            }
            printf("%d\n",ans);
        }
    }
}
