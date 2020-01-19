#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
typedef pair<ll,ll> pll ;
typedef pair<ll,int> pli ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
#define mid (l+r>>1)
const ll INF = 1e18 ; 
const int N = 1e5+9 , mod = 1e9+7 , inf = 2e9 ;
vector<int> g[N];
int color[N];
ll c[4][N];
ll dp[N][4][4];
int ed = 0 ,st=0 ;
void dfs0(int u,int v)
{
    int node = 0 ;
    for(auto it:g[u])
    {
        if(it!=v)node=it;
    }
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(i!=j)
            {
                dp[node][j][i^j]=dp[u][i][j]+c[i^j][node];
            }
        }
    }
    if(node)dfs0(node,u);
}
void traceback(int u,int v,int x,int y)
{
    ///x is color now , y is color right 
    color[u]=y ;
    if(u==st)return ;
    for(auto it:g[u])
    {
        if(it!=v)
        {
            traceback(it,u,x^y,x);
            return ;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        cin >> c[1][i];
    }
    for(int i=1;i<=n;i++)
    {
        cin >> c[2][i];
    }
    for(int i=1;i<=n;i++)
    {
        cin >> c[3][i];
    }
    for(int i=1,u,v ;i<n;i++)
    {
        cin >> u >> v; 
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        if(g[i].size()==1&&st==0)st=i;
        else if(g[i].size()==1)ed=i;
        if(g[i].size()>=3)
        {
            cout << "-1" << '\n' ;
            return 0 ;
        }
    }
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(i!=j)
            {
                dp[st][i][j]=c[j][st];
            }
        }
    }
    dfs0(st,st);
    pair<ll,pii> ans={INF,{0,0}} ;  
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(i!=j)
            {
                if(dp[ed][i][j]<ans.fi)
                {
                    ans={dp[ed][i][j],{i,j}};
                }
            }
        }
    }
    traceback(ed,ed,ans.se.fi,ans.se.se);
    cout << ans.fi << '\n' ;
    for(int i=1;i<=n;i++)
    {
        cout << color[i] << " " ;
    }
    return 0 ;
}