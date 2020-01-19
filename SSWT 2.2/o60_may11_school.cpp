#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second
const int N = 3e5+9 , LOG = log2(N)+1 ;
vector<int> cc ;
vector<pii> a ;
pii q[N];
int n,root[N],L[N*LOG*2],R[N*LOG*2],st[N*LOG*2],idx=1;
void construct(int l,int r,int m)
{
    if(l==r)return ;
    L[m]=++idx,R[m]=++idx;
    construct(l,mid,L[m]);
    construct(mid+1,r,R[m]);
}
int update(int l,int r,int x,int m)
{
    if(r<x||l>x)return m;
    int nw = ++idx ;
    if(l==r)
    {
        st[nw]=st[m]+1;
        return nw;
    }
    L[nw]=update(l,mid,x,L[m]);
    R[nw]=update(mid+1,r,x,R[m]);
    st[nw]=st[L[nw]]+st[R[nw]];
    return nw ;
}
int getsum(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return 0 ;
    if(l>=x&&r<=y)return st[m];
    return getsum(l,mid,x,y,L[m])+getsum(mid+1,r,x,y,R[m]);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int m ;
    cin >> n >> m ;
    for(int i=1,x,y;i<=n;i++)
    {
        cin >> x >> y ;
        a.emplace_back(x,y);
        cc.emplace_back(x);
        cc.emplace_back(y);
    }
    for(int i=1,x,y ;i<=m;i++)
    {
        cin >> x >> y ;
        q[i]={x,y};
        cc.emplace_back(x);
        cc.emplace_back(y);
    }
    sort(cc.begin(),cc.end());
    cc.resize(unique(cc.begin(),cc.end())-cc.begin());
    sort(a.begin(),a.end());
    int sz = cc.size();
    root[0]=1;
    construct(1,sz,1);
    for(int i=0,r=0;i<sz;i++)
    {
        int it = cc[i];
        root[i+1]=root[i];
        while(a[r].fi==it&&r<n)
        {
            int y = lower_bound(cc.begin(),cc.end(),a[r].se)-cc.begin()+1;
            root[i+1]=update(1,sz,y,root[i+1]),r++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        int ans[5]={0,0,0,0,0};
        int x = lower_bound(cc.begin(),cc.end(),q[i].fi)-cc.begin()+1;
        int y = lower_bound(cc.begin(),cc.end(),q[i].se)-cc.begin()+1;
        ans[1]=getsum(1,sz,y+1,sz,root[y])-getsum(1,sz,y+1,sz,root[x-1]);
        ans[2]=getsum(1,sz,x,y,root[x-1]);
        ans[3]=getsum(1,sz,x,y,root[y])-ans[2];
        ans[4]=getsum(1,sz,y+1,sz,root[x-1]);
        for(int j=1;j<5;j++)ans[0]+=ans[j];
        for(int j=0;j<5;j++)cout << ans[j] << " " ;
        cout << '\n' ;
    }
    return 0 ;
}
