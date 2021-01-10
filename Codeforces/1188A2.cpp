#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
const int N = 1e3+9 ; 
vector<pii> g[N];
vector<pair<pii,int>> ans ;  
int rep[N],n,val[N],add[N]; 
void dfs0(int u,int v,int cst)
{
    val[u]=cst ;
    if(g[u].size()==1)
    {
        rep[u]=u ;
    }
    for(auto it:g[u])
    {
        if(it.fi!=v)
        {
            dfs0(it.fi,u,it.se);
            if(!rep[u])rep[u]=rep[it.fi];
        }
    }
}
void dfs1(int u,int v,int pz)
{
    if(g[u].size()==1)return ; 
    vector<int> V ;
    for(auto it:g[u])
    {
        if(it.fi!=v)
        {
            V.emplace_back(it.fi); 
        }
    }
    int sz = V.size();
    int tmp = 0 ;
    val[V[0]]+=add[u];
    add[V[0]]+=add[u];
    for(int i=0;i<sz;i+=2)
    {
        int x,y,z ;
        x=V[i],y=V[(i+1)%sz];
        if(sz>2)///use z 
        {
            z=V[(i+2)%sz];
        }
        else ///use pz  
        {
            z=pz ;
        }
        int vx=val[x],vy=val[y];
        int a = (vx-vy)/2;
        add[x]-=a;
        add[y]+=a;
        ans.push_back({{rep[x],rep[z]},-a});
        ans.push_back({{rep[y],rep[z]},a});
        add[x]+=-vx+a;
        add[y]+=-vx+a;
        ans.push_back({{rep[x],rep[y]},-vx+a});
        val[x]=0;
        val[y]=0;
    }
    for(int i=0;i<sz;i++)
    {
        dfs1(V[i],u,V[(i+1)%sz]);
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n ;
    for(int i=1,u,v,x ;i<n;i++)
    {
        cin >> u >> v >> x ; 
        g[u].emplace_back(v,x);
        g[v].emplace_back(u,x);
    }
    int root = 0 ;
    bool deg2 = 0 ;
    for(int i=1;i<=n;i++)
    {
        if(g[i].size()==2)
        {
            deg2++;
        }
        if(g[i].size()>2)root=i ;
    }
    if(deg2)
    {
        cout << "NO" << '\n' ; 
        return 0 ;
    }
    cout << "YES" << '\n' ;
    if(n==2)
    {
        cout << "1" << '\n' ;
        for(auto it:g[1])
        {
            cout << "1 " << it.fi << " " << it.se << '\n' ;
        }
        return 0 ;
    }
    dfs0(root,0,0);
    dfs1(root,0,0);
    cout << ans.size() << '\n' ;
    for(auto it:ans)
    {
        cout << it.fi.fi << " " << it.fi.se << " " << -it.se << '\n' ;
    }
    return 0 ;
}
