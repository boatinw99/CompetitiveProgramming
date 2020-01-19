#include<bits/stdc++.h>
using namespace std ;
int MOD,d;
int F[20][20];
int M[20][20];
int c[20][20];
int f[20];
void multiply(int a[20][20],int b[20][20])
{
    int i,j,k;
    for(i=0;i<d;i++)
    {
        for(j=0;j<d;j++)
        {
            for(k=0;k<d;k++)
            {
                c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j])%MOD;
            }
        }
    }
    for(i=0;i<d;i++)
    {
        for(j=0;j<d;j++)
        {
            a[i][j]=c[i][j];
            c[i][j]=0;
        }
    }
}
void pow(int n)
{
    if(n==1)return ;
    pow(n/2);
    multiply(F,F);
    if(n&1)
    {
        multiply(F,M);
    }
}
main()
{
    int n,i,j ;
    while(1)
    {
        scanf("%d %d %d",&d,&n,&MOD);
        if(d==0)return 0 ;
        for(i=1;i<20;i++)
        {
            for(j=0;j<20;j++)
            {
                M[i][j]=F[i][j]=0;
            }
            F[i][i-1]=1,M[i][i-1]=1;
        }
        for(i=0;i<d;i++)
        {
            scanf("%d",&F[0][i]);
            F[0][i]%=MOD;
            M[0][i]=F[0][i];
        }
        for(i=0;i<d;i++)scanf("%d",&f[i]),f[i]%=MOD;
        if(n<=d)
        {
            printf("%d\n",f[n-1]);
        }
        else
        {
            pow(n-d);
            int ans = 0 ;
            for(i=0;i<d;i++)
            {
                ans=(ans+1ll*F[0][i]*f[d-i-1])%MOD;
            }
            printf("%d\n",ans);
        }
    }
}
