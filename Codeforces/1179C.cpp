#include<bits/stdc++.h>
using namespace std ;
#define mid (l+r>>1)
const int N = 3e5+9 , M = 1e6+9 ; 
multiset<int> S;
int st[M<<2],lazy[M<<2],A[N],B[N];
void push(int l,int r,int m)
{
    if(!lazy[m])return ;
    st[m]+=lazy[m];
    if(l<r)
    {
        lazy[m<<1]+=lazy[m];
        lazy[m<<1|1]+=lazy[m];
    }
    lazy[m]=0;
}
void update(int l,int r,int x,int y,int cst,int m)
{
    push(l,r,m);
    if(r<x||l>y)return ;
    if(l>=x&&r<=y)
    {
        lazy[m]+=cst;
        push(l,r,m);
        return ;
    }
    update(l,mid,x,y,cst,m<<1);
    update(mid+1,r,x,y,cst,m<<1|1);
    st[m]=max(st[m<<1],st[m<<1|1]);
}
int getmax(int l,int r,int m)
{
    push(l,r,m);
    if(l==r)return l ;
    push(l,mid,m<<1);
    push(mid+1,r,m<<1|1);
    if(st[m<<1|1]>0)return getmax(mid+1,r,m<<1|1);
    else return getmax(l,mid,m<<1); 
}
void updatedish(int x,int cst)
{
    if(cst==1)S.insert(x);
    else 
    {
        auto it = S.find(x);
        S.erase(it);
    }
    update(0,M,0,x,cst,1);
}
void updatepupil(int x,int cst)
{
    update(0,M,0,x,cst*-1,1);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,q ; 
    cin >> n >> m ;
    for(int i=1;i<=n;i++)
    {
        cin >> A[i];
        updatedish(A[i],1);
    }
    for(int i=1;i<=m;i++)
    {
        cin >> B[i];
        updatepupil(B[i],1);
    }
    cin >> q ;
    for(int i=1,typ,u,v ;i<=q;i++)
    {
        cin >> typ >> u >> v ; 
        if(typ==1)
        {
            updatedish(A[u],-1);
            A[u]=v;
            updatedish(A[u],1);
        }
        else 
        {
            updatepupil(B[u],-1);
            B[u]=v;
            updatepupil(B[u],1);
        }
        int ans = getmax(0,M,1);
        cout << (ans?*prev(S.upper_bound(ans)):-1) << '\n';
    }
    return 0 ;
}