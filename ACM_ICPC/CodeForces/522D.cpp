#include<bits/stdc++.h>
using namespace std ;
#define mid (l+r>>1)
const int N = 5e5+9 , LOG=log2(N)+1 ; 
map<int,int> mp ; 
int root[N],n,st[N*LOG*2],L[N*LOG*2],R[N*LOG*2],idx=1;
void construct(int m=1,int l=1,int r=n)
{
    if(l==r)return ; 
    L[m]=++idx;
    R[m]=++idx;
    construct(L[m],l,mid);
    construct(R[m],mid+1,r);
}
int update(int m,int x,int val,int l=1,int r=n)
{
    if(r<x||l>x)return m ;
    int tmp = ++idx ; 
    if(l==r)
    {
        st[tmp]=max(st[m],val);
        return tmp ; 
    }
    L[tmp]=update(L[m],x,val,l,mid);
    R[tmp]=update(R[m],x,val,mid+1,r);
    st[tmp]=max(st[L[tmp]],st[R[tmp]]);
    return tmp ; 
}
int getmin(int x,int m,int l=1,int r=n)
{
    if(l==r)
    {
        if(st[m]>=x)return l;
        else return -1 ;
    }
    if(st[L[m]]>=x)return getmin(x,L[m],l,mid);
    else return getmin(x,R[m],mid+1,r);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int m ;
    cin >> n >> m ;
    root[0]=1;
    construct();
    for(int i=1;i<=n;i++)
    { 
        int ai; 
        cin >> ai ;
        root[i]=update(root[i-1],i-mp[ai],mp[ai]);
        mp[ai]=i;
    }
    for(int i=1,l,r ;i<=m;i++)
    {
        cin >> l >> r ;
        cout << getmin(l,root[r]) << '\n' ;
    }
    return 0 ;
}