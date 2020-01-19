#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 1e5+9,LOG=log2(N)+1;
int st[N*LOG*4],L[N*LOG*4],R[N*LOG*4],root[N];
int n,id=1;
pii a[N];
void construct(int l,int r,int m)
{
    if(l==r)return ;
    L[m]=++id,R[m]=++id;
    int mid=l+r>>1;
    construct(l,mid,L[m]),construct(mid+1,r,R[m]);
}
int update(int l,int r,int x,int cst,int m)
{
    if(r<x||l>x)return m ;
    int tmp=++id,mid=l+r>>1;
    if(l==r)
    {
        st[tmp]=cst ;
        return tmp ;
    }
    L[tmp]=update(l,mid,x,cst,L[m]);
    R[tmp]=update(mid+1,r,x,cst,R[m]);
    st[tmp]=st[L[tmp]]+st[R[tmp]];
    return tmp ;
}
int findsum(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return 0 ;
    if(l>=x&&r<=y)return st[m];
    int mid=l+r>>1;
    return findsum(l,mid,x,y,L[m])+findsum(mid+1,r,x,y,R[m]);
}
int qans(int l,int r)
{
    int S = 0 ;
    while(1)
    {
        auto k = upper_bound(a+1,a+1+n,make_pair(S+1,INT_MAX))-a-1;
        int tmp = findsum(1,n,l,r,root[k]);
        if(tmp>S)S=tmp ;
        else break ;
    }
    return S+1;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j,m,l,r ;
    cin >> n ;
    for(i=1;i<=n;i++)
    {
        cin >> a[i].fi ;
        a[i].se = i ;
    }
    root[0]=1;
    construct(1,n,1);
    sort(a+1,a+1+n);
    for(i=1;i<=n;i++)root[i]=update(1,n,a[i].se,a[i].fi,root[i-1]);
    cin >> m ;
    while(m--)
    {
        cin >> l >> r ;
        cout << qans(l,r) << '\n' ;
    }

}
