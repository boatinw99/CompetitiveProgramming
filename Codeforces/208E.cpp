#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9,LOG=log2(N);
vector<int> g[N];
vector<int> cls[N];
int up[N][LOG];
int depth[N],pos[N],tin[N],tout[N],times=0;
void dfs(int u)
{
    depth[u]=depth[up[u][0]]+1;
    pos[u]=cls[depth[u]].size();
    cls[depth[u]].emplace_back(u);
    tin[u]=++times;
    for(int i=1;i<LOG;i++)up[u][i]=up[up[u][i-1]][i-1];
    for(auto it:g[u])dfs(it);
    tout[u]=++times ;
}
bool Islca(int u,int v)
{
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
int findlca(int u,int v)
{
    if(Islca(u,v))return u ;
    if(Islca(v,u))return v;
    for(int i=LOG-1;i>=0;i--)if(!Islca(up[u][i],v))u=up[u][i];
    return up[u][0];
}
int qans(int u,int p)
{
    int tmp=depth[u],l=-1,r=pos[u],ans=0;
    if(depth[u]<=p)return 0;
    while(l+1<r)
    {
        int mid=l+r>>1;
        int lca=findlca(u,cls[tmp][mid]);
        if(lca!=0&&depth[u]-depth[lca]<=p)r=mid;
        else l=mid ;
    }
    ans+=pos[u]-r;
    l=pos[u],r=cls[tmp].size();
    while(l+1<r)
    {
        int mid=l+r>>1;
        int lca=findlca(u,cls[tmp][mid]);
        if(lca!=0&&depth[u]-depth[lca]<=p)l=mid;
        else r=mid ;
    }
    ans+=l-pos[u];
    return ans;
}
main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n,i,j,T,u,p ;
    cin >> n ;
    for(i=1;i<=n;i++)
    {
        cin >> up[i][0];
        g[up[i][0]].emplace_back(i);
    }
    depth[0]=-1;
    dfs(0);
    cin >> T ;
    while(T--)
    {
        cin >> u >> p ;
        cout << qans(u,p) << " ";
    }
}
