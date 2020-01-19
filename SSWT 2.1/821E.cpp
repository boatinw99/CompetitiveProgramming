#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MOD = 1e9+7 , B=16 ;
int F[B][B];
int M[B][B];
int c[B][B];
int f[B],temp[B];
int base ;
void multi(int a[B][B],int b[B][B])
{
    int i,j,k ;
    for(i=0;i<base;i++)for(j=0;j<base;j++)for(k=0;k<base;k++)
        c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j])%MOD;
    for(i=0;i<base;i++)for(j=0;j<base;j++)
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T,t,y,x,i,j  ;
    ll l,r,k ;
    f[0]=1;
    for(i=0;i<B;i++)
    {
        for(j=0;j<B;j++)
        {
            if(abs(i-j)<=1)
            {
                F[i][j]=M[i][j]=1;
            }
        }
    }
    cin >> T >> k ;
    while(T--)
    {
        cin >> l >> r >> base ;
        base++ ;
        memset(temp,0,sizeof temp);
        for(i=0;i<base;i++)for(j=0;j<base;j++)F[i][j]=M[i][j];
        if(r>k)r=k;
        pow(r-l);
        for(i=0;i<base;i++)for(j=0;j<base;j++)
        {
            temp[i]=(temp[i]+1ll*F[i][j]*f[j])%MOD;
        }
        for(i=0;i<B;i++)f[i]=temp[i];
        if(r==k)
        {
            ///cout
            cout << f[0] ;
            return 0 ;
        }

    }
}
