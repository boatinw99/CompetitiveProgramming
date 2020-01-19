#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pii ;
#define fi first
#define se second 
#define mid (l+r>>1)
const int N = 5e5+9 , inf = 1e9 ; 
struct Q
{
    int node;
    ll upfi,upse ;
} query[N];
vector<int> g[N],business[N],pbs[N]; /// tree //factory  /// parallel binary search -> l,r,M
ll f[N][2],threshold[N];
int L[N],R[N],in[N],out[N],n,m,q,depth[N],times=0; 
void update(int idx,int i,ll val)
{
    for(i;i<N;i+=i&-i)
    {
        f[i][idx]+=val;
    }
}
pii getsum(int i)
{
    pii ret = {0,0} ;
    for(i;i;i-=i&-i)
    {
        ret.fi+=f[i][0];
        ret.se+=f[i][1];
    }
    return ret ; 
}
void comp(int idx)
{
    int l=L[idx],r=R[idx];
    if(l==r)
    {
        return ; 
    }
    ll val = 0 ;
    for(auto town:business[idx])
    {
        pii ret = getsum(in[town]);
        val+=ret.fi+ret.se*depth[town];
    }
    if(val<threshold[idx])
    {
        L[idx]=mid+1; 
    }
    else R[idx]=mid ;
}
void clean_stuff()
{
    for(int i=0;i<N;i++)f[i][0]=f[i][1]=0;
    for(int i=1;i<=q;i++)
    {
        pbs[i].clear();
    }
    for(int i=1;i<=m;i++)
    {
        pbs[L[i]+R[i]>>1].push_back(i);
    }
}
void dfs0(int u,int dp)
{
    in[u]=++times;
    depth[u]=dp ;
    for(auto it:g[u])
    {
        dfs0(it,dp+1);
    }
    out[u]=times+1;
}
void add(int i)
{
    update(0,in[query[i].node],query[i].upfi);
    update(1,in[query[i].node],query[i].upse);
    update(0,out[query[i].node],-query[i].upfi);
    update(1,out[query[i].node],-query[i].upse);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m ; 
    for(int i=2,u ;i<=n;i++)
    {
        cin >> u;
        g[u].emplace_back(i); 
    }
    for(int i=1,u ;i<=n;i++)
    {
        cin >> u ;
        business[u].emplace_back(i);
    }
    for(int i=1;i<=m;i++)
    {
        cin >> threshold[i];
    }
    dfs0(1,0);
    cin >> q ; 
    for(int i=1,u;i<=q;i++)
    {
        ll X,D ;
        cin >> u >> X >> D ; 
        query[i]={u,X-D*depth[u],D};
    }
    for(int i=1;i<=m;i++)
    {
        L[i]=1;
        R[i]=q+1;
    }
    for(int rd=1;rd<=log2(q)+1;rd++)
    {
        clean_stuff();
        for(int i=1;i<=q;i++)
        {
            add(i);
            for(auto it:pbs[i])comp(it);
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(R[i]==q+1)cout << "rekt" << '\n' ;
        else cout << R[i] << '\n' ;
    }
    return 0 ;
}