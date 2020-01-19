#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 2e5+9 ;
vector<int> g[N];
stack<int> st ;
int deg[N],cst[N];
ll dp[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m ;
    cin >> n >> m ; 
    for(int i=1;i<=n;i++)
    {
        cin >> cst[i] ; 
    }
    for(int i=1,u,v ;i<=m;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        deg[u]++;
        deg[v]++;
    }
    int s ; 
    cin >> s; 
    g[s].emplace_back(s);
    deg[s]+=2;
    for(int i=1;i<=n;i++)
    {
        if(deg[i]==1)
        {
            st.push(i);
        }
    }
    ll mx = 0 ;
    while(!st.empty())
    {
        int u = st.top();
        st.pop();   
        for(auto it:g[u])
        {
            dp[it]=max(dp[it],dp[u]+cst[u]);
            deg[it]--;
            deg[u]--;
            if(deg[it]==1)
            {
                st.push(it);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(deg[i]>1)mx=max(mx,dp[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(deg[i]>1)mx+=cst[i];
    }
    cout << mx << '\n' ; 
    return 0 ;
}