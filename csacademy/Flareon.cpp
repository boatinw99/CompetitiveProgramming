#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pll ; 
typedef pair<int,int> pii ;
#define fi first 
#define se second 
const int N = 2e5+9 , LOG=log2(N)+1 ; 
int sub[N],dist[N][LOG],depth[N],n,vst[N];
ll Pad[N],Pde[N];
pll pp ; //>N -> cst,num
ll ans[N];
vector<int> pwrad[N];
vector<int> g[N];
void dfs0(int u)
{
    sub[u]=1;
    vst[u]++;
    for(auto it:g[u])  
    {
        if(!vst[it])dfs0(it),sub[u]+=sub[it];
    }
    vst[u]=0;
}
int dfs1(int u,int v,int sz)
{
    for(auto it:g[u])
    {
        if(!vst[it]&&it!=v&&sub[it]>sz/2)return dfs1(it,u,sz);
    }
    return u ;
}
void dfs2(int u,int cst,int depthctd,int mul)
{
    vst[u]++;
    for(auto it:pwrad[u])
    {
        if(it-cst>0)
        {
            pp.se+=mul;
            pp.fi+=(it-cst)*mul;
            if(it-cst<N)
            {
                Pad[it-cst]+=mul;
            }
        }
    }
    for(auto it:g[u])
    {
        if(!vst[it])
        {
            dfs2(it,cst+1,depthctd,mul);
        }
    }
    vst[u]=0;
}
void dfs3(int u,pll add,int di)
{
    add.fi-=add.se;
    add.se-=Pad[di];
    ans[u]+=add.fi;
    vst[u]++;
    for(auto it:g[u])
    {
        if(!vst[it])
        {
            dfs3(it,add,di+1);
        }
    }
    vst[u]=0;
}
void dfs4(int u,int par,int cst,int mul) ///add exclusion on par
{
    vst[u]++;
    for(auto it:pwrad[u])
    {
        if(it-cst>0)
        {
            pp.se+=mul; 
            pp.fi+=(it-cst)*mul;
            if(it-cst-1<N)Pde[it-cst]+=mul;
        }
    }
    for(auto it:g[u])
    {
        if(!vst[it])
        {
            dfs4(it,par,cst+1,mul);
        }
    }
    vst[u]=0;
}
void dfs5(int u,pll add,int di)
{
    add.fi-=add.se;
    add.se-=Pde[di];
    ans[u]-=add.fi;
    vst[u]++;
    for(auto it:g[u])
    {
        if(!vst[it])dfs5(it,add,di+1);
    }
    vst[u]=0;
}
void decompose(int u,int lvl,int prectd)
{
    dfs0(u);
    int ctd = dfs1(u,u,sub[u]);
    depth[ctd]=lvl ; 
    vst[ctd]=1;
    for(auto it:g[ctd])
    {
        if(!vst[it])decompose(it,lvl+1,ctd);
    }
    dfs2(ctd,0,depth[ctd],1);
    pp.fi+=pp.se;
    dfs3(ctd,pp,0);
    pp.fi-=pp.se;
    dfs2(ctd,0,depth[ctd],-1);
    vst[ctd]=1;
    for(auto it:g[ctd])
    {
        if(!vst[it])
        {
            dfs4(it,it,1,1);
            dfs5(it,pp,1);
            dfs4(it,it,1,-1);
        }
    }   
    vst[ctd]=0;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int m ;
    cin >> n >> m ;
    for(int i=2,u ;i<=n;i++)
    {
        cin >> u ;
        g[u].emplace_back(i);
        g[i].emplace_back(u);
    }
    for(int i=1,u,pwr ;i<=m;i++)
    {
        cin >> u >> pwr ;
        pwrad[u].push_back(pwr) ;
    }
    decompose(1,0,0);
    for(int i=1;i<=n;i++)
    {
        cout << ans[i] << '\n' ;
    }
    return 0 ;
}