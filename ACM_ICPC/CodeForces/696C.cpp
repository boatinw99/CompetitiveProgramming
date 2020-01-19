#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
const int base = 2 , mod = 1e9+7 ; 
ll F[base][base]={{1,2},{1,0}},M[base][base]={{1,2},{1,0}},c[base][base];
ll f[base];
ll powap(ll a,ll p)
{
    if(p==0)return 1 ;
    ll ret = powap(a,p>>1);
    ret = ret*ret %mod ;
    if(p&1)ret=ret*a%mod ; 
    return ret ; 
}
void multi(ll a[base][base],ll b[base][base])
{
    for(int i=0;i<base;i++)for(int j=0;j<base;j++)for(int k=0;k<base;k++)c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod;
    for(int i=0;i<base;i++)for(int j=0;j<base;j++)a[i][j]=c[i][j],c[i][j]=0;
}
void pow(ll n)
{
    if(n==1)return ; 
    pow(n>>1);
    multi(F,F);
    if(n&1)multi(F,M);   
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    ll div = 2 ; 
    cin >> n ;
    f[0]=(mod-powap(4,mod-2));
    f[1]=powap(2,mod-2);
    swap(f[0],f[1]);
    for(int i=1;i<=n;i++)
    {
        ll mul ; 
        cin >> mul ;
        pow(mul);
        div = powap(div,mul);
        for(int x=0;x<base;x++)for(int y=0;y<base;y++)M[x][y]=F[x][y];
    }
    cout << (F[0][0]*f[0]+F[0][1]*f[1])%mod << "/" << div*powap(2,mod-2)%mod << '\n' ;
    return 0 ;
}