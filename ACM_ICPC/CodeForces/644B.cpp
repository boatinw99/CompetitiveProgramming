#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
#define mid (l+r>>1)
const int N = 2e5+9 ; 
vector<ll> cc ;
pii query[N] ; 
int n,sz,st[N<<2];
ll times = 0 ;
void update(int l,int r,int x,int cst,int m)
{
    if(r<x||l>x)return ;
    if(l==r)
    {
        st[m]+=cst ;
        return ;
    }
    update(l,mid,x,cst,m<<1);
    update(mid+1,r,x,cst,m<<1|1);
    st[m]=st[m<<1]+st[m<<1|1];
}
int getsum(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return 0 ;
    if(l>=x&&r<=y)return st[m] ;
    return getsum(l,mid,x,y,m<<1)+getsum(mid+1,r,x,y,m<<1|1);
}
ll process(ll t,ll d) /// times duration 
{
    int idx = lower_bound(cc.begin(),cc.end(),t)-cc.begin()+1;
    if(getsum(1,n,1,idx,1)<=sz)
    {
        if(times<=t)times=t ; 
        times+=d;
        //printf("wtf t=%lld idx=%d sum=%d %d\n",t,idx,getsum(1,n,1,idx,1),lower_bound(cc.begin(),cc.end(),times)-cc.begin()+1);
        update(1,n,idx,1,1);
        update(1,n,lower_bound(cc.begin(),cc.end(),times)-cc.begin()+1,-1,1);
        return times ; 
    }
    return -1 ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int m ; 
    cin >> m >> sz ;
    for(int i=1;i<=m;i++)
    {
        cin >> query[i].fi >> query[i].se ; 
        cc.push_back(query[i].fi);
        //cc.push_back(query[i].se); 
    }
    sort(cc.begin(),cc.end());
    //cc.resize(unique(cc.begin(),cc.end())-cc.begin());
    n = cc.size();
    //for(auto it:cc)printf("%d ",it);
    for(int i=1;i<=m;i++)
    {
        cout << process(query[i].fi,query[i].se) << " " ;
    }
    return 0 ;
}