#include<bits/stdc++.h>
using namespace std ;
const int N = 2e3+9 , LOG = log2(N)+1 , INF = 1e9 ; 
int m ;
int dp[N][N][2]; 
/// dp[i][j][k] -> devices i with state k (0 means connected to the top / 1 means connected to the bottom)  
/// j means the last node that have distinctive state with k  
struct tree
{
    int n ; 
    vector<int> g[N];
    int lca[N][N],up[N][LOG],leaf[N],depth[N],tin[N],tout[N],times=0;
    void dfs(int u,int v)
    {
        tin[u]=++times ;
        up[u][0]=v ; 
        depth[u]=depth[v]+1;
        for(int i=1;i<LOG;i++)
        {
            up[u][i]=up[up[u][i-1]][i-1];
        }
        for(auto it:g[u])
        {
            dfs(it,u);
        }
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
        for(int i=LOG-1;i>=0;i--)
        {
            if(!Islca(up[u][i],v))
            {
                u = up[u][i] ;
            }
        }
        return up[u][0] ; 
    }
    int dist(int u,int v)
    { 
        return depth[u]+depth[v]-2*depth[lca[u][v]];
    }
    void construct()
    { 
        cin >> n ; 
        for(int i=2,u ;i<=n;i++)
        {
            cin >> u ; 
            g[u].emplace_back(i);
        }
        for(int i=1;i<=m;i++)
        {
            cin >> leaf[i] ;
        }
        dfs(1,1);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                lca[i][j]=findlca(i,j);
            }
        }
    }

}ta,tb ;
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> m ;
    ta.construct();
    tb.construct();
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)dp[i][j][0]=dp[i][j][1]=INF ; 
    ta.leaf[0]=1;
    tb.leaf[0]=1;
    dp[1][0][0] = ta.dist(ta.leaf[1],1);
    dp[1][0][1] = tb.dist(tb.leaf[1],1);
    for(int i=2;i<=m;i++)
    {
        for(int j=0;j<i-1;j++)
        {
            //[0] -> [0]
            int itop = ta.leaf[i] , ibot = tb.leaf[i] ;
            int jtop = ta.leaf[j] , jbot = tb.leaf[j] ;
            int lcatop = ta.lca[itop][jtop];
            int lcabot = tb.lca[ibot][jbot];
            dp[i][j][0] = min(dp[i][j][0],dp[i-1][j][0]+ta.dist(itop,ta.lca[itop][ta.leaf[i-1]]));
            dp[i][j][1] = min(dp[i][j][1],dp[i-1][j][1]+tb.dist(ibot,tb.lca[ibot][tb.leaf[i-1]]));
            dp[i][i-1][1] = min(dp[i][i-1][1],dp[i-1][j][0]+tb.dist(ibot,lcabot));
            dp[i][i-1][0] = min(dp[i][i-1][0],dp[i-1][j][1]+ta.dist(itop,lcatop));
        }
    }
    int mn = INF ; 
    for(int i=0;i<m;i++)
    {
        mn = min({mn,dp[m][i][0],dp[m][i][1]});
    }
    cout << ta.n+tb.n-mn-2 ;
    return 0 ; 
}