#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N =1e6+9;
ll dp[N];
ll qs[N];
deque<pair<ll,ll> > dq ;
main()
{
    int n,k,i,j ;
    ll x;
    ll max1=0;
    dq.push_back({0,0});
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&qs[i]);
        qs[i]+=qs[i-1];
        dp[i]=dp[i-1];
        x=dp[i-1]-qs[i];
        while(!dq.empty()&&qs[i]-dq.front().second>k)
        {
            dq.pop_front();
        }
        if(!dq.empty())dp[i]=max(qs[i]+dq.front().first,dp[i]);
        while(!dq.empty()&&dq.back().first<=x)
        {
            dq.pop_back();
        }
        dq.push_back({x,qs[i]});
        max1=max(max1,dp[i]);
    }
    printf("%lld",max1);
}
