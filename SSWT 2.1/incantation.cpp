#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int K = 1<< 7 ;
ll F[K][K] ;
ll M[K][K];
ll c[K][K];
int bits ;
void multi(ll a[K][K],ll b[K][K])
{
    int i,j,k ;
    for(i=0;i<bits;i++)for(j=0;j<bits;j++)for(k=0;k<bits;k++)
            c[i][j]=max(c[i][j],a[i][k]+b[k][j]);
    for(i=0;i<bits;i++)for(j=0;j<bits;j++)a[i][j]=c[i][j],c[i][j]=0;
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
    int n,k,i,j,wi,x ;
    ll ans= 0 ;
    scanf("%d %d",&n,&k);
    bits= 1<<k ;
    x=bits/2-1;
    for(i=0;i<bits;i++)
    {
        scanf("%d",&wi);
        F[i][(i&x)<<1]=wi;
        F[i][((i&x)<<1)+1]=wi;
        M[i][(i&x)<<1]=wi;
        M[i][((i&x)<<1)+1]=wi;
    }
    pow(n-k+1);
    for(i=0;i<bits;i++)for(j=0;j<bits;j++)ans=max(ans,F[i][j]);
    printf("%lld",ans);
}
