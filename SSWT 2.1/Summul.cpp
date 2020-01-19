#include<bits/stdc++.h>
using namespace std ;
const int B= 4,MOD=1e9+7 ;
int F[B][B];
int M[B][B]={{1,1,1,0},{1,2,1,0},{0,0,1,1},{0,0,0,1}};
int f[B]={0,0,1,1};
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
    int T,i,j,n ;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<B;i++)for(j=0;j<B;j++)F[i][j]=M[i][j];
        if(n<=1)printf("0");
        else
        {
            pow(n-1);
            int ans = 0;
            for(i=0;i<B;i++)
            {
                ans=(ans+1ll*F[1][i]*f[i])%MOD;
            }
            printf("%d",ans);
        }
        printf("\n");
    }

}
