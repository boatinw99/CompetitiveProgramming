#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 1e5+9,LOG=log2(N)+1;
struct Tree
{
    int sl,sr,mx,cnt;
};
Tree st[N*LOG+N*4];
int L[N*LOG+N*4],R[N*LOG+N*4],root[N],a[N],pos[N];
vector<pii> v;
int n,id=1 ;
void construct(int l,int r,int m)
{
    if(l==r)return ;
    int mid=l+r>>1 ;
    L[m]=++id,R[m]=++id ;
    construct(l,mid,L[m]),construct(mid+1,r,R[m]);
}
Tree operate(Tree t1,Tree t2)
{
    Tree t ;
    t.mx=max(t1.mx,t2.mx);
    if(t1.cnt&&t2.cnt)t={t1.sl+t2.sr,t1.sl+t2.sr,t1.sl+t2.sr,1};
    else if(t1.cnt)t={t1.sr+t2.sl,t2.sr,max(t.mx,t1.sr+t2.sl),0};
    else if(t2.cnt)t={t1.sl,t1.sr+t2.sl,max(t.mx,t1.sr+t2.sl),0};
    else t={t1.sl,t2.sr,max(t.mx,t1.sr+t2.sl),0};
    return t ;
}
int update(int l,int r,int x,int m)
{
    int tmp=++id,mid=l+r>>1;
    if(l==r)
    {
        st[tmp]={1,1,1,1};
        return tmp ;
    }
    L[tmp]=L[m],R[tmp]=R[m];
    if(x<=mid)L[tmp]=update(l,mid,x,L[m]);
    else R[tmp]=update(mid+1,r,x,R[m]);
    st[tmp]=operate(st[L[tmp]],st[R[tmp]]);
    return tmp ;
}
Tree findmax(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return {0,0,0,1};
    if(l>=x&&r<=y)return st[m];
    int mid=l+r>>1;
    return operate(findmax(l,mid,x,y,L[m]),findmax(mid+1,r,x,y,R[m]));
}
int qans(int x,int y,int w)
{
    int l=0,r=n ;
    while(l+1<r)
    {
        int mid=l+r>>1;
        if(findmax(1,n,x,y,root[mid]).mx>=w)r=mid;
        else l=mid ;
    }
    return r ;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j,m,x,y,w ;
    cin >> n ;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        v.push_back({a[i],i});
    }
    root[0]=1;
    construct(1,n,1);
    sort(v.begin(),v.end(),greater<pii>());
    i=1;
    for(auto it:v)
    {
        root[i]=update(1,n,it.se,root[i-1]);
        pos[i++]=it.fi;
    }
    cin >> m ;
    while(m--)
    {
        cin >> x >> y >> w ;
        cout << pos[qans(x,y,w)] << '\n' ;
    }
}
