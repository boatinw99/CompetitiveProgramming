#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
#define mid (l+r>>1)
const int N = 2e5+9 ;
int st[N<<2];
pair<int,pii> A[N];
vector<int> cc ;
void update(int l,int r,int x,int cst,int m)
{
    if(r<x||l>x)return ;
    if(l==r)
    {
        st[m]=max(cst,st[m]);
        return ;
    }
    update(l,mid,x,cst,m<<1);
    update(mid+1,r,x,cst,m<<1|1);
    st[m]=max(st[m<<1],st[m<<1|1]);
}
int findmax(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return -1 ;
    if(l>=x&&r<=y)return st[m];
    return max(findmax(l,mid,x,y,m<<1),findmax(mid+1,r,x,y,m<<1|1));
}
main()
{
    int n,i,j,ans=0 ;
    cin >> n ;
    for(i=1;i<=n;i++)
    {
        cin >> A[i].fi >> A[i].se.fi >> A[i].se.se ;
        cc.push_back(A[i].se.fi);
    }
    fill(st,st+N*4-1,-1);
    sort(A+1,A+1+n);
    sort(cc.begin(),cc.end());
    for(i=n;i>=1;i--)
    {
        auto it = lower_bound(cc.begin(),cc.end(),A[i].se.fi)-cc.begin()+1;
        int ret = findmax(1,n,it,n,1);
        if(ret>=A[i].se.se)ans++;
        update(1,n,it,A[i].se.se,1);
    }
    cout << ans;
}
