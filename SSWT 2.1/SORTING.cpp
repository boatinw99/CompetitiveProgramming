#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N = 5e5+9,LOG=log2(N)+1;
int st[N*LOG+N*4],L[N*LOG+N*4],R[N*LOG+N*4],root[N];
int a[N],pos[N],n,id=1;
ll ans=0 ;
void construct(int l,int r,int m)
{
    if(l==r)return ;
    L[m]=++id,R[m]=++id;
    int mid=l+r>>1;
    construct(l,mid,L[m]),construct(mid+1,r,R[m]);
}
int update(int l,int r,int x,int m)
{
    int tmp=++id,mid=l+r>>1;
    if(l==r)
    {
        st[tmp]++;
        return tmp ;
    }
    L[tmp]=L[m],R[tmp]=R[m];
    if(x<=mid)L[tmp]=update(l,mid,x,L[m]);
    else R[tmp]=update(mid+1,r,x,R[m]);
    st[tmp]=st[L[tmp]]+st[R[tmp]];
    return tmp ;
}
int findmid(int l,int r,int m1,int m2,int k)
{
    int mid=l+r>>1,tmp=st[L[m2]]-st[L[m1]];
    if(l==r)return l ;
    if(tmp>=k)return findmid(l,mid,L[m1],L[m2],k);
    else return findmid(mid+1,r,R[m1],R[m2],k-tmp);
}
void cntsort(int l,int r)
{
    if(r-l+1<=1)return ;
    int mid=a[findmid(1,n,root[l-1],root[r],r-l+2>>1)];
    ans+=r-l+1;
    cntsort(l,mid-1),cntsort(mid+1,r);
}
main()
{
    int i,j ;
    cin >> n ;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        pos[a[i]]=i ;
    }
    root[0]=1;
    construct(1,n,1);
    for(i=1;i<=n;i++)root[i]=update(1,n,pos[i],root[i-1]);
    cntsort(1,n);
    cout << ans ;
}
