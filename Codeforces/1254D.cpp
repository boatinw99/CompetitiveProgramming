#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
#define mid (l+r>>1)
const int N = 2e5+9 , mod = 998244353 ; 
vector<int> g[N];
ll f[N],val[N],st[N<<2];
int times=0,tin[N],tout[N],sub[N],n;
int hd[N],pos[N],num=1,idx=0,ch[N],subhld[N],par[N]; ///hld
void upf(int x,int val)
{
    for(;x<N;x+=x&-x)f[x]+=val+mod,f[x]%=mod;
}
ll getsumf(int x)
{
    ll sum = 0;
    for(;x;x-=x&-x)sum+=f[x]+mod,sum%=mod;
    return sum ; 
}
void updatesg(int l,int r,int x,ll y,int m)
{
    if(r<x||l>x)return ;
    if(l==r)
    {
        st[m]+=y ;
        st[m]%=mod;
        return ; 
    }
    updatesg(l,mid,x,y,m<<1);
    updatesg(mid+1,r,x,y,m<<1|1);
    st[m]=st[m<<1]+st[m<<1|1];
    st[m]%=mod;
}
ll getsumsg(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return 0 ;
    if(l>=x&&r<=y)return st[m];
    return (getsumsg(l,mid,x,y,m<<1)+getsumsg(mid+1,r,x,y,m<<1|1))%mod;
}
void dfs0(int u,int v)
{
    tin[u]=++times ;
    sub[u]=1;
    for(auto it:g[u])
    {
        if(it!=v)
        {
            dfs0(it,u);
            sub[u]+=sub[it];
        }
    }
    tout[u]=times;
}
void hld(int u,int v)
{
    pii mx = {0,0}; //cst node
    par[u]=v;
    pos[u]=++idx;
    ch[u]=num ; 
    if(!hd[num])hd[num]=u;
    for(auto it:g[u])
    {
        if(it!=v)
        {
            mx = max(mx,{sub[it],it});
        }
    }
    if(mx.se)hld(mx.se,u);
    subhld[u]=sub[mx.se];
    for(auto it:g[u])
    {
        if(it!=v&&it!=mx.se)
        {
            num++,hld(it,u);
        }
    }
}
ll powap(ll a,ll p)
{
    if(p==0)return 1 ;
    ll ret = powap(a,p>>1);
    ret = ret*ret%mod;
    if(p&1)ret=ret*a%mod;
    return ret ; 
}
void update(int u,ll wi)
{
    val[u]+=wi;
    val[u]%=mod;
    upf(1,wi*sub[u]%mod);
    upf(tin[u],(-wi*sub[u]+1ll*mod*mod)%mod);
    upf(tout[u]+1,wi*sub[u]%mod);
    updatesg(1,n,pos[u],wi*(n-subhld[u])%mod,1);
}
ll solve(int u)
{
    int tmp = u ; 
    ll sum = getsumf(tin[u])+val[u]*n%mod;
    sum%=mod;
    //printf("check %d -> %lld \n",u,sum);
    while(u!=0)
    {
        int hh = hd[ch[u]];
        sum+=getsumsg(1,n,pos[hh],pos[u]-1,1);
        sum%=mod;
        sum+=1ll*val[par[hh]]*(n-sub[hh]);
        sum%=mod;
        u = par[hh];  
    }
    return (sum*powap(n,mod-2))%mod ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int m ; 
    cin >> n >> m ;
    for(int i=1,u,v ;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs0(1,1);
    hld(1,0);
    for(int i=1;i<=m;i++)
    {
        int typ,u ;
        cin >> typ >> u ;
        if(typ==1)
        {
            ll wi ; 
            cin >> wi ; 
            update(u,wi);
        }
        else 
        {
            cout << solve(u) << '\n' ;
        }
    }
    return 0 ; 
}