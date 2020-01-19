#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 309, LOG=log2(N)+1 , K=10;
vector<int> g[N];
vector<int> mark[N];
vector<pii> st,ans;
pair<int,pii> q[N];
int up[N][LOG],tin[N],tout[N],depth[N],times=0,cnt=0,m;
bool vst[N];
void dfs0(int u,int v)
{
    up[u][0]=v;
    depth[u]=depth[v]+1;
    for(int i=1;i<LOG;i++)up[u][i]=up[up[u][i-1]][i-1];
    tin[u]=++times;
    for(auto it:g[u])if(it!=v)dfs0(it,u);
    tout[u]=++times;
}
bool Islca(int u,int v)
{
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
bool cmp(pair<int,pii> q1,pair<int,pii> q2)
{
    return depth[q1.fi]>depth[q2.fi] ;
}
int lift(int u,int cst)
{
    for(int i=0;i<LOG;i++)if((1<<i)&cst)u=up[u][i];
    return u ;
}
int findlca(int u,int v)
{
    if(Islca(u,v))return u ;
    if(Islca(v,u))return v ;
    for(int i=LOG-1;i>=0;i--)if(!Islca(up[u][i],v))u=up[u][i];
    return up[u][0];
}
void MARK(int x,int par)
{
    for(int i=1;i<=m;i++)
    {
        if(vst[i]==0)
        {
            if(Islca(q[i].fi,x)&&(Islca(x,q[i].se.se)||Islca(x,q[i].se.fi)))
            {
                vst[i]++;
                mark[par].push_back(i);
            }
        }
    }
}
void chk(int i)
{
    if(cnt>K)return ;
    if(i==m+1)
    {
        if(st.size()<ans.size())ans=st;
        return ;
    }
    if(vst[i]==0)
    {
        vst[i]++;
        cnt++;
        st.push_back({q[i].fi,lift(q[i].se.se,depth[q[i].se.se]-depth[q[i].fi]-1)});
        int r=st.back().se;
        MARK(r,i);
        chk(i+1);
        for(auto it:mark[i])vst[it]=0;
        mark[i].clear();
        st.pop_back();
        if(q[i].se.fi==q[i].fi)
        {
            vst[i]=0;
            cnt--;
            return ;
        }
        st.push_back({q[i].fi,lift(q[i].se.fi,depth[q[i].se.fi]-depth[q[i].fi]-1)});
        r=st.back().se;
        MARK(r,i);
        chk(i+1);
        for(auto it:mark[i])vst[it]=0;
        mark[i].clear();
        st.pop_back();
        vst[i]=0;
        cnt--;
    }
    else chk(i+1);
}
main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n,u,v,i,j ;
    cin >> n >> m ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for(i=1;i<=14;i++)ans.push_back({1,1});
    dfs0(1,1);
    for(i=1;i<=m;i++)
    {
        cin >> q[i].se.fi >> q[i].se.se ;
        if(depth[q[i].se.fi]>depth[q[i].se.se])swap(q[i].se.fi,q[i].se.se);
        q[i].fi=findlca(q[i].se.fi,q[i].se.se);
    }
    sort(q+1,q+1+m,cmp);
    chk(1);
   // while(ans.size()>10);
    cout << ans.size() << '\n';
    for(auto it:ans)
    {
        cout << it.fi << " " << it.se << '\n' ;
    }
}
