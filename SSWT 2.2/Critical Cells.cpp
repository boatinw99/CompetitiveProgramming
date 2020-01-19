#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 1e5+9 ,inf = 1e9 ;
struct point
{
    int x,y,idx ;
}p[N];
int dp1[N],dp2[N],lis[N],cnt[N],id=0;
int find(int x)
{
    int l=0,r=id+1;
    while(l+1<r)
    {
        int mid = l+r>>1 ;
        if(lis[mid]>=x)l=mid;
        else r=mid ;
    }
    return l+1;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,k ;
    cin >> n >> m >> k ;
    for(int i=1,x,y ;i<=k;i++)
    {
        cin >> x >> y ;
        p[i]={x,y,i};
    }
    sort(p+1,p+1+k,[&](const point &a,const point &b){
         return (a.x==b.x?a.y<b.y:a.x<b.x);});
    int mx = 0 ;
    for(int i=1;i<=k;i++)
    {
        auto it = upper_bound(lis,lis+id+1,p[i].y)-lis;
        lis[it]=p[i].y;
        if(it>id)id++;
        dp1[p[i].idx]=it;
    }
    memset(lis,0,sizeof lis);
    lis[0]=inf ;
    id=0;
    for(int i=k;i>=1;i--)
    {
        int it = find(p[i].y);
        lis[it]=p[i].y;
        if(it>id)id++;
        dp2[p[i].idx]=it;
    }
    for(int i=1;i<=k;i++)mx=max(mx,dp1[i]+dp2[i]-1);
    for(int i=1;i<=k;i++)if(dp1[i]+dp2[i]-1==mx)cnt[dp1[i]]++;123
    int ans = 0 ;
    for(int i=1;i<=mx;i++)if(cnt[i]==1)ans++;
    cout << ans ;
    return 0 ;
}
