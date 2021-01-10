#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 ;
vector<int> gc,g[N],eg[N];
int vst[N],depth[N],ans=0;
void dfs(int u,int cst)
{
    vst[u]=1;
    depth[u]=cst ;
    for(auto it:g[u])
    {
        if(vst[it]==0)dfs(it,cst+1);
        else ans=__gcd(ans,abs(cst-depth[it]+1));
    }
    for(auto it:eg[u])if(vst[it]==0)dfs(it,cst-1);
}
main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,u,v,i ;
    cin >> n >> m ;
    while(m--)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        eg[v].emplace_back(u);
    }
    for(i=1;i<=n;i++)if(vst[i]==0)dfs(i,1);
    if(ans==0)ans=n ;
    cout << ans ;
}
