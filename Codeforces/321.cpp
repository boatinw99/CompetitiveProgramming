#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 ;
vector<int> g[N];
int sub[N];
char ans[N];
bool vst[N];
void dfs1(int u)
{
    sub[u]=1;
    vst[u]++;
    for(auto it:g[u])if(!vst[it])dfs1(it),sub[u]+=sub[it];
    vst[u]=0;
}
int dfs2(int u,int v,int sz)
{
    for(auto it:g[u])if(it!=v&&!vst[it]&&sub[it]>sz/2)
        return dfs2(it,u,sz);
    return u ;
}
void decompose(int u,int rnk)
{
    dfs1(u);
    int ctd = dfs2(u,u,sub[u]);
    ans[ctd]='A'+rnk;
    vst[ctd]++;
    for(auto it:g[ctd])
    {
        if(!vst[it])decompose(it,rnk+1);
    }
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,u,v ;
    cin >> n ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    decompose(1,0);
    for(i=1;i<=n;i++)cout << ans[i] << " " ;
}
