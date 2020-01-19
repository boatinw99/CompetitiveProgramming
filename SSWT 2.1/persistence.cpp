#include<bits/stdc++.h>
using namespace std ;
int a[6]={0,1,2,3,4,5},n=5;
int st[100],L[100],R[100],root[100];
int kp=1 ;
void construct(int l,int r,int m)
{
    if(l==r)
    {
        st[m]=a[l];
        return ;
    }
    int mid=l+r>>1;
    L[m]=++kp;
    R[m]=++kp;
    construct(l,mid,L[m]),construct(mid+1,r,R[m]);
    st[m]=st[L[m]]+st[R[m]];
}
int update(int l,int r,int x,int cst,int m)
{
    int M=++kp,mid=l+r>>1 ;
    if(l==r)
    {
        st[M]=cst ;
        return M ;
    }
    L[M]=L[m],R[M]=R[m];
    if(mid<x)R[M]=update(mid+1,r,x,cst,R[m]);
    else L[M]=update(l,mid,x,cst,L[m]);
    st[M]=st[L[M]]+st[R[M]];
    return M ;
}
int getsum(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return 0 ;
    if(l>=x&&r<=y)return st[m];
    int mid=l+r>>1;
    return getsum(l,mid,x,y,L[m])+getsum(mid+1,r,x,y,R[m]);
}
main()
{
    construct(1,n,1);
    root[0]=1;
    root[1]=update(1,n,5,1,root[0]);
    while(1)
    {
        int x , y ;
        cin >> x >> y ;
        cout << getsum(1,n,x,y,root[1]) <<'\n';
    }
}
