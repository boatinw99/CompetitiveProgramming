#include<bits/stdc++.h>
using namespace std ;
#define mid (l+r>>1)
const int N = 1e5+9 , LOG = log2(N)+1; 
vector<int> V ;
int n ;
struct T
{
    bool adj ;
    int numl,numr,ans; 
}st[N*LOG*4];
int hi[N],L[N*LOG*4],R[N*LOG*4],root[N],idx=1;
T operate(T a,T b)
{
    T t ; 
    t.ans=max(a.ans,max(b.ans,a.numr+b.numl));
    t.adj = min(a.adj,b.adj);
    t.numl = a.numl+b.numl*a.adj;   
    t.numr = b.numr+a.numr*b.adj;
    return t ;
}
void construct(int l,int r,int m)
{
    if(l==r)
    {
        st[m]={0,0,0,0};
        return ; 
    }
    L[m]=++idx,R[m]=++idx;
    construct(l,mid,L[m]);
    construct(mid+1,r,R[m]);
    st[m]={0,0,0,0};
}
int update(int l,int r,int x,int m)
{
    if(r<x||l>x)return m ;
    int tmp = ++idx ;
    if(l==r)
    {
        st[tmp] = {1,1,1,1};
        return tmp ; 
    }
    L[tmp]=update(l,mid,x,L[m]);
    R[tmp]=update(mid+1,r,x,R[m]);
    st[tmp] = operate(st[L[tmp]],st[R[tmp]]);
    return tmp ; 
}
T getmx(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return {0,0,0,0};
    if(l>=x&&r<=y)return st[m];
    return operate(getmx(l,mid,x,y,L[m]),getmx(mid+1,r,x,y,R[m]));
}
int compute(int x,int y,int w)
{
    int l=0,r=n ;
    while(l+1<r)
    {
        if(getmx(1,n,x,y,root[mid]).ans>=w)l=mid ;
        else r=mid ;
    }
    //printf("wtf x=%d y=%d w=%d ans=%d\n",x,y,w,l);
    return hi[V[l]] ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int m ;
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        V.emplace_back(i);
        cin >> hi[i] ;
    }
    sort(V.begin(),V.end(),[&](int lhs,int rhs){
        return hi[lhs]<hi[rhs];
    });
    root[n]=1;
    construct(1,n,1);
    for(int i=V.size()-1;i>=0;i--)
    {
        ///it = idx
        root[i]=update(1,n,V[i],root[i+1]);
    }
    cin >> m ;
    for(int i=1,l,r,w ;i<=m;i++)
    {
        cin >> l >> r >> w ;
        cout << compute(l,r,w) << '\n' ;
    }
    return 0 ; 
}