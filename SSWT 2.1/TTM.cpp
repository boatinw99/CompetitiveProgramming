#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 2e5+9,LOG=log2(N)+1 ;
ll st[N*LOG*4],lazy[N*LOG*4];
int L[N*LOG*4],R[N*LOG*4],root[N],a[N];
int n,id=1;
void construct(int l,int r,int m)
{
    if(l==r)
    {
        st[m]=a[l];
        return ;
    }
    L[m]=++id,R[m]=++id;
    int mid=l+r>>1;
    construct(l,mid,L[m]),construct(mid+1,r,R[m]);
    st[m]=st[L[m]]+st[R[m]];
}
void uplazy(int l,int r,int m)
{
    if(lazy[m])
    {
        st[m]+=lazy[m]*(r-l+1);
        if(l<r)
        {
            int tmpl=L[m],tmpr=R[m];
            L[m]=++id,R[m]=++id;
            lazy[L[m]]=lazy[tmpl]+lazy[m];
            lazy[R[m]]=lazy[tmpr]+lazy[m];
            L[L[m]]=L[tmpl],R[L[m]]=R[tmpl];
            L[R[m]]=L[tmpr],R[R[m]]=R[tmpr];
            st[L[m]]=st[tmpl],st[R[m]]=st[tmpr];
        }
        lazy[m]=0;
    }
}
int update(int l,int r,int x,int y,int cst,int m)
{
    uplazy(l,r,m);
    if(r<x||l>y)return m ;
    int tmp=++id,mid=l+r>>1;
    if(l>=x&&r<=y)
    {
        st[tmp]=st[m]+1ll*(r-l+1)*cst;
        if(l<r)
        {
            int tmpl=L[m],tmpr=R[m];
            L[tmp]=++id,R[tmp]=++id;
            lazy[L[tmp]]=lazy[tmpl]+cst;
            lazy[R[tmp]]=lazy[tmpr]+cst;
            L[L[tmp]]=L[tmpl],R[L[tmp]]=R[tmpl];
            L[R[tmp]]=L[tmpr],R[R[tmp]]=R[tmpr];
            st[L[tmp]]=st[tmpl],st[R[tmp]]=st[tmpr];
        }
        return tmp ;
    }
    L[tmp]=update(l,mid,x,y,cst,L[m]);
    R[tmp]=update(mid+1,r,x,y,cst,R[m]);
    st[tmp]=st[L[tmp]]+st[R[tmp]];
    return tmp ;
}
ll findsum(int l,int r,int x,int y,int m)
{
    uplazy(l,r,m);
    if(r<x||l>y)return 0 ;
    if(l>=x&&r<=y)return st[m];
    int mid=l+r>>1;
    return findsum(l,mid,x,y,L[m])+findsum(mid+1,r,x,y,R[m]);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j,m,l,r,x ;
    char c ;
    cin >> n >> m ;
    for(i=1;i<=n;i++)cin >> a[i];
    root[0]=1;
    construct(1,n,1);
    i=1;
    while(m--)
    {
        cin >> c ;
        if(c=='B')
        {
            cin >> x ;
            i=x+1;
        }
        else if(c=='Q')
        {
            cin >> l >> r ;
            cout << findsum(1,n,l,r,root[i-1]) << '\n';
        }
        else if(c=='H')
        {
            cin >> l >> r >> x ;
            cout << findsum(1,n,l,r,root[x]) << '\n' ;
        }
        else
        {
            cin >> l >> r >> x ;
            root[i]=update(1,n,l,r,x,root[i-1]);
            i++;
        }
    }
}
