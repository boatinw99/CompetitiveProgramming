#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 1009,Q = 1e4+9 , md = 1e9+7 , sz= 2e5+9 ;
int fact[sz],inv[sz],dp[N];
pii a[N];
int pow2(int a,int p)
{
    if(p==0)return 1;
    if(p==1)return a;
    int tmp = pow2(a,p>>1);
    tmp=1ll*tmp*tmp%md ;
    if(p&1)tmp=tmp*1ll*a%md;
    return tmp ;
}
void init()
{
    fact[0]=1;
    for(int i=1;i<sz;i++)fact[i]=fact[i-1]*1ll*i%md;
    for(int i=0;i<sz;i++)inv[i]=pow2(fact[i],md-2);
}
int dist(int x,int y)
{
    return fact[x]*1ll*inv[x-y]%md*inv[y]%md;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,i,j,u,v ;
    init();
    cin >> n >> m ;
    for(i=0;i<n;i++)cin >> a[i].fi >> a[i].se ;
    sort(a,a+n);
    for(i=0;i<n;i++)
    {
        dp[i]=dist(a[i].fi+a[i].se-2,a[i].fi-1);
        for(j=0;j<i;j++)
        {
            if(a[j].fi<=a[i].fi&&a[j].se<=a[i].se)
            {
                dp[i]=(dp[i]+md-1ll*dp[j]*dist(a[i].fi-a[j].fi+a[i].se-a[j].se,a[i].fi-a[j].fi))%md;
            }
        }
    }
    while(m--)
    {
        cin >> u >> v ;
        int ans=dist(u+v-2,u-1);
        for(i=0;i<n;i++)
        {
            if(a[i].fi<=u&&a[i].se<=v)
            {
                ans=(ans+md-1ll*dp[i]*dist(u+v-a[i].fi-a[i].se,u-a[i].fi)%md)%md;
            }
        }
        cout << ans << '\n' ;
    }
}
