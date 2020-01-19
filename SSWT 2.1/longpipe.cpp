#include<bits/stdc++.h>
using namespace std ;
const int L = 5,MOD = 1e9+7 ;
int F[L][L]={{1,1,0,1,0},{1,1,1,0,0},{0,1,1,0,1},{0,0,1,1,0},{1,0,0,0,1}};
int M[L][L];
int c[L][L];
int f[L]={2,3,2,1,1};
void multiply(int a[L][L],int b[L][L])
{
    int i,j,k;
    for(i=0;i<L;i++)for(j=0;j<L;j++)for(k=0;k<L;k++)
        c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j])%MOD;
    for(i=0;i<L;i++)for(j=0;j<L;j++)
        a[i][j]=c[i][j],c[i][j]=0;
}
void pow(int n)
{
    if(n==1)return ;
    pow(n/2);
    multiply(F,F);
    if(n&1)multiply(F,M);
}
main()
{
    int ans = 0,n ;
    scanf("%d",&n);
    for(int i=0;i<L;i++)for(int j=0;j<L;j++)M[i][j]=F[i][j];
    if(n==1)
    {
        printf("7");
        return 0 ;
    }
    pow(n-1);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<L;j++)
        {
            ans=(ans+1ll*F[i][j]*f[j])%MOD;
        }
    }
    printf("%d",ans);
}
