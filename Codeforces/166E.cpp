#include<bits/stdc++.h>
using namespace std ;
const int MOD = 1e9+7,B=4;
int F[B][B];
int M[B][B];
int c[B][B];
void multi(int a[B][B],int b[B][B])
{
    int i,j,k ;
    for(i=0;i<B;i++)for(j=0;j<B;j++)for(k=0;k<B;k++)
        c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j])%MOD;
    for(i=0;i<B;i++)for(j=0;j<B;j++)
        a[i][j]=c[i][j],c[i][j]=0;
}
void pow(int n)
{
    if(n==1)return ;
    pow(n/2);
    multi(F,F);
    if(n&1)multi(F,M);
}
main()
{
    int n,i,j ;
    scanf("%d",&n);
    for(i=0;i<B;i++)
    {
        for(j=0;j<B;j++)F[i][j]=M[i][j]=1;
        F[i][i]=M[i][i]=0;
    }
    if(n==1)
    {
        printf("0");
        return 0 ;
    }
    else
    {
        int ans=0;
        pow(n-1);
        for(i=1;i<B;i++)
        {
            ans=(ans+F[0][i])%MOD;
        }
        printf("%d",ans);
    }
}
