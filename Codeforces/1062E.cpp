#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 , LOG=log2(N)+1;
vector<int> g[N];
int expo[N];
int up[N][LOG],dp[N][LOG],depth[N];
int tin[N],tout[N],times=0 ;
void dfs(int u,int v)
{
    up[u][0]=v; tin[u]=++times; depth[u]=depth[v]+1;
    for(int i=1;i<LOG;i++)up[u][i]=up[up[u][i-1]][i-1];
    for(auto it:g[u])if(it!=v)dfs(it,u);
    tout[u]=++times ;
}
bool Islca(int u,int v){return tin[u]<=tin[v]&&tout[u]>=tout[v]; }
int findlca(int u,int v)
{
    if(Islca(u,v))return u ;
    if(Islca(v,u))return v ;
    for(int i=LOG-1;i>=0;i--)if(!Islca(up[u][i],v))u=up[u][i];
    return up[u][0];
}
int nth(int u,int cnt)
{
    for(int i=0;i<LOG;i++)if(expo[i]&cnt)u=up[u][i];
    return u ;
}
int sparse(int l,int r)
{
    int len=r-l+1,log=log2(len);
    return findlca(dp[l][log],dp[r-expo[log]+1][log]);
}
void qans(int l,int r)
{
    int lca = sparse(l,r),x,u=l,v=r,y ;
    if(l+1==r)
    {
        if(depth[l]>depth[r])cout << r << " " << depth[l] << '\n' ;
        else cout << l << " " << depth[r] << '\n';
    }
    else if(lca==l)cout << l << " " <<  depth[sparse(l+1,r)] << '\n';
    else if(lca==r)cout << r << " " << depth[sparse(l,r-1)]<< '\n' ;
    else if(l<lca&&lca<r)cout << lca << " " <<
        depth[findlca(sparse(l,lca-1),sparse(lca+1,r))] << '\n';
    else
    {
        x=nth(l,depth[l]-depth[lca]-1);
        while(l+1<r)
        {
            int mid=l+r>>1 ;
            if(depth[sparse(u,mid)]<depth[x])r=mid ;
            else l=mid ;
        }
        y=l ;
        if(u==y)
        {
            int max1=depth[sparse(u+1,v)];
            int max2=depth[findlca(sparse(u+2,v),u)];
            if(max1>max2)cout << u << " " << max1 <<'\n';
            else cout << u+1 << " " << max2 << '\n' ;
        }
        else if(y==v-1)cout << v << " " << depth[sparse(u,v-1)]<<'\n';
        else cout <<  y+1 << " " <<
        depth[findlca(sparse(u,y),sparse(y+2,v))] << '\n';
    }
}
main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n,T,i,j,u,v ;
    cin >> n >> T ;
    for(i=2;i<=n;i++)cin >> u ,g[u].emplace_back(i) ;
    depth[1]=-1; expo[0]=1;dfs(1,1);
    for(i=1;i<LOG;i++)expo[i]=expo[i-1]<<1;
    for(i=1;i<=n;i++)dp[i][0]=i ;
    for(j=1;j<LOG;j++)for(i=1;i<=n&&i+expo[j]-1<=n;i++)
        dp[i][j]=findlca(dp[i][j-1],dp[i+expo[j-1]][j-1]);
    while(T--)cin>>u>>v,qans(u,v);
}
