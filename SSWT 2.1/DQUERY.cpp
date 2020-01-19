#include<bits/stdc++.h>
using namespace std ;
const int N =3e4+9 , LOG=log2(N)+1 ,K=1e6+9 ;
int st[N*LOG*2+N*4],L[N*LOG*2+N*4],R[N*LOG*2+N*4],root[N*2];
int val[K],n,id=1;
void construct(int l,int r,int m)
{
    if(l==r)return ;
    L[m]=++id,R[m]=++id;
    int mid=l+r>>1;
    construct(l,mid,L[m]),construct(mid+1,r,R[m]);
}
int update(int l,int r,int x,int cst,int m)
{
    int tmp=++id,mid=l+r>>1;
    if(l==r)
    {
        st[tmp]=st[m]+cst;
        return tmp ;
    }
    L[tmp]=L[m],R[tmp]=R[m];
    if(x<=mid)L[tmp]=update(l,mid,x,cst,L[m]);
    else R[tmp]=update(mid+1,r,x,cst,R[m]);
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
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j,x,l,r,m ;
    cin >> n ;
    root[0]=1;
    construct(1,n,1);
    for(i=1;i<=n;i++)
    {
        cin >> x ;
        if(!val[x])root[i]=root[i-1];
        else root[i]=update(1,n,val[x],-1,root[i-1]);
        val[x]=i;
        root[i]=update(1,n,val[x],1,root[i]);
    }
    cin >> m ;
    while(m--)
    {
        cin >> l >> r ;
        cout << findsum(1,n,l,r,root[r]) << '\n';
    }
}
