#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
const int N = 1e5+9 ; 
map<int,int> par,sz,embodi;
map<int,int> pushed,deg;
vector<pair<int,pii>> alledge ; 
vector<pair<int,pii>> edgecycle ; 
vector<pair<int,pii>> ans ; 
vector<int> cc ; 
vector<int> nodes; 
int find(int u)
{
    return u==par[u]?u:par[u]=find(par[u]);
}
bool Union(int u,int v)
{
    u = find(u);
    v = find(v);
    if(u==v)return 0 ;
    if(sz[u]<sz[v])swap(u,v);
    sz[u]+=sz[v];
    par[v]=par[u];
    return 1 ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int T ; 
    cin >> T ; 
    while(T--)
    {
        int n ;
        par.clear();
        sz.clear();
        edgecycle.clear();
        alledge.clear();
        cc.clear();
        deg.clear();
        pushed.clear();
        nodes.clear();
        ans.clear();
        embodi.clear();
        cin >> n ;
        for(int i=1;i<=n;i++)
        {
            int u,v ;
            cin >> u >> v ;
            nodes.push_back(u);
            nodes.push_back(v);
            if(sz[u]==0)par[u]=u,sz[u]=1;
            if(sz[v]==0)par[v]=v,sz[v]=1;
            alledge.push_back({i,{u,v}});
            bool ret = Union(u,v);
            deg[u]++;
            deg[v]++;
            if(ret==0)
            {
                edgecycle.push_back({i,{u,v}});
            }
        }
        sort(nodes.begin(),nodes.end());
        nodes.resize(unique(nodes.begin(),nodes.end())-nodes.begin());
        for(auto it:nodes)
        {
            int i = it;
            if(deg[i]>=deg[embodi[find(i)]])
            {
                embodi[find(i)]=i;
            }
        }
        for(auto it:alledge)
        {
            int num = it.fi ;
            int u = it.se.fi;
            int v = it.se.se ;
            if(deg[u]==1)
            {
                edgecycle.push_back({num,{v,u}});
            }
            else if(deg[v]==1)
            {
                edgecycle.push_back({num,{u,v}});
            }
        }
        for(auto it:nodes)
        {
            int i = it ;
            if(pushed[find(i)]==0)
            {
                pushed[find(i)]=1;
                cc.push_back(find(i));
            }
        }
        for(auto it:edgecycle)
        {
            int num = it.fi;
            int u = it.se.fi,v = it.se.se ;
            int p = find(u);
            while(!cc.empty()&&find(cc.back())==p)
            {
                cc.pop_back(); 
            }
            if(cc.empty())break;
            int desti = cc.back();
            cc.pop_back();
            ans.push_back({num,{v,embodi[find(desti)]}});
            Union(p,embodi[find(desti)]);
        }
        cout << ans.size() << '\n' ;
        for(auto it:ans)
        {
            cout << it.fi << " " << it.se.fi << " " << it.se.se << '\n' ;
        }
    }
    return 0 ;
}