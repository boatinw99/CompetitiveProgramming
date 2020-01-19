#include<bits/stdc++.h>
using namespace std ;
const int MOD = 1e9+7 , B= 3;
typedef long long ll ;
int F[B][B]={{1,0,1},{1,0,0},{0,1,0}};
int M[B][B]={{1,0,1},{1,0,0},{0,1,0}};
int c[B][B];
void multi(int a[B][B],int b[B][B])
{
    int i,j,k;
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
    ll n ;
    int i,j ;
    scanf("%lld",&n);
    if(n==1)printf("2");
    else if(n==2)printf("3");
    else
    {
        pow(n-2);
        int ans=0;
        for(i=0;i<B;i++)for(j=0;j<B;j++)
            ans=(ans+F[i][j])%MOD;
        printf("%d",ans);
    }
}
