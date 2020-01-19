///Non-success cause lazy
#include<bits/stdc++.h>
using namespace std ;
const int B = 18,MOD=1e9+7 ;
typedef long long ll ;
int F[B][B];
int M[B][B];
int c[B][B];
int d[10]={1,3,2,1,0,1,1,1,0};
int f[B]={0,3,2,1,1,1,1,1};
int prime[B]={0,1,2,3,5,6,7,10,14,15,21,30,35,42,70,105,210,0};
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
    int T,i,j,x,y ;
    ll n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&n);
        memset(F,0,sizeof F); memset(M,0,sizeof M);
        F[0][0]=M[0][0]=1;
        for(i=0;i<B-1;i++)
        {
            x=prime[i];
            for(j=1;j<B-1;j++)
            {
                y=prime[j];
                if(y!=0&&x%y==0)
                {
                    F[i][j]=M[i][j]=d[x/y];
                }
                else if(x!=0&&y%x==0)
                {
                    F[i][j]=M[i][j]=d[y/x];
                }
            }
        }
        M[2][3]=F[2][3]=1; M[3][2]=F[3][2]=1;
        M[7][0]=F[7][0]=1; M[7][1]=F[7][1]=1; M[7][7]=F[7][7]=1;
        if(n==1)
        {
            printf("4\n");
            continue ;
        }
        for(i=0;i<B;i++){for(j=0;j<B;j++)printf("%d ",M[i][j]);
        printf("\n");}
        int ans=0;
        pow(n-1);
        for(j=0;j<B;j++)
        {
            ans=(ans+1ll*F[7][j]*f[j])%MOD;
            ans=(ans+1ll*F[0][j]*f[j])%MOD;
            ans=(ans+1ll*F[1][j]*f[j])%MOD;
        }
        printf("%d\n",ans);
    }
}
