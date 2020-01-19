#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 50009,MAX=1e6+9;
vector<pair<ll,ll> > v;
vector<pair<ll,ll> > ::iterator it ;
ll p=0;
pair<ll,ll> a[N];
pair<ll,ll> dp[N];
ll ans[N];
ll slope[MAX];
main()
{
    ll n,i,j  ;
    ll x,y,max1=0,val,x1;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld %lld %lld",&x,&y,&val);
        v.push_back({val,x*y});
    }
    sort(v.begin(),v.end());
    for(it=v.end()-1;;it--)
    {
        if(it->second>max1)
        {
            max1=it->second ;
            a[++p]=*it;
        }
        if(it==v.begin())break;
    }
    for(i=1;i<=p/2;i++)
    {
        swap(a[i],a[p-i+1]);
    }
    dp[1]={a[1].second,0}; ans[1]=a[1].second*a[1].first;
    ll y1;
    /// dp - > {m,c} -> mx+c ;
    ///ans[i]-> min(mx+c);
    ll k ;
    j=1;
    for(i=2;i<=p;i++)
    {
        y=ans[i-1];
        x=a[i].second ;
        dp[i]={x,y};
        for(k=a[i-1].first;k<=a[i].first;k++)
        {
            if(slope[k]!=0&&a[i].first*dp[slope[k]].first+
               dp[slope[k]].second<=a[i].first*dp[j].first+dp[j].second)
            {
                j=slope[k];
            }
        }
        y1=((ans[i-1]-dp[j].second-1)/(dp[j].first-dp[i].first))+1; ///
        if(y1>1ll*MAX);
        else if(y1<=a[i].first)
        {
            j=i;
        }
        else
        {
            slope[y1]=i;
        }
        ans[i]=dp[j].first*a[i].first+dp[j].second;
    }
    printf("%lld",ans[p]);
}
