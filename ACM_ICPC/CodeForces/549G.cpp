#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
#define mid (l+r>>1)
const int N = 2e5+9 ,inf = 2e9 ;
pii st[N<<2];
int lazy[N<<2],arr[N];
vector<int> ans ; 
pii operate(pii a,pii b)
{
    if(a.fi==b.fi)return {a.fi,0};
    else return max(a,b);
}
void push(int l,int r,int m)
{
    if(!lazy[m])return ;
    st[m].fi+=lazy[m];
    if(l<r)
    {
        lazy[m<<1]+=lazy[m];
        lazy[m<<1|1]+=lazy[m];
    }
    lazy[m]=0;
}
void construct(int l,int r,int m)
{
    if(l==r)
    {
        st[m]={arr[l],l};
        return ;
    }
    construct(l,mid,m<<1);
    construct(mid+1,r,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}
void update(int l,int r,int x,int y,int cst,int m)
{
    push(l,r,m);
    if(r<x||l>y)return ;
    if(l>=x&&r<=y)
    {
        lazy[m]+=cst ;
        push(l,r,m);
        return ;
    }
    update(l,mid,x,y,cst,m<<1);
    update(mid+1,r,x,y,cst,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}
pii getmax(int l,int r,int x,int y,int m)
{
    push(l,r,m);
    if(r<x||l>y)return {-inf,0};
    if(l>=x&&r<=y)return st[m];
    return operate(getmax(l,mid,x,y,m<<1),getmax(mid+1,r,x,y,m<<1|1));
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        cin >> arr[i] ;
        arr[i] = arr[i]-n+i;
    }
    construct(1,n,1);
    for(int i=1;i<=n;i++)
    {
        pii mx = st[1];
        //printf("wtf %d %d \n",mx.fi,mx.se);
        if(mx.se<=0)break ; 
        ans.push_back(mx.fi);
        update(1,n,mx.se,mx.se,-inf,1);
        update(1,n,1,n,1,1);
    }
    if(ans.size()<n)
    {
        cout << ":(" << '\n' ;
        return 0 ;
    }
    for(int i=n-1;i>=0;i--)cout << ans[i] << " " ;
    return 0 ;
}