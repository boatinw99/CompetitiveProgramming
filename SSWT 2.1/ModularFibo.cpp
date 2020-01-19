#include<bits/stdc++.h>
using namespace std ;
int MOD,N=32 ;
int F[2][2]={{1,1},{1,0}};
int M[2][2]={{1,1},{1,0}};
int c[2][2];
void multiply(int a[2][2],int b[2][2])
{
    int i,j,k ;
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)for(k=0;k<2;k++)
            c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j])%MOD;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            a[i][j]=c[i][j];
            c[i][j]=0;
        }
    }
}
void power(int n)
{
    if(n==1)return ;
    power(n/2);
    multiply(F,F);
    if(n&1)
    {
        multiply(F,M);
    }
}
main()
{
    int n,m ;
    while(cin >> n >> m)
    {
        F[0][0]=1; F[0][1]=1; F[1][0]=1; F[1][1]=0;
        MOD=1<<m ;
        if(n==0)printf("0\n");
        else if(n<=2)printf("%d\n",1%MOD);
        else
        {
            power(n-1);
            printf("%d\n",F[0][0]);
        }
    }

}
