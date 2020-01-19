#include<bits/stdc++.h>
using namespace std ;
const int N = 35009 ;
int n,last[N];
int dp[51][N],a[N],lval[N];
int st[N*4],lazy[N*4];
bool visited[N];
void re()
{
    memset(st,0,sizeof st);
    memset(lazy,0,sizeof lazy);
    memset(lval,0,sizeof lval);
}
void construct(int l,int r,int m,int i)
{
    if(l==r)
    {
        st[m]=dp[i][l];
        return ;
    }
    int mid=l+r>>1;
    construct(l,mid,m<<1,i),construct(mid+1,r,m<<1|1,i);
    st[m]=max(st[m<<1],st[m<<1|1]);
}
void uplazy(int l,int r,int m)
{
    if(lazy[m])
    {
        st[m]+=lazy[m];
        if(l<r)
        {
            lazy[m<<1]+=lazy[m];
            lazy[m<<1|1]+=lazy[m];
        }
        lazy[m]=0;
    }
}
void update(int l,int r,int x,int y,int m)
{
    uplazy(l,r,m);
    if(r<x||l>y)return ;
    if(l>=x&&r<=y)
    {
        st[m]++;
        if(l<r)
        {
            lazy[m<<1]++;
            lazy[m<<1|1]++;
        }
        return ;
    }
    int mid=l+r>>1;
    update(l,mid,x,y,m<<1),update(mid+1,r,x,y,m<<1|1);
    st[m]=max(st[m<<1],st[m<<1|1]);
}
int findmax(int l,int r,int x,int y,int m)
{
    uplazy(l,r,m);
    if(r<x||l>y)return 0 ;
    if(l>=x&&r<=y)return st[m];
    int mid=l+r>>1;
    return max(findmax(l,mid,x,y,m<<1),findmax(mid+1,r,x,y,m<<1|1));
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int k,i,j ;
    cin >> n >> k ;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        dp[1][i]=dp[1][i-1]+!visited[a[i]];
        visited[a[i]]++;
    }
    for(i=2;i<=k;i++)
    {
        re();
        construct(0,n,1,i-1);
        for(j=1;j<=n;j++)
        {
            int l=lval[a[j]];
            update(0,n,l,j-1,1);
            dp[i][j]=findmax(0,n,0,j-1,1);
            lval[a[j]]=j;
        }
    }
    cout << dp[k][n];
}
