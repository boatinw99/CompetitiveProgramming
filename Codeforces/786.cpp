#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 , LOG=log2(N)+1;
int st[N*LOG*4],L[N*LOG*4],R[N*LOG*4],root[N];
int lval[N],a[N],n,id=1;
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
        st[tmp]=st[m]+cst;
        return tmp ;
    }
    L[tmp]=update(l,mid,x,cst,L[m]);
    R[tmp]=update(mid+1,r,x,cst,R[m]);
    st[tmp]=st[L[tmp]]+st[R[tmp]];
    return tmp;
}
int findmax(int l,int r,int k,int m)
{
    if(l==r)return l ;
    int mid=l+r>>1;
    if(st[R[m]]>=k)return findmax(mid+1,r,k,R[m]);
    else return findmax(l,mid,k-st[R[m]],L[m]);
}
int qans(int k)
{
    int ans = 0 , r=n ;
    while(r>=1)
    {
        r=findmax(0,n,k+1,root[r]);
        ans++;
    }
    return ans;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j,m,x ;
    cin >> n ;
    root[0]=1;
    construct(0,n,1);
    for(i=1;i<=n;i++)
    {
        cin >> x ;
        if(lval[x]>0)root[i]=update(0,n,lval[x],-1,root[i-1]);
        else root[i]=root[i-1];
        lval[x]=i ;
        root[i]=update(0,n,lval[x],1,root[i]);
    }
    for(i=1;i<=n;i++)cout << qans(i) << " " ;
}
