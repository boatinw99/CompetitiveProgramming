#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e5 + 9;
ll a[N];
ll dp[N];
struct P
{
    ll max1,posuse,posreal ;
};
deque<P> dq;
set<pair<ll,ll> > s;
set<pair<ll,ll> > ::iterator it;
main()
{
    ll n,m,i,j,l,r ;
    ll slide=0;
    scanf("%lld %lld",&n,&m);
    for(i=1,j=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        slide+=a[i];
        if(a[i]>m)
        {
            printf("-1");
            return 0 ;
        }
        while(slide>m)
        {
            slide-=a[j];
            j++;
        }
        ///max1 posuse(expand to...) posreal
        ///posuse<j
        while(!dq.empty()&&dq.front().posuse<j)
        {
            s.erase({dq.front().max1+dp[dq.front().posuse-1],
                    dq.front().posreal});
            if(dq.front().posuse<dq.front().posreal)
            {
                dq.front().posuse++;
                s.insert({dq.front().max1+dp[dq.front().posuse-1],
                         dq.front().posreal});
            }
            else dq.pop_front();
        }
        while(!dq.empty()&&a[i]>dq.back().max1)
        {
            s.erase({dq.back().max1+dp[dq.back().posuse-1]
                    ,dq.back().posreal});
            dq.pop_back();
        }
        if(dq.empty())
        {
            dq.push_back({a[i],j,i});
        }
        else
        {
            dq.push_back({a[i],dq.back().posreal+1,i});
        }
        s.insert({dq.back().max1+dp[dq.back().posuse-1]
                 ,dq.back().posreal});
        dp[i]=s.begin()->first;
    }
    printf("%lld",dp[n]);
}
