#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int K = 609 ;
ll a[K],b[K],md ;
ll mul(ll a,ll b)
{
    return a*b%md;
}
void solve(ll n,int k)
{
    if(n==0)
    {
        a[0]=1;
        return ;
    }
    solve(n>>1,k);
    for(int i=0;i<=k;i++)
    {
        ll tmp = 0 ;
        for(int j=0;j<=i;j++)tmp=(tmp+mul(a[j],a[i-j]))%md;
        b[i]=tmp ;
    }
    for(int i=0;i<=k;i++)a[i]=b[i];
    if(n&1)for(int i=k;i>=1;i--)a[i]=(a[i]+a[i-1])%md;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    ll n,fact=1,ans=0 ;
    int k ;
    cin >> n >> k >> md ;
    solve(n+1,k+1);
    for(int i=1;i<=k;i++)
    {
        fact=mul(fact,i);
        ans=(ans+mul(fact,a[i+1]))%md;
    }
    cout << ans ;
}
