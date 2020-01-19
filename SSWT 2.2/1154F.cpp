#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const ll inf = 1e14 ;
const int N = 2e5+9 , K = 2009 ;
int a[N],offer[K] ;
ll dp[K],qs[K];
int n,m,k ;
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m >> k ;
    for(int i=1;i<=n;i++)cin >> a[i] ;
    sort(a+1,a+1+n);
    for(int i=1;i<=k;i++)qs[i]=qs[i-1]+a[i];
    for(int i=2;i<=k;i++)offer[i]=-1,dp[i]=inf ;
    dp[1]=inf ;
    for(int i=1,x,y ;i<=m;i++)
    {
        cin >> x >> y ;
        if(x<=k)offer[x]=max(offer[x],y);
    }
    for(int i=1;i<=k;i++)
    {
        dp[i]=dp[i-1]+a[i];
        for(int j=1;j<=i;j++)
        {
            if(offer[j]<=0)continue ;
            dp[i]=min(dp[i],dp[i-j]+qs[i]-qs[i-j+offer[j]]);
        }
    }
    cout << dp[k];
    return 0 ;
}
