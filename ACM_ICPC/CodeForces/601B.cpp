#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e5+9 ; 
vector<int> cc ;
ll d[N],arr[N],dp[N]; 
int first_more[N],f[N];
int n,m ;
ll solve(int x,int y)
{
    ll ans = 0 ;
    for(int i=x+1;i<=y;i++)
    {
        int r = max(x,first_more[i]);
        int len = i-r;
        ll res=dp[r]+len*d[i];
        dp[i]=res ;
        ans+=res ;
    }
    return ans ; 
}
void update(int x,int idx)
{
    for(;x;x-=x&-x)
    {
        f[x]=max(f[x],idx);
    }
}
int getmx(int x)
{
    int ret = 0 ;
    for(;x<=n;x+=x&-x)
    {
        ret=max(ret,f[x]);
    }
    return ret ;
}
void pre_process()
{
    for(int i=2;i<=n;i++)
    {
        int idx = lower_bound(cc.begin(),cc.end(),d[i])-cc.begin()+1;
        int mx = getmx(idx+1);
        first_more[i]=mx;
        update(idx,i);
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m ;
    for(int i=1;i<=n;i++)
    {
        cin >> arr[i] ;
    }
    for(int i=2;i<=n;i++)
    {
        d[i]=abs(arr[i]-arr[i-1]);
        cc.push_back(d[i]);
    }
    sort(cc.begin(),cc.end());
    cc.resize(unique(cc.begin(),cc.end())-cc.begin());
    pre_process();
    for(int i=1,l,r ;i<=m;i++)
    {
        cin >> l >> r ;
        memset(dp,0,sizeof dp);
        cout << solve(l,r) << '\n' ; 
    }
    return 0 ;
}