#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N = 1e5+9 , LOG=log2(N)+1 , P = 1e7+9 , md=1e9+7;
vector<int> g[N],sprime;
vector<pii> p[N*8],query[N*8]; /// store prime factor of ai (p^,node);
pii iterate ;
int path[N][3];
int a[N],ans[N];
int up[N][LOG],tin[N],tout[N],times=0,sz=0 ;
int euler[N],out[N],f[N*2],prime[P],pos[P],posinf[N],n;
void update(int i,int cst)
{
    for(;i<=n;i+=i&-i)f[i]+=cst;
}
int getval(int i)
{
    int x=0 ;
    for(;i;i-=i&-i)x+=f[i];
    return x ;
}
void dfs(int u,int v)
{
    tin[u]=++times ;
    euler[++sz]=u;///euler path
    posinf[u]=sz;
    up[u][0]=v ;
    for(int i=1;i<LOG;i++)up[u][i]=up[up[u][i-1]][i-1];
    for(auto it:g[u])if(it!=v)dfs(it,u);
    out[u]=sz;///u -> mx pos in euler path that in sub of u)
    tout[u]=++times ;
}
bool Islca(int u,int v)
{
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
int findlca(int u,int v)
{
    if(Islca(u,v))return u ;
    if(Islca(v,u))return v ;
    for(int i=LOG-1;i>=0;i--)if(!Islca(up[u][i],v))u=up[u][i];
    return up[u][0];
}
void updatefw(int u,int cst)
{
    ///updatefw in pos[u]->eulertour with +cst and - cst
    update(posinf[u],cst);
    update(out[u]+1,-cst);
}
void qupdate(int i,int ex)
{
    ///iterate -> (pos,pre expo);
    if(p[i].empty())return ;
    for(;p[i][iterate.fi].fi<=ex&&iterate.fi<p[i].size();iterate.fi++)
        updatefw(p[i][iterate.fi].se,p[i][iterate.fi].fi-iterate.se);
    for(int tmp=iterate.fi;tmp<p[i].size();tmp++)
        updatefw(p[i][tmp].se,ex-iterate.se);
    iterate.se=ex;
}
void del(int i)
{
    for(auto it:p[i])updatefw(it.se,-min(it.fi,iterate.se));
}
int powax(int b,int x)
{
    if(x==0)return 1 ;
    if(x==1)return b ;
    int tmp = powax(b,x/2);
    tmp=1ll*tmp*tmp %md ;
    if(x&1)tmp=1ll*tmp*b%md ;
    return tmp ;
}
int findans(int b,int i,int ex)
{
    int u=path[i][0],v=path[i][1],lca=path[i][2];
    int x = getval(posinf[u])+getval(posinf[v])-
    getval(posinf[lca]);
    if(lca>1)x-=getval(posinf[up[lca][0]]);
    x=powax(b,x);
    ans[i]=1ll*x*ans[i]%md;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j,T,u,v,x,tmp,ex ;
    cin >> n ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    ///find prime
    for(i=2;i<P;i++)
    {
        if(prime[i]==0)
        {
            pos[i]=sprime.size();
            sprime.emplace_back(i);
            for(j=1;j*i<P;j++)prime[j*i]=i;
        }
    }
    ///lca + euler tour
    dfs(1,1);
    for(i=1;i<=n;i++)
    {
        cin >> a[i] ;
        tmp=a[i];
        while(tmp>1)
        {
            int cnt=0,x=prime[tmp];
            while(tmp%x==0)tmp/=x,cnt++;
            p[pos[x]].emplace_back(cnt,i);
        }
    }
    for(i=0;i<sprime.size();i++)
        if(!p[i].empty())sort(p[i].begin(),p[i].end());
    cin >> T ;
    for(i=1;i<=T;i++)
    {
        cin >> u >> v >> tmp ;
        path[i][0]=u,path[i][1]=v,path[i][2]=findlca(u,v);
        while(tmp>1)
        {
            int cnt=0,x=prime[tmp];
            while(tmp%x==0)tmp/=x,cnt++;
            query[pos[x]].push_back({cnt,i});
        }
    }
    for(i=1;i<=T;i++)ans[i]=1;
    fill(ans,ans+N-1,1);
    for(i=0;i<sprime.size();i++)
        if(!query[i].empty())sort(query[i].begin(),query[i].end());
    for(i=0;i<sprime.size();i++)
    {
        if(query[i].empty())continue ;
        auto it = query[i].begin() ;
        iterate={0,0};
        ///prime(i) ^ex it.se (pos)
        while(it!=query[i].end())
        {
            ex=it->fi;
            qupdate(i,ex);
            for(;it!=query[i].end()&&it->fi==ex;it++)
                findans(sprime[i],it->se,ex);
        }
        del(i);
    }
    for(i=1;i<=T;i++)cout << ans[i] << '\n' ;
}
