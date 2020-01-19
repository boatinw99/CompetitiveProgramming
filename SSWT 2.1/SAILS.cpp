#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mid (l+r>>1)
const int N = 1e5+9 ;
pii a[N];///height , flags
int st[N*4],lazy[N*4],mxhi=0;
void uplazy(int l,int r,int m)
{
    if(lazy[m])
    {
        st[m]+=lazy[m];
        if(l<r)
        {
            lazy[m<<1]+=lazy[m];
            lazy[m<<1|1]+=lazy[m];
        }
        lazy[m]=0;
    }
}
void update(int l,int r,int x,int y,int m)
{
    uplazy(l,r,m);
    if(r<x||l>y)return ;
    if(l>=x&&r<=y)
    {
        st[m]++;
        if(l<r)
        {
            lazy[m<<1]++;
            lazy[m<<1|1]++;
        }
        return ;
    }
    update(l,mid,x,y,m<<1),update(mid+1,r,x,y,m<<1|1);
    st[m]=max(st[m<<1],st[m<<1|1]);
}
int findmax(int l,int r,int x,int y,int m)
{
    uplazy(l,r,m);
    if(r<x||l>y)return 0;
    if(l>=x&&r<=y)return st[m];
    return max(findmax(l,mid,x,y,m<<1),findmax(mid+1,r,x,y,m<<1|1));
}
int findposmin(int l,int r,int cst)
{
    l--;
    while(l+1<r)
    {
        int tmp = findmax(1,mxhi,mid,mid,1);
        if(tmp<=cst)r=mid;
        else l=mid ;
    }
    return r ;
}
int findposmax(int l,int r,int cst)
{
    r++;
    while(l+1<r)
    {
        int tmp = findmax(1,mxhi,mid,mid,1);
        if(tmp<cst)r=mid;
        else l=mid ;
    }
    return l ;
}
ll findans(int l,int r,int m)
{
    uplazy(l,r,m);
    if(l==r)return 1ll*st[m]*(st[m]-1)/2;
    return findans(l,mid,m<<1)+findans(mid+1,r,m<<1|1);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j ;
    cin >> n ;
    for(i=1;i<=n;i++)
    {
        cin >> a[i].fi >> a[i].se ;
        mxhi=max(mxhi,a[i].fi);
    }
    sort(a+1,a+1+n);
    for(i=1;i<=n;i++)
    {
        int mx=findmax(1,mxhi,a[i].fi-a[i].se+1,a[i].fi,1);
        int L = findposmin(1,a[i].fi,mx);
        int R = findposmax(1,a[i].fi,mx);
        int range=a[i].fi-R,rmn=a[i].se-range;
        if(R+1<=R+range)update(1,mxhi,R+1,R+range,1);
        if(L<=L+rmn-1)update(1,mxhi,L,L+rmn-1,1);
    }
    cout << findans(1,mxhi,1);
}
