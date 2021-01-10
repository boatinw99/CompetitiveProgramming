#include<bits/stdc++.h>
using namespace std ;
const int N = 209 ;
vector<int> g[N],topo,ans;
bool vst[N];
int cc[N],id=1;
stack<int> fnsh ;
void dfs(int u,bool mul)
{
    vst[u]++;
    for(auto it:g[u])if(!vst[it])dfs(it,mul);
    if(mul)cc[u]=id ;
    else topo.push_back(u),fnsh.push(u);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,i,j,u,v,x ;
    cin >> n >> m ;
    while(m--)
    {
        cin >> u >> v >> x ;
        u<<=1,v<<=1;
        if(x)
        {
            g[u].push_back(v);
            g[v].push_back(u);
            g[u^1].push_back(v^1);
            g[v^1].push_back(u^1);
        }
        else
        {
            g[u^1].push_back(v);
            g[v].push_back(u^1);
            g[u].push_back(v^1);
            g[v^1].push_back(u);
        }
    }
    for(i=2;i<=n*2;i++)if(!vst[i])dfs(i,0);
    memset(vst,0,sizeof vst);
    while(!fnsh.empty())
    {
        if(!vst[fnsh.top()])id++,dfs(fnsh.top(),1);
        fnsh.pop();
    }
    for(i=2;i<=n*2;i++)
    {
        if(cc[i]==cc[i^1])
        {
            cout << "Impossible" ;
            return 0 ;
        }
    }
    memset(vst,0,sizeof vst);
    for(auto it:topo)
    {
        if(!vst[it>>1]++)
        {
            if(!(it&1))ans.push_back(it/2);
        }
    }
    cout << ans.size() << '\n' ;
    for(auto it:ans)cout << it << " " ;
}
