#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second
const int N = 1e5+9 ,LOG = log2(N)+1;
struct T
{
    int num ;
    ll sum ;
};
T st[N*LOG*2];
int a[N],L[N*LOG*2],R[N*LOG*2],id=1,root[N];
ll qs[N];
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
        st[tmp]={1,x};
        return tmp ;
    }
    L[tmp]=update(l,mid,x,L[m]);
    R[tmp]=update(mid+1,r,x,R[m]);
    st[tmp]={st[L[tmp]].num+st[R[tmp]].num,st[L[tmp]].sum+st[R[tmp]].sum};
    return tmp ;
}
ll walk(int l,int r,int k,int m1,int m2) ///findsum , kth smallest
{
    if(l==r)return st[m2].sum ;
    if(st[L[m2]].num-st[L[m1]].num>=k)return walk(l,mid,k,L[m1],L[m2]);
    else return walk(mid+1,r,k-st[L[m2]].num+st[L[m1]].num,R[m1],R[m2])
        +st[L[m2]].sum-st[L[m1]].sum;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,X,i,j,u,v ;
    cin >> n >> m >> X ;
    root[0]=1;
    construct(1,n,1);
    for(i=1;i<=n;i++)
    {
        cin >> a[i] ;
        qs[i]=qs[i-1]+a[i];
        root[i]=update(1,n,a[i],root[i-1]);
    }
    int lans=0 ;
    while(m--)
    {
        cin >> u >> v ;
        if(X)u^=lans,v^=lans;
        //printf("aa %lld \n",qs[v]-qs[u-1]);
        lans=qs[v]-qs[u-1]-2*walk(1,n,v-u+1>>1,root[u-1],root[v]) ;
        cout << lans << '\n' ;
    }
}
