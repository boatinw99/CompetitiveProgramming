#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define mid (l+r>>1)
const int N = 1e5+9 , MIN = -1e9;
ll qs[N],a[N];
int st[N<<2],dp[N];
vector<ll> cc ;
void construct(int l,int r,int m)
{
    if(l==r)
    {
        st[m]=MIN;
        return ;
    }
    construct(l,mid,m<<1);
    construct(mid+1,r,m<<1|1);
    st[m]=MIN;
}
void update(int l,int r,int x,int cst,int m)
{
    if(r<x||l>x)return ;
    if(l==r)
    {
        st[m]=max(st[m],cst);
        return ;
    }
    update(l,mid,x,cst,m<<1);
    update(mid+1,r,x,cst,m<<1|1);
    st[m]=max(st[m<<1],st[m<<1|1]);
}
int findmax(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return MIN ;
    if(l>=x&&r<=y)return st[m];
    return max(findmax(l,mid,x,y,m<<1),findmax(mid+1,r,x,y,m<<1|1));
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j ;
    cin >> n ;
    for(i=1;i<=n;i++)
    {
        cin >> a[i] ;
        qs[i]=qs[i-1]+a[i];
        cc.push_back(qs[i]);
    }
    cc.push_back(0);
    sort(cc.begin(),cc.end());
    cc.resize(unique(cc.begin(),cc.end())-cc.begin());
    int m = cc.size();
    construct(1,m,1);
    auto it=lower_bound(cc.begin(),cc.end(),0)-cc.begin()+1;
    update(1,m,it,0,1);
    for(i=1;i<=n;i++)
    {
        auto it = lower_bound(cc.begin(),cc.end(),qs[i])-cc.begin()+1;
        int ret = findmax(1,m,1,it-1,1);
        ret++;
        if(ret>0)
        {
            dp[i]=ret;
            update(1,m,it,ret,1);
        }
        //printf("aa %d \n",dp[i]);
    }
    cout << dp[n];
}
