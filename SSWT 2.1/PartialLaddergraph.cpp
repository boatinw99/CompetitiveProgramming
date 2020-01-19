#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MOD = 1e9+7,B=2 ;
int f[B]={1,1};
int F[B][B]={{4,1},{2,1}};
int M[B][B]={{4,1},{2,1}};
int c[B][B];
void multi(int a[B][B],int b[B][B])
{
    int i,j,k ;
    for(i=0;i<B;i++)for(j=0;j<B;j++)for(k=0;k<B;k++)
        c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j])%MOD;
    for(i=0;i<B;i++)for(j=0;j<B;j++)a[i][j]=c[i][j],c[i][j]=0;
}
void pow(ll n)
{
    if(n==1)return ;
    pow(n>>1);
    multi(F,F);
    if(n&1)multi(F,M);
}
main()
{
    int i,j,k,ans=0 ;
    ll n ;
    cin >> n ;
    if(n==1)cout << "1" ;
    else
    {
        pow(n-1);
        for(j=0;j<B;j++)ans=(ans+F[0][j])%MOD;
        cout << ans ;
    }
}
