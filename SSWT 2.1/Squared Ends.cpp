#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define mid (l+r>>1)
const ll MAX = 1e14 ;
const int N = 1e4+9 , M = 1e6+9 , K = 109 ;
struct line
{
    ll m,c ;
};
line st[M<<2];
int vst[M<<2],t=0;
ll a[N];
ll dp[N][K];
ll f(line a,ll x)
{
    return a.m*x+a.c ;
}
void update(int l,int r,int m,line nw)
{
    if(vst[m]<t)
    {
        st[m]=nw ;
        vst[m]=t;
        return ;
    }
    bool L = f(nw,l)<f(st[m],l),M = f(nw,mid)<f(st[m],mid);
    if(M)swap(st[m],nw);
    if(l==r)return ;
    else if(L!=M)update(l,mid,m<<1,nw);
    else update(mid+1,r,m<<1|1,nw);
}
ll findmin(int l,int r,int pos,int m)
{
    if(vst[m]<t)return MAX ;
    ll ret = f(st[m],pos);
    if(l==r)return ret ;
    else if(pos<=mid)return min(ret,findmin(l,mid,pos,m<<1));
    else return min(ret,findmin(mid+1,r,pos,m<<1|1));
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,k,mx=1e6 ;
    cin >> n >> k ;
    for(i=1;i<=n;i++)cin >> a[i] ;
    for(i=1;i<=n;i++)dp[i][1]=(a[i]-a[1])*(a[i]-a[1]);
    for(j=2;j<=k;j++)
    {
        t++;
        for(i=j;i<=n;i++)
        {
            update(1,mx,1,{-2*a[i],dp[i-1][j-1]+a[i]*a[i]});
            ll ret = findmin(1,mx,a[i],1)+a[i]*a[i];
            dp[i][j]=ret ;
        }
    }
    cout << dp[n][k];
}
