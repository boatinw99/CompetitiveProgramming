#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MOD=  1e9+7,B=8;
int F[B][B];
int M[B][B];
int c[B][B];
int f[B]={3,1,2,1,0,1,0,1};
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
    int Q,i,j,k  ;
    ll n;
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%lld",&n);
        if(n==1)
        {
            printf("6\n");
            continue ;
        }
        for(i=0;i<B;i++)
        {
            for(j=0;j<B;j++)
            {
                F[i][j]=M[i][j]=f[i^j];
            }
        }
        pow(n-1);
        int ans = 0 ;
        for(i=1;i<B;i++)
        {
            for(j=0;j<B;j++)
            {
                ans=(ans+1ll*F[i][j]*f[j])%MOD;
            }
        }
        printf("%d\n",ans);
    }
}
