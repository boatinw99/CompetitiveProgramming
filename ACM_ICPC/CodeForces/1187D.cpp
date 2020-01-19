#include<bits/stdc++.h>
using namespace std ;
#define mid (l+r>>1)
const int N = 3e5+9 , inf = 1e9 ;
vector<int> V[N];
int A[N],B[N],cnt[N],ptr[N],st[N<<2],n ;
void construct(int l,int r,int m)
{
    if(l==r)
    {
        st[m]=A[l];
        return ;
    }
    construct(l,mid,m<<1);
    construct(mid+1,r,m<<1|1);
    st[m]=min(st[m<<1],st[m<<1|1]);
}
void update(int l,int r,int x,int y,int m)
{
    if(r<x||l>x)return ;
    if(l==r)
    {
        st[m]=y; 
        return ;
    }
    update(l,mid,x,y,m<<1);
    update(mid+1,r,x,y,m<<1|1);
    st[m]=min(st[m<<1],st[m<<1|1]);
}
int getmin(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return inf ;
    if(l>=x&&r<=y)return st[m];
    return min(getmin(l,mid,x,y,m<<1),getmin(mid+1,r,x,y,m<<1|1));
}
void init()
{
    for(int j=0;j<=n;j++)
    {
        V[j].clear();
        ptr[j]=0;
    }
}
int solve()
{
    for(int j=1;j<=n;j++)
    {
        if(ptr[B[j]]==V[B[j]].size())return 0 ;
        int x = V[B[j]][ptr[B[j]]];
        ptr[B[j]]++;
        int ret = getmin(1,n,1,x,1);
        //printf("aa %d %d %d\n",j,x,ret);
        if(ret<B[j])
        {
            return 0 ;
        }
        update(1,n,x,inf,1);
    }
    return 1 ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int q ;
    cin >> q ; 
    while(q--)
    {
        cin >> n ;
        init();
        for(int i=1;i<=n;i++)cin >> A[i] ;
        for(int i=1;i<=n;i++)cin >> B[i] ;
        for(int i=1;i<=n;i++)
        {
            V[A[i]].push_back(i);
        }
        construct(1,n,1);
        cout << (solve()==1?"YES":"NO") << '\n' ;
    }
    return 0 ;
}