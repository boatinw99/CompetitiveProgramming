#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,int> pli ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
#define mid (l+r>>1)
const ll INF = 1e16 ; 
const int N = 1e6+9 ,inf = 1e9+7;
pair<pii,int> point[N]; 
vector<int> cc ; 
map<int,vector<int>> P;
pli st[N<<2];
ll lazy[N<<2];
pli operate(pli lhs,pli rhs)
{
    pli mhs ;
    if(lhs.fi>rhs.fi)mhs = lhs ;
    else mhs = rhs ;
    return mhs ;
}
void construct(int l,int r,int m)
{
    if(l==r)
    {
        st[m]={cc[l-1],cc[l-1]};
        return ;
    }
    construct(l,mid,m<<1);
    construct(mid+1,r,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}
void push(int l,int r,int m)
{
    if(lazy[m]==0)return ;
    st[m].fi+=lazy[m];
    if(l<r)
    {
        lazy[m<<1]+=lazy[m],lazy[m<<1|1]+=lazy[m];
    }
    lazy[m]=0;
}
void update(int l,int r,int x,int y,ll add,int m)
{
    push(l,r,m);
    if(r<x||l>y)return ;
    if(l>=x&&r<=y)
    {
        lazy[m]+=add;
        push(l,r,m);
        return ;
    }
    update(l,mid,x,y,add,m<<1);
    update(mid+1,r,x,y,add,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}
pli getmax(int l,int r,int x,int y,int m)
{
    push(l,r,m);
    if(r<x||l>y)return {-INF,inf};
    if(l>=x&&r<=y)return st[m];
    return operate(getmax(l,mid,x,y,m<<1),getmax(mid+1,r,x,y,m<<1|1)); 
}
int findidx(int x)
{
    int idx = lower_bound(cc.begin(),cc.end(),x)-cc.begin()+1;
    return idx ; 
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    pair<ll,pii> ans = {0,{inf,inf}}; 
    cin >> n ;
    for(int i=1,x,y,c ;i<=n;i++)
    {
        cin >> x >> y >> c ;
        point[i]={{x,y},c};
        cc.push_back(x);
        cc.push_back(y);
        P[max(x,y)].push_back(i);
    }
    sort(cc.begin(),cc.end());
    cc.resize(unique(cc.begin(),cc.end())-cc.begin());
    int m = cc.size();
    ll cstnow = 0 ;
    construct(1,m,1);
    int ex = -1 ;
    for(auto itp:P)
    {
        if(itp.fi<=ex)while(1);
        ex=itp.fi;
        for(auto it:itp.se)
        {
            cstnow+=point[it].se ; 
            int x = point[it].fi.fi , y = point[it].fi.se;
            int idx = 0 ;
            if(y<=x)
            {
                idx = findidx(y)+1;
            }
            else 
            {
                idx = findidx(x)+1;
            }
            update(1,m,idx,m,-point[it].se,1);
            //printf("wtf x=%d y=%d -> update here => %d st[2]=%lld\n",x,y,idx,getmax(1,m,2,2,1).fi);
            //printf("point number = %d \n",it);
        }
        ///itp = x,y 
        int idx = findidx(itp.fi);
        pli ret = getmax(1,m,1,idx,1);
        pair<ll,pii> tmp = {ret.fi+cstnow-cc[idx-1],{ret.se,cc[idx-1]}};
        if(ans.fi<tmp.fi)ans=tmp ; 
        //printf("check %lld %lld\n",tmp.fi,ret.fi);
    }
    //return 0 ;
    cout << ans.fi << '\n' ;
    cout << ans.se.fi << " " << ans.se.fi << " " << ans.se.se << " " << ans.se.se << '\n' ;
    return 0 ;
}