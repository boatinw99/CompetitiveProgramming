#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
typedef long long ll ;
pair<ll,ll> a[N];
ll dp[N];
deque<pair<ll,ll> > dq;
main()
{
    int n,k,i,j ;
    ll x,y,c;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%lld %lld",&x,&y);
        a[i]={x,y};
    }
    sort(a,a+n);
    dq.push_back({a[0].first+a[0].second,a[0].first});
    for(i=1;i<n;i++)
    {
        x=a[i].first ;
        c=a[i].second ;
        while(!dq.empty()&&x-dq.front().second>k)
        {
            dq.pop_front();
        }
        if(!dq.empty())
        {
            dp[i]=max(dq.front().first+c-x,dp[i-1]);
        }
        else
        {
            dp[i]=dp[i-1];
        }
        while(!dq.empty()&&dq.back().first<=dp[i-1]+c+x)
        {
            dq.pop_back();
        }
        dq.push_back({dp[i-1]+c+x,x});
    }
    long long max1=0;
    for(i=0;i<n;i++)max1=max(max1,dp[i]);
    printf("%lld",max1);
}
