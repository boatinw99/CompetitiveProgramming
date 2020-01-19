#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N = 1e5+9,LOG=log2(N)+1 ;
vector<pii> v ;
int n,id=1,a[N],pos[N];
int st[N*LOG*2],L[N*LOG*2],R[N*LOG*2],root[N];
void construct(int l,int r,int m)
{
    if(l==r)return ;
    L[m]=++id,R[m]=++id ;
    int mid=l+r>>1;
    construct(l,mid,L[m]),construct(mid+1,r,R[m]);
}
int update(int l,int r,int x,int m)
{
    int tmp=++id,mid=l+r>>1;
    if(l==r)
    {
        st[tmp]=1;
        return tmp;
    }
    L[tmp]=L[m],R[tmp]=R[m];
    if(x<=mid)L[tmp]=update(l,mid,x,L[m]);
    else R[tmp]=update(mid+1,r,x,R[m]);
    st[tmp]=st[L[tmp]]+st[R[tmp]];
    return tmp ;
}
int query(int l,int r,int k,int m1,int m2)
{
    int mid=l+r>>1;
    if(l==r)return l ;
    int tmp=st[L[m2]]-st[L[m1]];
    if(tmp>=k)return query(l,mid,k,L[m1],L[m2]);
    else return query(mid+1,r,k-tmp,R[m1],R[m2]);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int m,i,j,x,y,l,r,k ;
    cin >> n >> m ;
    for(i=1;i<=n;i++)
    {
        cin >> a[i] ;
        v.push_back({a[i],i});
    }
    sort(v.begin(),v.end());
    i=1;
    root[0]=1;
    construct(1,n,1);
    for(auto it:v)pos[it.se]=i++;
    for(i=1;i<=n;i++)root[i]=update(1,n,pos[i],root[i-1]);
    while(m--)
    {
        cin >> l >> r >> k ;
        cout << v[query(1,n,k,root[l-1],root[r])-1].fi << '\n';
    }
}
