#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+9 ; 
vector<int> g[N];
bool vst[N];
vector<int> V ; 
int euler[N<<1],ptr=0;
void dfs(int u,int v)
{
    vst[u]++;
    euler[++ptr]=u ; 
    for(auto it:g[u])
    {
        if(!vst[it])
        {
            dfs(it,u);
            euler[++ptr]=u;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,k ;
    cin >> n >> m >> k ;
    for(int i=1,u,v ;i<=m;i++)
    {
        cin >> u >> v; 
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1,1);
    int cnt = 0 ;
    for(int i=1;i<=ptr;i++)
    {
        V.push_back(euler[i]);
        if(V.size()==(2*n-1)/k+1||i==ptr)
        {
            cnt++;
            cout << V.size() << " " ;
            for(auto it:V)
            {
                cout << it << " ";
            }
            cout << '\n' ;
            V.clear();
        }
    }
    while(cnt<k)
    {
        cnt++;
        cout << "1 1" << '\n' ;
    }
    return 0 ;
}