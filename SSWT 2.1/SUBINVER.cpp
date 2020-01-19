#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 3e5+9,LOG=log2(N)+1;
const ll pb = 98765431 ;
ll st[N*LOG*8],pi[N],qs[N];
bool lazy[N*LOG*8];
int L[N*LOG*8],R[N*LOG*8],root[N],n,id=1,mx=0;
void construct(int l,int r,int m)
{
    if(l==r)return ;
    L[m]=++id,R[m]=++id;
    int mid=l+r>>1;
    construct(l,mid,L[m]),construct(mid+1,r,R[m]);
}
void uplz(int l,int r,int m)
{
    if(lazy[m])
    {
        st[m]=qs[r-l]-st[m];
        if(l<r)
        {
            int tl=L[m],tr=R[m];
            L[m]=++id,R[m]=++id;
            lazy[L[m]]=lazy[tl]^1;
            lazy[R[m]]=lazy[tr]^1;
            st[L[m]]=st[tl],st[R[m]]=st[tr];
            L[L[m]]=L[tl],R[L[m]]=R[tl];
            L[R[m]]=L[tr],R[R[m]]=R[tr];
        }
        lazy[m]=0;
    }
}
int update(int l,int r,int x,int y,int m)
{
    uplz(l,r,m);
    if(r<x||l>y)return m;
    int tmp=++id,mid=l+r>>1;
    if(l>=x&&r<=y)
    {
        st[tmp]=qs[r-l]-st[m];
        if(l<r)
        {
            int tl=L[m],tr=R[m];
            L[tmp]=++id,R[tmp]=++id;
            lazy[L[tmp]]=lazy[tl]^1;
            lazy[R[tmp]]=lazy[tr]^1;
            st[L[tmp]]=st[tl],st[R[tmp]]=st[tr];
            L[L[tmp]]=L[tl],R[L[tmp]]=R[tl];
            L[R[tmp]]=L[tr],R[R[tmp]]=R[tr];
        }
        return tmp ;
    }
    L[tmp]=update(l,mid,x,y,L[m]);
    R[tmp]=update(mid+1,r,x,y,R[m]);
    st[tmp]=st[L[tmp]]*pi[r-mid]+st[R[tmp]];
    return tmp ;
}
bool cpr(int l,int r,int m1,int m2)
{
    uplz(l,r,m1),uplz(l,r,m2);
    if(l==r)return st[m1]<st[m2]; ///old | new
    int mid=l+r>>1;
    uplz(l,mid,L[m1]),uplz(mid+1,r,R[m1]);
    uplz(l,mid,L[m2]),uplz(mid+1,r,R[m2]);
    if(st[L[m1]]!=st[L[m2]])return cpr(l,mid,L[m1],L[m2]);
    else return cpr(mid+1,r,R[m1],R[m2]);
}
void qval(int l,int r,int m)
{
    uplz(l,r,m);
    if(l==r)
    {
        cout << st[m];
        return ;
    }
    int mid=l+r>>1;
    qval(l,mid,L[m]),qval(mid+1,r,R[m]);
}
main()
{
    int i,j,m,l,r ;
    pi[0]=1,qs[0]=1;
    for(i=1;i<N;i++)
    {
        pi[i]=pi[i-1]*pb;
        qs[i]=pi[i]+qs[i-1];
    }
    cin >> n >> m ;
    root[0]=1;
    construct(1,n,1);
    for(i=1;i<=m;i++)
    {
        cin >> l >> r ;
        root[i]=update(1,n,l,r,root[i-1]);
        if(cpr(1,n,root[mx],root[i]))mx=i;
    }
    qval(1,n,root[mx]) ;
}
