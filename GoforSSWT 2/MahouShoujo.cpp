#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
int a[N];
int dp[N];
deque<pair<int,pair<int,int> > > dq;
set<pair<int,pair<int,int> > > s;
set<pair<int,pair<int,int> > > ::iterator it;
///dq -> (max,(posuse,posreal))
///set -> (dp+max,(posuse,posreal));
main()
{
    int n,k,i,j,x,d;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    dp[1]=a[1];
    dq.push_back({a[1],{1,1}});
    s.insert({a[1],{1,1}});
    for(i=2;i<=n;i++)
    {
        x=a[i];
        while(!dq.empty()&&i-dq.front().second.first>=k)
        {
            s.erase({dq.front().first+dp[dq.front().second.first-1],
            {dq.front().second.first,dq.front().second.second}});
            if(dq.front().second.second>dq.front().second.first)
            {
                dq.front().second.first++;
                s.insert({dq.front().first+dp[dq.front().second.first-1],
                {dq.front().second.first,dq.front().second.second}});
            }
            else
            {
                dq.pop_front();
            }
        }
        while(!dq.empty()&&dq.back().first<x)
        {
            s.erase({dq.back().first+dp[dq.back().second.first-1],
            {dq.back().second.first,dq.back().second.second}});
            dq.pop_back();
        }
        if(dq.empty())d=max(1,i-k+1);
        else d=dq.back().second.second+1;
        dq.push_back({a[i],{d,i}});
        s.insert({a[i]+dp[d-1],{d,i}});
        it=s.begin();
        dp[i]=it->first;
    }
    printf("%d",dp[n]);
}
