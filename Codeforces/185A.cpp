#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int B = 2,MOD= 1e9+7;
int F[B][B]={{3,1},{1,3}};
int M[B][B]={{3,1},{1,3}};
int c[B][B];
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
    ll n;
    scanf("%I64d",&n);
    if(n==0)
    {
        printf("%d",1);
        return 0 ;
    }
    pow(n);
    printf("%d",F[0][0]%MOD);

}
