#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int md = 1e9+7,B=2 ;
int F[B][B],M[B][B]={{1,md-1},{1,0}},c[B][B];
int f[B]={0,1};
int powap(int a,int p)
{
    if(p==1)return a ;
    int r = powap(a,p/2);
    r=1ll*r*r%md ;
    if(p&1)r=1ll*r*a%md ;
    return r ;
}
void multi(int a[B][B],int b[B][B])
{
    int i,j,k ;
    for(i=0;i<B;i++)for(j=0;j<B;j++)for(k=0;k<B;k++)
        c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j])%md ;
    for(i=0;i<B;i++)for(j=0;j<B;j++)a[i][j]=c[i][j],c[i][j]=0 ;
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
    ios::sync_with_stdio(false) ; cin.tie(0);
    ll n ;
    int T,i,j,l,d ;
    cin >> T ;
    while(T--)
    {
        cin >> l >> d >> n ;
        int csx = d*1ll*powap(l,md-2)%md;
        M[0][0] = 2*csx%md; f[0]=csx;
        for(i=0;i<B;i++)for(j=0;j<B;j++)F[i][j]=M[i][j];
        if(n==1)cout << d << '\n' ;
        else
        {
            pow(n-1);
            int ans = 0;
            for(j=0;j<B;j++)ans=(ans+1ll*F[0][j]*f[j])%md ;
            cout << ans*1ll*l%md << '\n' ;
        }

    }
}
