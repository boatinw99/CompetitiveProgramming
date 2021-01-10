#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pll ;
#define fi first
#define se second
const int N = 200009 ;
ll sum1[N],a[N],sum2[N],n=1,ans=0 ;
vector<pll> line ;
ll f(pll line,ll x)
{
    return line.fi*x+line.se ;
}
ll query(ll x)
{
    int L=0,R=line.size()-1;
    while(L<R)
    {
        int mid=(L+R)>>1 ;
        if(f(line[mid],x)>=f(line[mid+1],x))R=mid ;
        else L=mid+1 ;
    }
    return f(line[L],x);
}
bool bad(pll a,pll b,pll d)
{
    return 1.0*(d.se-a.se)/(a.fi-d.fi)<=1.0*(b.se-a.se)/(a.fi-b.fi);
}
void add(pll now)
{
    while(line.size()>1&&bad(line[line.size()-2],line.back(),now))line.pop_back();
    line.push_back(now);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i] ;
        sum1[i]=sum1[i-1]+a[i];
        sum2[i]=sum2[i-1]+a[i]*i;
    }
    ans=sum2[n];
    add({-n,-sum1[n]});
    for(int i=n-1;i>=1;i--)
    {
        ans=max(ans,query(-a[i])+sum1[i]+sum2[n]-a[i]*i);
        add({-i,-sum1[i]});
    }
    line.clear();
    add({1,0});
    for(int i=2;i<=n;i++)
    {
        ans=max(ans,query(a[i])+sum1[i-1]+sum2[n]-a[i]*i);
        add({i,-sum1[i-1]});
    }
    cout << ans ;
}
