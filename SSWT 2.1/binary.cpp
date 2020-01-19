#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 ;
priority_queue<int,vector<int>,greater<int> > pq ;
vector<int> g[N];
int dp[N];
void dfs(int u)
{
    for(auto it:g[u])dfs(it);
    for(auto it:g[u])pq.push(dp[it]);
    if(pq.empty())return ;
    if(pq.size()<=2&&!pq.empty())
    {
        while(pq.size()>1)pq.pop();
        dp[u]=pq.top()+1;
        pq.pop();
        return ;
    }
    while(pq.size()>2)
    {
        pq.pop();
        pq.push(pq.top()+1);
        pq.pop();
    }
    pq.pop();
    dp[u]=pq.top()+1 ;
    //printf("aaa %d %d\n",u,dp[u]);
    pq.pop();
}
main()
{
    int n,i,j,m,x ;
    cin >> n ;
    for(i=2;i<=n;i++)
    {
        cin >> x ;
        g[x].emplace_back(i);
    }
    dfs(1);
    cout << dp[1] ;
}
