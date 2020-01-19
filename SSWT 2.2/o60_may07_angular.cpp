#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 2009 ;
pii a[N];
vector<pii> cc1,cc2 ;
vector<int> A ,B ;
int dp[N];
bool cmpx(int x,int y)
{
    if(a[x].fi!=a[y].fi)return a[x].fi<a[y].fi;
    return a[x].se<a[y].se;
}
bool cmp1(pii x,pii y)
{
    int x1=x.fi,x2=x.se,y1=y.fi,y2=y.se ;
    ll mx = 1ll*(a[x2].se-a[x1].se)*(a[y2].fi-a[y1].fi);
    ll my = 1ll*(a[y2].se-a[y1].se)*(a[x2].fi-a[x1].fi);
    if(mx!=my)return mx>my;
    return a[x1].fi<a[y1].fi;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,w,x,y,cnt=0 ;
    cin >> w >> n ;
    a[n+1]={w,w};
    for(i=1;i<=n;i++)
    {
        cin >> a[i].fi >> a[i].se ;
        if(a[i].se>a[i].fi)A.emplace_back(i);
        else if(a[i].se<a[i].fi)B.emplace_back(i);
        else cnt++;
    }
    dp[0]=1;
    A.emplace_back(0),A.emplace_back(n+1);
    sort(A.begin(),A.end(),cmpx);
    for(i=0;i<A.size();i++)for(j=i+1;j<A.size();j++)cc1.push_back({A[i],A[j]});
    sort(cc1.begin(),cc1.end(),cmp1);
    for(auto it:cc1)if(dp[it.fi])dp[it.se]=max(dp[it.se],dp[it.fi]+1);
    int ans=dp[n+1];
    dp[n+1]=0;
    B.emplace_back(0),B.emplace_back(n+1);
    sort(B.begin(),B.end(),cmpx);
    for(i=0;i<B.size();i++)for(j=i+1;j<B.size();j++)cc2.push_back({B[i],B[j]});
    sort(cc2.begin(),cc2.end(),cmp1);
    reverse(cc2.begin(),cc2.end());
    for(auto it:cc2)if(dp[it.fi])dp[it.se]=max(dp[it.se],dp[it.fi]+1);
    cout << max({ans+dp[n+1]-4,ans-2+cnt,dp[n+1]+cnt-2});
}
