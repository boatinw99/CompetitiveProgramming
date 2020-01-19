#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int LOG = log2(1e15),MOD=1e9+9;
int f[3]={1,0,0};
int temp[3];
int M[3][3]={{1,1,2},{1,0,0},{1,0,1}};
int F[LOG+1][3][3];
main()
{
    int T,i,j,d,k ;
    ll n ;
    scanf("%d",&T);
    for(i=0;i<3;i++)for(j=0;j<3;j++)F[0][i][j]=M[i][j];
    for(d=0;d<LOG;d++)
    {
        for(i=0;i<3;i++)for(j=0;j<3;j++)for(k=0;k<3;k++)
            F[d+1][i][j]=(F[d+1][i][j]+
                          1ll*F[d][i][k]*F[d][k][j])%MOD;
    }
    while(T--)
    {
        scanf("%lld",&n);
        f[0]=1; f[1]=0; f[2]=0;
        for(d=0;d<=LOG;d++)
        {
            if(((1ll<<d)&n)>0)
            {
                for(i=0;i<3;i++)for(j=0;j<3;j++)
                {
                    temp[i]=(temp[i]+1ll*F[d][i][j]*f[j])%MOD;
                }
                for(i=0;i<3;i++)f[i]=temp[i],temp[i]=0;
            }
        }
        printf("%d\n",f[2]);

    }
}
