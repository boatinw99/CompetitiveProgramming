#include<bits/stdc++.h>
using namespace std ;
#define mid (l+r>>1)
#define fi first
#define se second
const int N = 5e4+9,LOG=log2(N)+1 ;
map<int,int> mp ;
int st[N*LOG*4],L[N*LOG*4],R[N*LOG*4],id=1,root[N];
void construct(int l,int r,int m)
{
    if(l==r)return ;
    L[m]=++id,R[m]=++id;
    construct(l,mid,L[m]),construct(mid+1,r,R[m]);
}
int update(int l,int r,int x,int cst,int m)
{
    if(r<x||l>x)return m ;
    int tmp=++id ;
    if(l==r)
    {
        st[tmp]=st[m]+cst;
        return tmp ;
    }
    L[tmp]=update(l,mid,x,cst,L[m]),R[tmp]=update(mid+1,r,x,cst,R[m]);
    st[tmp]=st[L[tmp]]+st[R[tmp]];
    return tmp ;
}
int findsum(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return 0;
    if(l>=x&&r<=y)return st[m];
    return findsum(l,mid,x,y,L[m])+findsum(mid+1,r,x,y,R[m]);
}
main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n,i,j,x,m,y ;
    cin >> n ;
    root[0]=1;
    construct(1,n,1);
    for(i=1;i<=n;i++)
    {
        cin >> x ;
        root[i]=root[i-1];
        if(mp.count(x))root[i]=update(1,n,mp[x],-1,root[i]);
        root[i]=update(1,n,i,1,root[i]);
        mp[x]=i;
    }
    cin >> m ;
    while(m--)
    {
        cin >> x >> y;
        x++;
        y++;
        cout << (y-x+1)-findsum(1,n,x,y,root[y]) << '\n' ;
    }
}
