#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 2e5+9 ,sq = 450 ,inf = 1e9 ;
vector<pii> g[N];
vector<int> path ;
int dist[N],val[N],n,m,a,b,sz,pos[N];
int mx[N];
pii block[N];
bool inpath[N];
int dfs1(int u,int v)
{
    if(u==b)
    {
        inpath[u]=1;
        path.emplace_back(u);
        return 1 ;
    }
    for(auto it:g[u])
    {
        if(it.fi!=v)
        {
            int ret = dfs1(it.fi,u);
            if(ret==1)
            {
                path.emplace_back(u);
                inpath[u]=1;
                return 1 ;
            }
        }
    }
    return 0 ;
}
void dfs0(int u,int v)
{
    val[u]=dist[u];
    for(auto it:g[u])
    {
        if(it.fi!=v)
        {
            dist[it.fi]=dist[u]+it.se;
            dfs0(it.fi,u);
            if(inpath[it.fi]==0)
            {
                val[u]=max(val[u],val[it.fi]);
            }
        }
    }
}
void pre_process(int i)
{
    int l = i*sq ,r=min((i+1)*sq-1,sz-1);
    if(l>=sz)return ;
    int mx1=-inf,ans=0 ;
    for(int i=l;i<=r;i++)
    {
        int u = path[i];
        ans=max(ans,mx1+dist[u]+val[u]);
        mx1=max(mx1,val[u]-dist[u]);
    }
    mx[i]=ans;
}
int query(int l,int r)
{
    int mx1=-inf,ans=0;
    while(l%sq&&l<=r)
    {
        int u = path[l];
        ans=max(ans,dist[u]+val[u]+mx1);
        mx1=max(mx1,val[u]-dist[u]);
        l++;
    }
    while(l+sq<=r)
    {
        int bl = l/sq ;
        ans=max(ans,mx[bl]);
        ans=max(ans,block[bl].se+mx1);
        mx1=max(mx1,block[bl].fi);
       // printf("chk %d | %d %d\n",bl,mx1,block[bl].fi);
        l+=sq;
    }
    //printf("aaa %d %d %d\n",l,ans,mx1);
    while(l<=r)
    {
        int u = path[l];
        ans=max(ans,dist[u]+val[u]+mx1);
        mx1=max(mx1,val[u]-dist[u]);
        l++;
    }
    return ans ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m >> a >> b ;
    for(int i=1,u,v,x ;i<n;i++)
    {
        cin >> u >> v >> x ;
        g[u].emplace_back(v,x);
        g[v].emplace_back(u,x);
    }
    dfs1(a,a);
    dfs0(a,a);
    reverse(path.begin(),path.end());
    sz = path.size();
    for(int i=0;i<(sz-1)/sq+1;i++)block[i]={-inf,-inf};
    int exdist = 0 ;
    for(int i=0;i<sz;i++)
    {
        ///max1,max2
        ///max1 -> L , max2 -> R ;
        int u = path[i];
        pos[u]=i ;
        val[u]=val[u]-dist[u];
        block[i/sq].fi=max(block[i/sq].fi,val[u]-dist[u]);
        block[i/sq].se=max(block[i/sq].se,dist[u]+val[u]);
    }
    for(int i=0;i<(sz-1)/sq+1;i++)pre_process(i);
    /*for(int i=0;i<(sz-1)/sq+1;i++)
    {
        printf("cqwe %d %d \n",block[i].fi,block[i].se);
    }*/
    while(m--)
    {
        int u,v ;
        cin >> u >> v ;
        if(pos[u]>pos[v])swap(u,v);
        cout << query(pos[u],pos[v]) << '\n' ;
    }
    return 0 ;
}
