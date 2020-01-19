#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 2e5+9 ,MIN = -1e9;
vector<pii> g[N];
priority_queue<pii> pq0,pq1,pq2,pq3;
int dp[N][4];
///dp0 -> red node
///dp1 -> blue node , change 2 child edge (red red) or (blue red);
///dp2 -> blue node , change child edge (red), parent edge(blue)
///dp3 -> blue node , change child edge (blue or red),parent edge(red)
void dfs(int u,int v,int cst)
{
    for(auto it:g[u])if(it.fi!=v)dfs(it.fi,u,it.se);
    for(auto it:g[u])
    {
        if(it.fi!=v)
        {
            int tmp = MIN;
            tmp=max(tmp,dp[it.fi][0]);
            tmp=max(tmp,dp[it.fi][3]);
            dp[u][0]+=tmp;
            ///
            tmp=MIN;
            tmp=max(tmp,dp[it.fi][0]);
            //tmp=max(tmp,dp[it.fi][1]);
            tmp=max(tmp,dp[it.fi][2]);
            dp[u][1]+=tmp;
            pq0.push({dp[it.fi][0]+it.se-tmp,it.fi});
            pq1.push({dp[it.fi][1]+it.se-tmp,it.fi});
            ///
            //tmp=MIN;
            //for(int i=0;i<3;i++)tmp=max(tmp,dp[it.fi][i]);
            tmp=max(tmp,dp[it.fi][0]);
            tmp=max(tmp,dp[it.fi][2]);
            dp[u][2]+=tmp;
            pq2.push({dp[it.fi][0]+it.se-tmp,it.fi});
            ///
            //tmp=MIN;
            //for(int i=0;i<3;i++)tmp=max(tmp,dp[it.fi][i]);
            dp[u][3]+=tmp;
            pq3.push({dp[it.fi][0]+it.se-tmp,it.fi});
            //pq3.push({dp[it.fi][1]+it.se-tmp,it.fi});
        }
    }
    if(pq0.size()>1)
    {
        int tmp=pq0.top().fi;
        if(pq0.top().se==pq1.top().se)
        {
            pq0.pop();
        }
        int mx1=0;
        mx1=max(pq0.top().fi+pq1.top().fi,mx1);
        pq1.pop();
        mx1=max(mx1,pq1.top().fi+tmp);
        mx1=max(mx1,tmp+pq0.top().fi);
        dp[u][1]+=mx1;
    }
   // else dp[u][1]=MIN;
    if(!pq2.empty())dp[u][2]+=pq2.top().fi+cst;
    if(!pq3.empty())dp[u][3]+=pq3.top().fi+cst;
    //printf("aaa %d | %d %d %d %d\n",u,dp[u][0],dp[u][1],dp[u][2],dp[u][3]);
    while(!pq0.empty())pq0.pop();
    while(!pq1.empty())pq1.pop();
    while(!pq2.empty())pq2.pop();
    while(!pq3.empty())pq3.pop();
}
main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int i,j,n,m,u,v,x ;
    cin >> n ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v >> x ;
        g[u].emplace_back(v,x);
        g[v].emplace_back(u,x);
    }
    dfs(1,0,MIN);
    cout << max(dp[1][0],dp[1][1]);
}
