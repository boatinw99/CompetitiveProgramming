#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
typedef long long ll ;
#define fi first
#define se second
const int N = 1e6+9 ;
bool dpl[N],dpr[N];
int val[N],n,x;
pii a[N];
int getmax(int l)
{
    l--;
    int tmp = a[l].se;
    int r = n+1;
    while(l+1<r)
    {
        int mid = l+r >> 1 ;
        if(dpr[mid]==1&&tmp<a[mid].se)r=mid;
        else l=mid ;
    }
    return r ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    ll ans = 0 ;
    cin >> n >> x ;
    for(int i=1;i<=n;i++)
    {
        int u ;
        cin >> u ;
        val[i]=u ;
        a[i]={u,i};
    }
    sort(a+1,a+1+n);
    dpl[0]=1;
    for(int i=1;i<=n;i++)
    {
        if(dpl[i-1]==1&&a[i].se>a[i-1].se)dpl[i]++;
    }
    dpr[n]=1;
    for(int i=n-1;i>=1;i--)
    {
        if(dpr[i+1]==1&&a[i].se<a[i+1].se)dpr[i]++;
    }
    for(int i=1;i<=x;i++)
    {
        int idx = lower_bound(a+1,a+1+n,make_pair(i,0))-a;
        if(idx==n+1)
        {
            if(dpl[n]==1)
            {
                ans+=x-i+1;
                continue;
            }
        }
        if(dpl[idx-1]==0)continue ;
        int nxt = getmax(idx);
        if(nxt==1)
        {
            ans+=x-i+1;
            continue ;
        }
        if(nxt==idx)
        {
            ans+=x-a[nxt].fi+1;
            continue ;
        }
        ans+=x-a[nxt-1].fi+1;
    }
    cout << ans ;
    return 0 ;
}
