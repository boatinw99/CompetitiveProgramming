#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+9 , K=7 , mod = 10007 ;
vector<int> g[N];
int dp[N][65],k,tmp[65],comb[100][100],fact[40];
bool Isleaf[N];
inline void merge(int v,int u,int sz)
{
    int sz1=k;
    if(Isleaf[u])sz1=1;
    for(int i=0;i<=sz1;i++)///dp[u][i]
    {
        for(int mp=0;mp<=i;mp++)///make pair -> mp pairs
        {
            for(int j=mp;j<=sz;j++)
            {
                tmp[j+i-2*mp]+=(1ll*dp[u][i]*dp[v][j]%mod)*
                    (1ll*comb[i][mp]*comb[j][mp]*fact[mp]%mod)%mod;
                tmp[j+i-2*mp]%=mod;
            }
        }
    }
}
void dfs0(int u,int v)
{
    if(g[u].size()==1)
    {
        Isleaf[u]++;
        dp[u][1]=1;
        return ;
    }
    dp[u][0]=1;
    int sz = 0 ;
    for(auto it:g[u])if(it!=v)dfs0(it,u);
    for(auto it:g[u])
    {
        if(it!=v)
        {
            merge(u,it,sz);
            if(Isleaf[it])sz++;
            else sz+=k;
            sz=min(sz,35);
            for(int i=0;i<=sz;i++)dp[u][i]=tmp[i],tmp[i]=0;
        }
    }
}
void preprocess()
{
    comb[0][0]=1;
    for(int i=1;i<50;i++)
    {
        comb[i][0]=1;
        for(int j=0;j<=i;j++)comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%mod;
    }
    fact[0]=1;
    for(int i=1;i<10;i++)fact[i]=fact[i-1]*i%mod;
}
int main()
{
    int n,m ;
    preprocess();
    cin >> n >> m >> k ;
    for(int i=1;i<n+m;i++)
    {
        int u,v ;
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int root = 0 ;
    for(int i=1;i<=n+m&&!root;i++)if(g[i].size()>1)root=i;
    dfs0(root,root);
    cout << dp[root][0];
    return 0 ;
}
