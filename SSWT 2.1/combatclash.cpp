#include<bits/stdc++.h>
using namespace std ;
const int B = 50,MOD=1e9+7 ;
int F[B][B];
int M[B][B];
int c[B][B];
int g1[3]={-2,0,2};
int g2[3]={-3,0,3};
int g0[3]={-1,0,1};
int base ;
int f[B];
int temp[B];
void multi(int a[B][B],int b[B][B])
{
    int i,j,k ;
    for(i=0;i<base;i++)for(j=0;j<base;j++)for(k=0;k<base;k++)
        c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j])%MOD;
    for(i=0;i<base;i++)for(j=0;j<base;j++)
        a[i][j]=c[i][j],c[i][j]=0;
}
void pow(int n)
{
    if(n==1)return ;
    pow(n/2);
    multi(F,F);
    if(n&1)multi(F,M);
}
void mul(int type)
{
    int i,j ;
    memset(temp,0,sizeof temp);
    for(i=0;i<base;i++)
    {
        temp[i]=(temp[i]+f[i])%MOD;
        if(i-2>=0)temp[i-2]=(temp[i-2]+f[i])%MOD ;
        if(i+2<base)temp[i+2]=(temp[i+2]+f[i])%MOD ;
    }
    for(i=0;i<base;i++)f[i]=temp[i];
    if(type==2)return ;
    memset(temp,0,sizeof temp);
    for(i=0;i<base;i++)
    {
        temp[i]=(temp[i]+f[i])%MOD;
        if(i-3>=0)temp[i-3]=(temp[i-3]+f[i])%MOD;
        if(i+3<base)temp[i+3]=(temp[i+3]+f[i])%MOD ;
    }
    for(i=0;i<base;i++)f[i]=temp[i];
}
main()
{
    int T,i,j,n,k,d ;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&base);
        ///
        for(i=0;i<base;i++)for(j=0;j<base;j++)F[i][j]=M[i][j]=0;
        for(d=0;d<base;d++)
        {
            for(i=0;i<3;i++)
            {
                for(j=0;j<3;j++)
                {
                    for(k=0;k<3;k++)
                    {
                        if(d+g1[i]>=0&&d+g1[i]<base&&
                           d+g1[i]+g2[j]>=0&&d+g1[i]+g2[j]<base&&
                           d+g1[i]+g2[j]+g0[k]>=0&&d+g1[i]+g2[j]+g0[k]<base)
                        {
                            F[d+g1[i]+g2[j]+g0[k]][d]++;
                            M[d+g1[i]+g2[j]+g0[k]][d]++;
                        }
                    }
                }
            }
            f[d]=0;
        }
        ///
        if(n<=3)for(i=0;i<base;i++)f[i]=1;
        else
        {
            pow((n-1)/3);
            for(i=0;i<base;i++)
            {
                for(j=0;j<base;j++)
                {
                    f[i]=(f[i]+F[i][j])%MOD;
                }
            }
        }
        if(n%3==0)mul(0);
        if(n%3==2)mul(2);
        int ans = 0;
        for(i=0;i<base;i++)ans=(ans+f[i])%MOD;
        printf("%d\n",ans);
    }
}
