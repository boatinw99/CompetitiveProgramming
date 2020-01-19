#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+9 ,LOG = log2(N)+1 ;
#define mid (l+r>>1)
int pos[N],a[N],st[N<<2],ans[N],up[N][LOG],p[N];
void construct(int l,int r,int m)
{
    if(l==r)
    {
        st[m]=ans[l];
        return ;
    }
    construct(l,mid,m<<1);
    construct(mid+1,r,m<<1|1);
    st[m]=max(st[m<<1],st[m<<1|1]);
}
int getmax(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return 0 ;
    if(l>=x&&r<=y)return st[m];
    return max(getmax(l,mid,x,y,m<<1),getmax(mid+1,r,x,y,m<<1|1));
}
int blift(int u,int cst)
{
    int x = u ;
    for(int i=0;i<LOG;i++)
    {
        if((1<<i)&cst)u=up[u][i] ;
    }
    ans[x]=u ;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,q,i,j,x,l,r ;
    cin >> n >> m >> q ;
    for(i=1;i<=n;i++)
    {
        cin >> x ;
        pos[x]=i ;
        a[i]=x;
    }
    for(i=1;i<=m;i++)
    {
        cin >> x ;
        if(pos[x]-1==0)up[i][0]=a[n];
        else up[i][0]=a[pos[x]-1];
        up[i][0]=p[up[i][0]];
        p[x]=i ;
        //printf("aa %d %d | %d \n",i,up[i][0],pos[x]);
        for(int j=1;j<LOG;j++)up[i][j]=up[up[i][j-1]][j-1];
        blift(i,n-1);
    }
    construct(1,m,1);
    while(q--)
    {
        cin >> l >> r ;
        int mx = getmax(1,m,l,r,1);
        cout << (mx>=l?"1":"0")  ;
    }

}
