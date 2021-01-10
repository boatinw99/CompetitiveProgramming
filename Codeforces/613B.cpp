#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,int> pli ;
#define fi first
#define se second 
const ll INF = 1e18 ; 
const int N = 1e5+9 ;
pli arr[N];
int rev[N];
ll qs[N];
int pr[N];
int n ;
ll A,cf,cm,m ; 
int get(int idx,int val)
{
    // find 
    int l=idx,r=n+1;
    while(l+1<r)
    {
        int mid = l+r >> 1 ;
        if(val>=arr[mid].fi)
        {
            r=mid;
        }
        else l =mid;
    }
    return r ;
}
ll comp(int idx)
{
    ll ans = 1ll*idx*cf ;
    ll res = m ;
    res-=1ll*idx*A-(qs[1]-qs[idx+1]);
    if(res<0)
    {
        return -INF ;
    }
    if(idx==n)return ans+A*cm;
    ll l=0,r=A+1 ;
    while(l+1<r)
    {
        ll mid = l+r>>1 ;
        int it = get(idx,mid);
        if(res>=1ll*(n-it+1)*mid-(qs[it]))
        {
            l=mid;
        }
        else r=mid;
    }
    return 1ll*l*cm+ans;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> A >> cf >> cm >> m ;
    for(int i=1;i<=n;i++)
    {
        cin >> arr[i].fi ;
        arr[i].se = i ;
    }
    sort(arr+1,arr+1+n,[&](pli a,pli b){
        if(a.fi!=b.fi)return a.fi>b.fi;
        return a.se>b.se ;
    });
    pli ans = {0,0};
    for(int i=1;i<=n;i++)rev[i]=arr[n-i+1].fi;
    for(int i=n;i>=0;i--)
    {
        qs[i]=qs[i+1]+arr[i].fi ;
    }
    for(int i=0;i<=n;i++)
    {
        ll ret = comp(i);
        ans=max(ans,{ret,i});
    }
    cout << ans.fi << '\n' ;
    for(int i=1;i<=ans.se;i++)
    {
        pr[arr[i].se]=A;
    }
    /// ans.fi = cf*ans.se + min*cm ; 
    ll tmp = 0 ;
    if(cm)tmp = (ans.fi - ans.se*cf)/cm ;
    for(int i=ans.se+1;i<=n;i++)
    {
        pr[arr[i].se]=max(tmp,arr[i].fi) ; 
    }
    for(int i=1;i<=n;i++)
    {
        cout << pr[i] << " " ;
    }
    return 0 ;
}