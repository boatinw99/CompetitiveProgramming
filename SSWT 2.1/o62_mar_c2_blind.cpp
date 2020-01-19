#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 20009 ;
vector<pii> edge ; /// edge
vector<int> cc[N];
stack<int> ans,st ;
vector<int> g[N]; ///directed edge
int par[N],rnk[N],in[N],out[N];
int find(int u){return u==par[u]?u:par[u]=find(par[u]); }
bool Union(int u,int v)
{
    int pu = find(u),pv=find(v);
    if(rnk[pu]>=rnk[pv])
    {
        rnk[pu]+=rnk[pv];
        par[pv]=pu ;
    }
    else
    {
        rnk[pv]+=rnk[pu];
        par[pu]=pv ;
    }
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,i,j,typ,u,v,a,b,c;
    cin >> n >> m ;
    for(i=1;i<=n;i++)par[i]=i;
    for(i=1;i<=m;i++)
    {
        cin >> typ >> a >> b >> c ;
        if(typ==3)
        {
            Union(a,b);
            Union(a,c);
        }
        else if(typ==1)
        {
            edge.emplace_back(a,b);
            edge.emplace_back(a,c);
        }
        else
        {
            edge.emplace_back(b,a);
            edge.emplace_back(c,a);
        }
    }
    for(i=1;i<=n;i++)cc[find(i)].emplace_back(i);
    for(i=1;i<=n;i++)sort(cc[i].begin(),cc[i].end());
    for(auto it:edge)
    {
        g[find(it.fi)].emplace_back(find(it.se));
        in[find(it.se)]++;
        out[find(it.fi)]++;
    }
    for(i=1;i<=n;i++)
    {
        if(par[i]==i&&in[i]==0)st.push(i);
    }
    while(!st.empty())
    {
        int x = st.top();
        st.pop();
        ans.push(x);
        for(auto it:g[x])
        {
            in[it]--;
            if(in[it]==0)st.push(it);
        }
    }
    cout << ans.size() << '\n' ;
    while(!ans.empty())
    {
        int x = ans.top();
        cout << cc[x].size() << " " ;
        for(auto it:cc[x])cout << it << " " ;
        cout << '\n' ;
        ans.pop();
    }


}
