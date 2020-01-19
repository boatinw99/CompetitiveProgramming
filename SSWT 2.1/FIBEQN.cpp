#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int B = 2,md = 1e9+7 ;
int F[B][B];
int M[B][B]={{1,1},{1,0}};
int c[B][B];
void multi(int a[B][B],int b[B][B])
{
    int i,j,k ;
    for(i=0;i<B;i++)for(j=0;j<B;j++)for(k=0;k<B;k++)
        c[i][j]=(c[i][j]+a[i][k]*1ll*b[k][j])%md ;
    for(i=0;i<B;i++)for(j=0;j<B;j++)a[i][j]=c[i][j],c[i][j]=0;
}
void pow(ll n)
{
    if(n==1)return ;
    pow(n/2);
    multi(F,F);
    if(n&1)multi(F,M);
}
ll powap(ll a,ll p)
{
    if(p==1)return a ;
    ll x = powap(a,p/2);
    x = x*x%md;
    if(p&1)x=x*a%md;
    return x ;
}
ll query(ll n)
{
    int i,j ;
    for(i=0;i<B;i++)for(j=0;j<B;j++)F[i][j]=M[i][j];
    if(n<2)return n ;
    pow(n-1);
    return F[0][0];
}
main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T,i,j ;
    ll n,k ;
    cin >> T ;
    while(T--)
    {
        cin >> n >> k ;
        k%=md ;
        ll inv = powap((k*k%md+k-1)%md,md-2);
        ll fn1=query(n+1)*powap(k,n+1)%md;
        ll fn=query(n)*powap(k,n+2)%md;
        cout << (fn1+fn-k+md)*inv%md << '\n' ;
    }
}
