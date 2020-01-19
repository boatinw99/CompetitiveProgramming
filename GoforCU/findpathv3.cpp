#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
vector<ll> v;
queue<ll>q ;
main()
{
    int i,n,j ;
    ll x;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&x);
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int pr=0;
    while(!q.empty() or !v.empty())
    {
        if(q.empty())x=v.back();
        else if(v.empty()) x=q.front();
        else x=max(v.back(),q.front());
        if(x==1)break;
        pr++;
        while(!q.empty()&&q.front()==x)q.pop();
        while(!v.empty()&&v.back()==x)v.pop_back();
        q.push(x/2);
    }
    printf("%d",pr);
}
