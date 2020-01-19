#include<bits/stdc++.h>
using namespace std ;
const int B = 109 , md = 1e9+7 ;
int F[B][B],M[B][B],c[B][B];
int powap(int a,int p)
{
    if(p==0)return 1 ;
    if(p==1)return a ;
    int r=powap(a,p/2);
    r=1ll*r*r%md ;
    if(p&1)r=1ll*r*a%md ;
    return r ;
}
void multi(int a[B][B],int b[B][B])
{
    int i,j,k ;
    for(i=0;i<B;i++)for(j=0;j<B;j++)for(k=0;k<B;k++)
        c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j])%md ;
    for(i=0;i<B;i++)for(j=0;j<B;j++)a[i][j]=c[i][j],c[i][j]=0;
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
    int n,K,a,b,i,j,k ;
    cin >> n >> K >> a >> b ;
    ///base
    for(i=1;i<=K;i++)for(j=1;j<=K;j++)F[i][j]=(abs(i-j)<=1)?1:0;
    for(i=K+1;i<=K*2;i++)for(j=K+1;j<=K*2;j++)F[i][j]=F[i-K][j-K];
    for(i=K+1;i<=K*2;i++)for(j=a+1;j<b;j++)
        F[i][j]=(abs(i-j-K)<=1)?1:0;
    for(i=1;i<=K*2;i++)for(j=1;j<=K*2;j++)M[i][j]=F[i][j];
    pow(n-2);
    int ans =(1ll*F[K+K/2][K/2]+F[K+K/2][K/2-1]+F[K+K/2][K/2+1])%md;
    cout << ans*1ll*powap(n-2,md-2)%md ;
}
