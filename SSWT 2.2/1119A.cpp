#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second
const int N=400009,inf = 1e9+7 ;
int st[N*4],a[N];
void update(int l,int r,int x,int cst,int m)
{
    if(r<x||l>x)return ;
    if(l==r)
    {
        st[m]=min(st[m],cst);
        return ;
    }
    update(l,mid,x,cst,m<<1);
    update(mid+1,r,x,cst,m<<1|1);
    st[m]=min(st[m<<1],st[m<<1|1]);
}
int findmin(int l,int r,int x,int y,int m)
{
    if(r<x||l>y||x>y)return inf ;
    if(l>=x&&r<=y)return st[m];
    return min(findmin(l,mid,x,y,m<<1),findmin(mid+1,r,x,y,m<<1|1));
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,ans=0,c ;
    fill(st,st+N*4-1,inf);
    cin >> n ;
    for(i=1;i<=n;i++)
    {
        cin >> c ;
        ans=max(ans,i-findmin(1,n,1,c-1,1));
        ans=max(ans,i-findmin(1,n,c+1,n,1));
        update(1,n,c,i,1);
    }
    cout << ans ;
}
