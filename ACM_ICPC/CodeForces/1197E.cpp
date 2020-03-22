#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
#define mid (l+r>>1)
const int N = 2e5+9 , mod = 1e9+7 , inf = 1e9+7 ; 
vector<pii> doll,pos;
set<pii> S ; ///
pii st[N<<2],A[N];
int st1[N<<2];
bool exist[N];
pii operate(pii a,pii b)
{
    pii T=min(a,b); 
    if(a.fi==b.fi)
    {
        T = {a.fi,(a.se+b.se)%mod}; 
    }
    return T ; 
}
pii getmin(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return {inf,0};
    if(l>=x&&r<=y)return st[m];
    return operate(getmin(l,mid,x,y,m<<1),getmin(mid+1,r,x,y,m<<1|1));
}
void update(int l,int r,int x,pii now,int m)
{
    if(r<x||l>x)return ;
    if(l==r)
    {
        st[m]=now ;
        return ;
    }
    update(l,mid,x,now,m<<1);
    update(mid+1,r,x,now,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}
int getmin1(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return inf ; 
    if(l>=x&&r<=y)return st1[m];
    return min(getmin1(l,mid,x,y,m<<1),getmin1(mid+1,r,x,y,m<<1|1));
}
void update1(int l,int r,int x,int y,int m)
{
    if(r<x||l>x)return ;
    if(l==r)
    {
        st1[m]=y ;
        return ;
    }
    update1(l,mid,x,y,m<<1);
    update1(mid+1,r,x,y,m<<1|1);
    st1[m]=min(st1[m<<1],st1[m<<1|1]);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    cin >> n ;
    for(int i=0;i<N*4;i++)
    {
        st[i]={inf,0};
        st1[i]=inf;
    }
    for(int i=1,u,v ;i<=n;i++)
    {
        cin >> u >> v ;
        doll.push_back({u,v});
    }
    doll.push_back({0,0});
    sort(doll.begin(),doll.end());
    doll.push_back({doll[n].fi,inf-5});
    for(int i=0;i<=n+1;i++)
    {
        pos.push_back({doll[i].se,i});
    }
    sort(pos.begin(),pos.end());
    pii ans = {inf,0} ;
    int exin = 0 ;
    for(int i=1;i<=n+1;i++)
    {
        int idx = pos[i].se ;
        pii P = doll[idx];///out,in
        while(!S.empty()) /// out,idx
        {
            pii it = *S.begin();
            auto tmp = lower_bound(pos.begin(),pos.end(),make_pair(it.fi,0))-pos.begin();
            int ret = getmin1(1,n,tmp,n,1);
            ///find in j >= out it (P.fi) that doll j have out j <=in it    
            if(ret<=P.se)
            {
                S.erase(it);
                exist[pos[it.se].se]++;
                //printf("really position=%d ret=%d P.se=%d?\n",pos[it.se].se,ret,P.se);
                update(1,n,pos[it.se].se,{inf,0},1);
                update1(1,n,it.se,inf,1);
            }
            else break ;
        }
        if(i==n+1)break;
        int R = upper_bound(doll.begin(),doll.end(),make_pair(P.se+1,0))-doll.begin()-1;
        pii ret = getmin(1,n,1,R,1);
        ret.fi+=P.se;
        if(ret.fi>inf)
        {
            A[idx] = {P.se,1};
        }
        else 
        {
            A[idx] = ret;
        }
        //printf("wtf %d %d || %d %d \n",A[idx].fi,A[idx].se,P.fi,P.se);
        update(1,n,idx,{A[idx].fi-P.fi,A[idx].se},1);
        update1(1,n,i,P.fi,1);
        S.insert({P.fi,i});
    }
    for(int i=1;i<=n;i++)
    {
        if(!exist[i])
        {
            ans = operate(ans,A[i]);
            //printf("pls");
        }
    }
    cout << ans.se << '\n' ;
    return 0 ;
}