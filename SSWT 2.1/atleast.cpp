#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
typedef long long ll ;
#define fi first
#define se second
#define mid (l+r>>1)
const int N = 1e5+9 , LOG =log2(N)+1;
struct T
{
    ll sum ;
    int cnt;
};
T st[N*LOG*2];
ll qs[N],a[N];
int L[N*LOG*2],R[N*LOG*2],pos[N],id=1,root[N],n;
vector<pii> cc ;
void construct(int l,int r,int m)
{
    if(l==r)return ;
    L[m]=++id,R[m]=++id;
    construct(l,mid,L[m]),construct(mid+1,r,R[m]);
}
int update(int l,int r,int x,int cst,int m)
{
    if(r<x||l>x)return m ;
    int tmp=++id;
    if(l==r)
    {
        st[tmp]={st[m].sum+cst,st[m].cnt+1};
        return tmp ;
    }
    L[tmp]=update(l,mid,x,cst,L[m]),R[tmp]=update(mid+1,r,x,cst,R[m]);
    st[tmp]={st[L[tmp]].sum+st[R[tmp]].sum,st[L[tmp]].cnt+st[R[tmp]].cnt};
    return tmp ;
}
ll query(int l,int r,int cst,int m1,int m2)
{
    if(st[m1].cnt-st[m2].cnt==cst)return st[m1].sum-st[m2].sum;
    int tmp1=st[L[m1]].cnt-st[L[m2]].cnt;
    if(tmp1>=cst)return  query(l,mid,cst,L[m1],L[m2]);
    else return st[L[m1]].sum-st[L[m2]].sum+query(mid+1,r,cst-tmp1,R[m1],R[m2]);
}
int qans(int l,int r,double avg)
{
    int range=r-l+1;
    ll sumr=qs[r]-qs[l-1];
    if(1.0*sumr/range>=avg)return 0 ;
    int l1=0,r1=range+1;
    while(l1+1<r1)
    {
        int mid1=(l1+r1)>>1;
        ll tmp = query(1,n,mid1,root[r],root[l-1]);
        if(1.0*(sumr-tmp)/(range-mid1)<avg)l1=mid1;
        else r1=mid1;
    }
    if(r1==range&&avg<=0)return range;
    else if(r1==range)return -1;
    return r1;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int m,i,j,l,r ;
    double cst ;
    cin >> n >> m;
    for(i=1;i<=n;i++)
    {
        cin >> a[i] ;
        qs[i]=qs[i-1]+a[i];
        cc.push_back({a[i],i});
    }
    sort(cc.begin(),cc.end());
    for(i=0;i<n;i++)pos[cc[i].se]=i+1;
    root[0]=1;
    construct(1,n,1);
    for(i=1;i<=n;i++)root[i]=update(1,n,pos[i],a[i],root[i-1]);
    while(m--)
    {
        cin >> l >> r >> cst ;
        cout << qans(l,r,cst) << '\n' ;
    }
}
