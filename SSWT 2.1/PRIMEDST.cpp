#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 5e4+9 ;
vector<int> g[N];
int P[N],sub[N],len=0;
int dist[N];
bool visited[N],chk[N];
ll ans=0;
void dfs1(int u)
{
    sub[u]=1,visited[u]++;
    for(auto it:g[u])if(!visited[it])dfs1(it),sub[u]+=sub[it];
    visited[u]=0;
}
int dfs2(int u,int v,int sz)
{
    for(auto it:g[u])if(it!=v&&!visited[it]&&sub[it]>sz/2)
        return dfs2(it,u,sz);
    return u ;
}
void dfs3(int u,int depth)
{
    dist[depth]++;
    visited[u]++;
    for(auto it:g[u])if(!visited[it])dfs3(it,depth+1);
    visited[u]=0;
}
void dfs4(int u,int cst)
{
    visited[u]++;
    for(int i=0;i<len;i++)
    {
        if(P[i]<cst)continue;
        if(!dist[P[i]-cst])break;
        ans+=dist[P[i]-cst];
    }
    for(auto it:g[u])
    {
        if(!visited[it])dfs4(it,cst+1);
    }
    visited[u]=0;
}
void decompose(int u)
{
    dfs1(u);
    int sz=sub[u],ct = dfs2(u,u,sz);
    dist[0]++;
    visited[ct]++;
    for(auto it:g[ct])
    {
        if(!visited[it])
        {
            dfs4(it,1);
            dfs3(it,1);
        }
    }
    for(int i=0;dist[i];i++)dist[i]=0;
    for(auto it:g[ct])
    {
        if(!visited[it])decompose(it);
    }
}
void genPrime()
{
    for(int i=2;i<N;i++)
    {
        if(!chk[i])
        {
            P[len++]=i;
            for(int j=i;j<N;j+=i)chk[j]++;
        }
    }
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,u,v ;
    genPrime();
    cin >> n ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    decompose(1);
    cout << 1.0*ans/(1ll*n*(n-1)/2) ;
}
