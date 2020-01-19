#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e5+9 ;
int lis[N],lenl[N],lenr[N],a[N];
ll suml[N],sumr[N],mxl[N],mxr[N];
int idx = 0 ;
int find(int x)
{
    int l=0,r=idx+1;
    while(l+1<r)
    {
        int mid = l+r>>1 ;
        if(lis[mid]>=x)l=mid;
        else r=mid ;
    }
    return r ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    cin >> n ;
    for(int i=1,x;i<=n;i++)
    {
        cin >> x ;
        a[i]=x ;
        auto it = upper_bound(lis+1,lis+idx+1,x)-lis;
        if(it>idx)
        {
            idx++;
        }
        lenl[i]=it;
        lis[it]=x;
        suml[it]=suml[it-1]+x;
        mxl[i]=suml[it];
    }
    memset(lis,0,sizeof lis);
    int ans = idx ;
    ll ret = 0 ;
    idx=0;
    for(int i=n;i>=1;i--)
    {
        int pp = find(a[i]);
        if(pp>idx)
        {
            idx++;
        }
        lenr[i]=pp ;
        lis[pp]=a[i];
        sumr[pp]=sumr[pp-1]+a[i];
        mxr[i]=sumr[pp];
    }
    for(int i=1;i<=n;i++)
    {
        if(lenl[i]+lenr[i]-1==ans)
        {
            ret = max(ret,mxr[i]);
        }
    }
    cout << ans << " " << ret << '\n' ;
    return 0 ;
}
