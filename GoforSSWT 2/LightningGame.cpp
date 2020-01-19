#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 40,K=53,MOD=1e9+7;
int dpyes[N][K][K],dpno[N][K][K];
int dp[K][K][K];
int poww[K];
main()
{
    int T,i,j,k,d ;
    ll n,bit;
    scanf("%d",&T);
    poww[0]=1;
    for(i=1;i<K;i++)
    {
        poww[i]=(1ll*poww[i-1]*2)%MOD;
    }
    while(T--)
    {
        scanf("%lld %d",&n,&k);
        ///preprocess
        for(i=1;i<=k;i++)
        {
            for(j=0;j<=i;j++)
            {
                for(d=0;d+j<i;d++)
                {
                    dp[i][j][d]=poww[max(0,i-j-d-2)];
                }
            }
            dp[i][i][i]=1;
        }
        ///process1;
        for(i=0;i<k;i++)
        {
            for(j=0;j<k;j++)
            {
                dpno[1][i][j]=dp[k][i][j];
            }
        }
        dpyes[1][k][k]=dp[k][k][k];
        for(d=2,bit=k*2;bit<=n;d++,bit*=2)
        {
            for(i=0;i<=k;i++)
            {
                for(j=0;j<=k;j++)
                {

                }
            }
        }
    }
    //printf("%d ",dpyes[1][1][0]);
}
