#include<bits/stdc++.h>
using namespace std ;
#define mid (l+r>>1)
const int N = 1e5+9,LOG=log2(N)+1;
int pos[N],a[N],st[N*LOG*4],L[N*LOG*4],R[N*LOG*4],root[N],id=1;
void construct(int l,int r,int m)
{
    if(l==r)return ;
    L[m]=++id,R[m]=++id ;
    construct(l,mid,L[m]);
    construct(mid+1,r,R[m]);
}
int update(int l,int r,int x,int m)
{
    if(r<x||l>x)return m ;
    int tmp = ++id ;
    if(l==r)
    {
        st[tmp]++;
        return tmp ;
    }
    L[tmp]=update(l,mid,x,L[m]);
    R[tmp]=update(mid+1,r,x,R[m]);
    st[tmp]=st[L[tmp]]+st[R[tmp]] ;
    return tmp ;
}
int getsum(int l,int r,int x,int y,int m)
{
    if(r<x||l>y||x>y)return 0 ;
    if(l>=x&&r<=y)return st[m];
    return getsum(l,mid,x,y,L[m])+getsum(mid+1,r,x,y,R[m]);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j ;
    long long ans=0 ;
    cin >> n ;
    for(i=1;i<=n;i++)
    {
        cin >> a[i] ;
        pos[a[i]]=i ;
    }
    root[0]=1;
    construct(1,n,1);
    for(i=1;i<=n;i++)
    {
        root[i]=update(1,n,pos[i],root[i-1]);
    }
    for(i=1;i<=n;i++)
    {
        int di ;
        cin >> di ;
        int L=max(i-di,1);
        int R=min(di+i,n);
        int len ;
        len = R-i ;
        if(len>0)
        {
            ans+=getsum(1,n,i+1,R,root[a[i]]);
        }
        len=i-L;
        if(len>0)
        {
            int tmp = len - getsum(1,n,L,i-1,root[a[i]]);
            ans+=tmp;
        }
    }
    cout << ans ;
}
