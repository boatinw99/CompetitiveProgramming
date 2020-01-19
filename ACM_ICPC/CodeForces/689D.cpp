#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first 
#define se second 
#define mid (l+r>>1)
const int N = 2e5+9 , inf = 2e9 ;
int a[N],b[N],n;
pii st[N<<2];
pii operate(pii a,pii b)
{
    return {max(a.fi,b.fi),min(a.se,b.se)};
}
void construct(int l,int r,int m)
{
    if(l==r)
    {
        st[m]={a[l],b[l]};
        return ;
    }
    construct(l,mid,m<<1);
    construct(mid+1,r,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}
pii get(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return {-inf,inf};
    if(l>=x&&r<=y)return st[m];
    return operate(get(l,mid,x,y,m<<1),get(mid+1,r,x,y,m<<1|1));
}
long long getr(int idx)
{
    int l=1,r=idx+1;
    while(l+1<r)
    {
        pii ret = get(1,n,mid,idx,1);
        if(ret.fi>=ret.se)l=mid;
        else r=mid;
    }
    while(l>idx||l<1);
    pii ret = get(1,n,l,idx,1);
    if(ret.fi!=ret.se)return inf ; 
    return l ;
}
long long getl(int idx)
{
    //return 0 ;
    int l=0,r=idx;
    while(l+1<r)
    {
        pii ret = get(1,n,mid,idx,1);
        if(ret.fi>ret.se)l=mid;
        else r=mid; 
    }
    pii ret = get(1,n,r,idx,1);
    if(ret.fi!=ret.se)return -inf ;
    return r ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i] ;
    }
    for(int i=1;i<=n;i++)
    {
        cin >> b[i] ;
    }
    construct(1,n,1);
    long long ans = 0 ;
    for(int i=1;i<=n;i++)
    {
        long long  R = getr(i), L = getl(i) ;
        long long ret = R-L+1;
        if(ret<=1ll*n)ans+=ret ;
    }
    cout << ans << '\n' ;
    return 0 ;
}