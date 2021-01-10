#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 2009, md=1e9+7 , M=1e5+9 ;
pii a[N];
int fact[M*2],inv[M*2],dp[N];
int pow2(int a,int p)
{
    if(p==0)return 1 ;
    if(p==1)return a;
    int ret=pow2(a,p>>1);
    ret=ret*1ll*ret%md;
    if(p&1)ret=1ll*ret*a%md;
    return ret ;
}
void init()
{
    fact[0]=1;
    for(int i=1;i<2*M;i++)fact[i]=fact[i-1]*1ll*i%md;
    for(int i=0;i<2*M;i++)inv[i]=pow2(fact[i],md-2);
}
int dist(int x,int y)
{
    return 1ll*fact[x]*inv[x-y]%md*inv[y]%md;
}
main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,i,j,k ;
    cin >> n >> m >> k ;
    init();
    for(i=0;i<k;i++)cin >> a[i].fi >> a[i].se ;
    a[k]={n,m};
    sort(a,a+k+1);
    for(i=0;i<=k;i++)
    {
        dp[i]=dist(a[i].fi+a[i].se-2,a[i].fi-1);
        for(j=0;j<i;j++)
        {
            if(a[j].fi<=a[i].fi&&a[j].se<=a[i].se)
            {
                dp[i]=(dp[i]+md-1ll*dp[j]*dist(a[i].fi-a[j].fi+a[i].se-a[j].se,a[i].fi-a[j].fi)%md)%md;
            }
        }
    }
    cout << dp[k] ;
}
