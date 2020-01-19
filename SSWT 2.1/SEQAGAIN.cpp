#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int B = 2 ,md = 1e9+7 ;
int F[B][B],M[B][B],c[B][B];
int f[B];
void multi(int a[B][B],int b[B][B])
{
    int i,j,k ;
    for(i=0;i<B;i++)for(j=0;j<B;j++)for(k=0;k<B;k++)
        c[i][j]=(c[i][j]+a[i][k]*1ll*b[k][j])%(md-1);
    for(i=0;i<B;i++)for(j=0;j<B;j++)a[i][j]=c[i][j],c[i][j]=0;
}
void pow(ll n)
{
    if(n==1)return ;
    pow(n/2);
    multi(F,F);
    if(n&1)multi(F,M);
}
ll powap(ll a,int p)
{
    if(p==0)return 1 ;
    if(p==1)return a ;
    ll res = powap(a,p/2);
    res = res*res%md ;
    if(p&1)res=res*a%md ;
    return res ;
}
main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T,i,j,k ;
    ll n ;
    cin >> T ;
    while(T--)
    {
        cin >> f[0] >> f[1] >> n >> k;
        M[0][0]=M[0][1]=k ;
        M[1][0]=1; M[1][1]=0;
        for(i=0;i<B;i++)for(j=0;j<B;j++)F[i][j]=M[i][j];
        if(n<2)cout << f[n] << '\n' ;
        else
        {
            pow(n-1);
            cout << powap(f[1],F[0][0])*powap(f[0],F[0][1])%md<< '\n';
        }
    }
}
