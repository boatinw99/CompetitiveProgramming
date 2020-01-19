#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 2e5+9 ;
vector<pair<pii,bool> > g[N];
vector<int> ans ;
int chose[N];
int cst[N],cnt=0;
pair<pii,bool> edge[N];
void dfs(int u)
{
    while(!g[u].empty()&&edge[g[u].back().fi.fi].se)g[u].pop_back();
    if(g[u].empty())return ;
    edge[g[u].back().fi.fi].se=1;
    auto it = g[u].back();
    g[u].pop_back();
    if(it.fi.se!=edge[it.fi.fi].fi.se)
    {
        ans.push_back(it.fi.fi);
        cnt+=cst[it.fi.fi];
    }
    dfs(it.fi.se);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,i,j,u,v,x,all=0  ;
    cin >> n >> m ;
    for(i=1;i<=m;i++)
    {
        cin >> edge[i].fi.fi>> edge[i].fi.se >> cst[i] ;
        g[edge[i].fi.fi].push_back({{i,edge[i].fi.se},0});
        g[edge[i].fi.se].push_back({{i,edge[i].fi.fi},0});
        all+=cst[i];
    }
    for(i=1;i<=n;i++)
    {
        if(!g[i].empty())
        {
            dfs(i);
        }
    }
    int num = 0 ;
    if(cnt<=all/2)
        for(auto it:ans)chose[it]=1,num++;
    else
    {
        num=m ;
        for(i=1;i<=m;i++)chose[i]=1;
        for(auto it:ans)chose[it]=0,num--;
    }
    cout << num << '\n' ;
    for(i=1;i<=m;i++)
    {
        if(chose[i]==1)
        {
            cout << i << '\n' ;
        }
    }
}
