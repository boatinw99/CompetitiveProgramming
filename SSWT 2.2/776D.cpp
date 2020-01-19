#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 ;
int a[N],comp[N<<1];
bool vst[N<<1];
vector<int> swit[N],g[N<<1],gt[N<<1],order;
void dfs0(int u)
{
    vst[u]++;
    for(auto it:g[u])if(!vst[it])dfs0(it);
    order.emplace_back(u);
}
void dfs1(int u,int clr)
{
    comp[u]=clr;
    for(auto it:g[u])if(!comp[it])dfs1(it,clr);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    bool ans = 1 ;
    int n,m ;
    cin >> n >> m ;
    for(int i=1;i<=n;i++)cin >> a[i];
    for(int i=0;i<m;i++)
    {
        int x,u ;
        cin >> x ;
        while(x--)
        {
            cin >> u ;
            swit[u].emplace_back(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        int u = swit[i][0]*2, v = swit[i][1]*2;
        if(a[i]==0)
        {
            g[u|1].emplace_back(v);
            g[v|1].emplace_back(u);
            g[u].emplace_back(v|1);
            g[v].emplace_back(u|1);
        }
        else
        {
            g[u].emplace_back(v);
            g[v].emplace_back(u);
            g[u|1].emplace_back(v|1);
            g[v|1].emplace_back(u|1);
        }
    }
    for(int i=0;i<2*m;i++)if(!vst[i])dfs0(i);
    for(int i=0,j=1;i<2*m;i++)if(!comp[i])dfs1(i,j++);
    for(int i=0;i<2*m;i+=2)
    {
        if(comp[i]==comp[i|1])
        {
            ans=0;
            break;
        }
    }
    cout << (ans==1?"YES":"NO") << '\n' ;
    return 0 ;
}
