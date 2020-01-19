#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 ;
#define fi first
#define se second
#define mid (l+r>>1)
struct tree
{
    int mxl,mxr,ans,sum ;
};
int a[N];
multiset<int> mt ;
tree st[N*4];
tree operate(tree t1,tree t2)
{
    tree t ;
    t.mxl=max(t1.mxl,t1.sum+t2.mxl);
    t.mxr=max(t2.mxr,t2.sum+t1.mxr);
    t.sum=t1.sum+t2.sum;
    t.ans=max(t1.ans,t2.ans);
    t.ans=max(t.ans,t.sum);
    t.ans=max(t.ans,max(t.mxr,t.mxl));
    t.ans=max(t.ans,t1.mxr+t2.mxl);
    return t ;
}
void construct(int l,int r,int m)
{
    if(l==r)
    {
        int tmp = max(a[l],0);
        st[m]={tmp,tmp,tmp,a[l]};
        return ;
    }
    construct(l,mid,m<<1);
    construct(mid+1,r,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}
void update(int l,int r,int x,int m)
{
    if(r<x||l>x)return ;
    if(l==r)
    {
        int tmp =max(a[l],0);
        st[m]={tmp,tmp,tmp,a[l]};
        return ;
    }
    update(l,mid,x,m<<1);
    update(mid+1,r,x,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}
main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,i,j,x,cst ;
    cin >> n >> m ;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        mt.insert(a[i]);
    }
    construct(1,n,1);
    cout << (st[1].ans==0?*mt.rbegin():st[1].ans) << '\n' ;
    while(m--)
    {
        cin >> x >> cst ;
        x++;
        auto it=mt.find(a[x]);
        mt.erase(it);
        a[x]=cst;
        mt.insert(cst);
        update(1,n,x,1);
        cout << (st[1].ans==0?*mt.rbegin():st[1].ans) << '\n' ;
    }

}
