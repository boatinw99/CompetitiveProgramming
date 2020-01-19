#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MOD = 1e9+7,B=16 ;
int F[B][B],M[B][B],c[B][B];
int f[B];
void multi(int a[B][B],int b[B][B])
{
    int i,j,k;
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
    ll n ;
    int Q,i,j,k,bits=0,t,cnt ;
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%lld",&n);
        bits= 0;
        cnt = 0 ;
        for(i=0;i<4;i++)
        {
            bits <<= 1;
            scanf("%d",&t);
            bits+=t;
            cnt+=t;
            f[1<<i]=1;
        }
        f[0]=6;
        ///I
        memset(F,0,sizeof F);
        for(i=0;i<B;i++)
        {
            for(j=0;j<4;j++)
            {
                F[i][(1<<j)^i]=M[i][(1<<j)^i]=1;
            }
            F[i][i]=M[i][i]=6;
        }
        ///
        if(n==1)
        {
            if(cnt==0)printf("6");
            else if(cnt==1)printf("1");
            else printf("0");
        }
        else
        {
            pow(n-1);
            int ans = 0 ;
            for(j=0;j<B;j++)
            {
                ans=(ans+1ll*F[bits][j]*f[j])%MOD;
            }
            printf("%d",ans);
        }
        printf("\n");
    }
}
