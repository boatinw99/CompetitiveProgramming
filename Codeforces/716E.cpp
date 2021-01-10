///14.31-14.51(break) -> 14.55 and end up because of the math LOL
#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 1e5+9;
vector<pii> g[N];
map<int,int> mp ;
int sub[N],md,P[N],phi,p=0,inv;
bool vst[N],chk[N];
ll ans=0;
int powap(int a,int p)
{
    if(p==0)return 1;
    if(p==1)return a;
    int tmp = powap(a,p/2);
    tmp=1ll*tmp*tmp%md;
    if(p&1)tmp=1ll*tmp*a%md;
    return tmp ;
}
void dfs1(int u)
{
    sub[u]=1;
    vst[u]++;
    for(auto it:g[u])if(!vst[it.fi])dfs1(it.fi),sub[u]+=sub[it.fi];
    vst[u]=0;
}
int dfs2(int u,int v,int sz)
{
    for(auto it:g[u])if(!vst[it.fi]&&it.fi!=v&&sub[it.fi]>sz/2)
        return dfs2(it.fi,u,sz);
    return u ;
}
void dfs3(int u,int cst,int add,int depth)
{
    mp[cst]+=add;
    vst[u]++;
    for(auto it:g[u])if(!vst[it.fi])
        dfs3(it.fi,(1ll*it.se*powap(10,depth)%md+cst)%md,add,depth+1);
    vst[u]=0;
}
void dfs4(int u,int cst,int depth)
{
    vst[u]++;
    int tmp = (1ll*(md-cst)*powap(inv,depth))%md;
    ans+=mp[tmp];
    for(auto it:g[u])if(!vst[it.fi])
        dfs4(it.fi,(10ll*cst+it.se)%md,depth+1);
    vst[u]=0;
}
void dcp(int u)
{
    dfs1(u);
    int ctd = dfs2(u,u,sub[u]);
    vst[ctd]++;
    mp[0]++;
    for(auto it:g[ctd])if(!vst[it.fi])dfs3(it.fi,it.se%md,1,1);
    for(auto it:g[ctd])
    {
        if(!vst[it.fi])
        {
            dfs3(it.fi,it.se%md,-1,1);
            dfs4(it.fi,it.se%md,1);
            dfs3(it.fi,it.se%md,1,1);
        }
    }
    mp[0]--;
    ans+=mp[0];
    for(auto it:g[ctd])if(!vst[it.fi])dfs3(it.fi,it.se%md,-1,1);
    for(auto it:g[ctd])if(!vst[it.fi])dcp(it.fi);
}
void preprocess()
{
    for(int i=2;i<N;i++)
    {
        if(chk[i]==0)
        {
            P[p++]=i;
            for(int j=i;j<N;j+=i)chk[j]++;
        }
    }
    int tmp=md ;
    phi=md;
    for(int i=0;P[i]*P[i]<=tmp;i++)
    {
        if(tmp%P[i]==0)
        {
            phi/=P[i];
            phi*=P[i]-1;
            while(tmp%P[i]==0)tmp/=P[i];
        }
    }
    if(tmp>1)
    {
        phi/=tmp;
        phi*=(tmp-1);
    }
    inv=powap(10,phi-1);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,u,v,x ;
    cin >> n >> md ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v >> x ;
        g[u].emplace_back(v,x);
        g[v].emplace_back(u,x);
    }
    preprocess();
    dcp(0);
    cout << ans ;
}
