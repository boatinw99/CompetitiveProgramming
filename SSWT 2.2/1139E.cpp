#include<bits/stdc++.h>
using namespace std ;
const int N = 5009 ;
int match[N],p[N],c[N],query[N],ans[N];
bool vst[N],ch[N];
vector<int> g[N];
int dfs0(int u)
{
    vst[u]++;
    for(auto it:g[u])
    {
        if(match[it]==-1||(!vst[match[it]]&&dfs0(match[it])))
        {
            match[it]=u ;
            return 1 ;
        }
    }
    return 0 ;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,i,j,q ;
    cin >> n >> m ;
    for(i=1;i<=n;i++)cin >> p[i];
    for(i=1;i<=n;i++)cin >> c[i] ;
    cin >> q;
    for(i=1;i<=q;i++)cin >> query[i],ch[query[i]]++;;
    int cur = 0 ;
    for(i=1;i<=n;i++)if(!ch[i])g[p[i]].emplace_back(c[i]);
    memset(match,-1,sizeof match);
    for(i=q;i>=1;i--)
    {
        while(cur<=m)
        {
            memset(vst,0,sizeof vst);
            if(dfs0(cur))cur++;
            else break;
        }
        ans[i]=cur ;
        g[p[query[i]]].emplace_back(c[query[i]]);
    }
    for(i=1;i<=q;i++)cout << ans[i] << '\n' ;
}
