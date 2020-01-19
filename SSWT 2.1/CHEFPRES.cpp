#include<bits/stdc++.h>
using namespace std ;
const int N = 1e4+9 , K = 109 , LOG = log2(N),MAX1=1e9;
int up[N][LOG+1] ;
int P[N][K],f[N];
int times=0,s,n,k ;
vector<int> G[N];
void dfs(int u,int v)
{
    up[u][0]=v;
    P[u][f[u]]=u;
    for(int i=1;i<=LOG;i++)
        up[u][i]=up[up[u][i-1]][i-1];
    for(auto it:G[u])
    {
        if(it!=v)
        {
            dfs(it,u);
            for(int i=1;i<=k;i++)
                P[u][i]=min(P[u][i],P[it][i]);
        }
    }
}
int findlca(int u,int type)
{
    if(P[u][type]<=n)return P[u][type] ;
    for(int i=LOG;i>=0;i--)
    {
        if(P[up[u][i]][type]>n)
        {
            u=up[u][i];
        }
    }
    if(P[up[u][0]][type]>n)return -1;
    return P[up[u][0]][type];
}
main()
{
    int i,j,u,v,p,T  ;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k  ;
    cin >> s ;
    for(i=1;i<=n;i++)for(j=1;j<K;j++)P[i][j]=MAX1 ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(i=1;i<=n;i++)cin >> f[i];
    dfs(s,s);
    cin >> T;
    while(T--)
    {
        cin >> u >> p ;
        cout << findlca(u,p) << '\n';
    }
}
