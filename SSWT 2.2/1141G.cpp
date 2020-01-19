#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 2e5+9 ;
vector<pii> g[N];
vector<int> cc ;
int clr,ans[N];
void dfs0(int u,int v,int c)
{
    if(g[u].size()>clr)
    {
        for(auto it:g[u])
        {
            if(it.fi!=v)
            {
                ans[it.se]=c;
                dfs0(it.fi,u,c);
            }
        }
    }
    else
    {
        int nxtc = 0 ;
        for(auto it:g[u])
        {
            if(it.fi!=v)
            {
                nxtc++;
                if(nxtc==c)nxtc++;
                ans[it.se]=nxtc;
                dfs0(it.fi,u,nxtc);

            }
        }
    }
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,k,i,j,u,v ;
    cin >> n >> k ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v,i);
        g[v].emplace_back(u,i);
    }
    for(i=1;i<=n;i++)
    {
        cc.push_back(g[i].size());
    }
    sort(cc.begin(),cc.end());
    for(clr=1;;clr++)
    {
        auto it = upper_bound(cc.begin(),cc.end(),clr)-cc.begin()+1;
        if(n-it+1<=k)break;
    }
    for(i=1;i<=n;i++)
    {
        if(g[i].size()==clr)
        {
            dfs0(i,i,0);
            break;
        }
    }
    cout << clr << '\n' ;
    for(i=1;i<n;i++)cout << ans[i] << " " ;
}
