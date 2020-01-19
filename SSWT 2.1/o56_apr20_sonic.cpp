///NOT-FINISH YET
#include<bits/stdc++.h>
using namespace std ;
#define mid (l+r>>1)
typedef long long ll ;
const int N = 5e5+9 ;
ll st[N<<2];
vector<int> cc ;
map<int,ll> mp;
struct Q
{
    int t,x,powr,idx;
}q[N];
ll ans[N];
void update(int l,int r,int x,ll cst,int m)
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
ll getsum(int l,int r,int x,int y,int m)
{
    if(r<x||l>y||x>y)return 0 ;
    if(l>=x&&r<=y)return st[m];
    return getsum(l,mid,x,y,m<<1)+getsum(mid+1,r,x,y,m<<1|1);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,L,i,j,typ,sz,times=0,cnt=0,prev=0 ;
    cin >> n >> L ;
    sz=2*n ;
    q[0].x=-1 ;
    for(i=1;i<=n;i++)ans[i]=-1 ;
    for(i=1;i<=n;i++)
    {
        cin >> typ >> q[i].t >> q[i].x ;
        if(typ==1)
        {
            cin >> q[i].powr;
            //mp[q[i].x]+=q[i].powr;
        }
        else
        {
            q[i].powr=0 ;
            ans[i]=0 ;
            //ans[i]-=mp[q[i].x];
            cnt++;
        }
        q[i].idx=i ;
        cc.push_back(q[i].t-q[i].x);
        printf("aa aaaaaaaaaaaa %d \n",q[i].t-q[i].x);
        cc.push_back(q[i].t+q[i].x);
    }
    sort(q+1,q+1+n,[&](Q lhs,Q rhs){
         if(lhs.x==rhs.x)return lhs.powr>rhs.powr;
         return lhs.x<rhs.x ;
         });
    sort(cc.begin(),cc.end());
    for(i=1;i<=n;i++)
    {
        int tmp = q[i].t-q[i].x ;
        auto it = lower_bound(cc.begin(),cc.end(),tmp)-cc.begin()+1;
        if(q[i].powr)update(1,sz,it,q[i].powr,1),mp[q[i].x]+=q[i].powr;
        else ans[q[i].idx]+=getsum(1,sz,1,it,1)-mp[q[i].x];
    }
    memset(st,0,sizeof st);
    sort(q+1,q+1+n,[&](Q lhs,Q rhs){
         if(lhs.x==rhs.x)return lhs.powr>rhs.powr ;
         return lhs.x>rhs.x ;
         });
    for(i=1;i<=n;i++)
    {
        int tmp = q[i].t+q[i].x;
        auto it=lower_bound(cc.begin(),cc.end(),tmp)-cc.begin()+1;
        if(q[i].powr)update(1,sz,it,q[i].powr,1);
        else ans[q[i].idx]+=getsum(1,sz,1,it,1);
    }
    for(i=1;i<=n;i++)
    {
        if(ans[i]>=0)
        {
            cnt--;
            cout << ans[i] << '\n' ;
        }
        while(ans[i]<-1);
    }
    while(cnt!=0);
}
