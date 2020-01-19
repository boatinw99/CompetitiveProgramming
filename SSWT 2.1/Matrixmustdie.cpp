#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int B = 9,MOD=1e9+7,LOG=log2(1e12) ;
int ans[B];
int temp[B];
int F[LOG+1][B][B];
main()
{
    ll n,bits;
    int T,i,j,d,k,x,y,k1,k2  ;
    scanf("%d",&T);
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            k1=i*3+j;
            for(x=0;x<3;x++)
            {
                for(y=0;y<3;y++)
                {
                    k2=x*3+y ;
                    F[0][k1][k2]=abs(i-x)+abs(j-y)+abs(i+j-x-y);
                }
            }
        }
    }
    for(d=0;d<LOG;d++)
    {
        for(i=0;i<B;i++)for(j=0;j<B;j++)for(k=0;k<B;k++)
            F[d+1][i][j]=(F[d+1][i][j]+
                    1ll*F[d][i][k]*F[d][k][j])%MOD;
    }
    while(T--)
    {
        scanf("%lld",&n);
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                scanf("%d",&ans[i*3+j]);
            }
        }
        for(d=0;d<=LOG;d++)
        {
            if((1ll<<d)&n)
            {
                for(i=0;i<B;i++)for(j=0;j<B;j++)
                    temp[i]=(temp[i]+1ll*F[d][i][j]*ans[j])%MOD;
                for(i=0;i<B;i++)
                    ans[i]=temp[i],temp[i]=0;
            }
        }
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                printf("%d ",ans[i*3+j]);
            }
            printf("\n");
        }
    }
}
