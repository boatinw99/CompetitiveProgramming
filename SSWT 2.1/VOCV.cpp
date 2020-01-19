#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+19,md=1e4+7,MAX=1e9+7;
int dp1[N],dp2[N];
int cnt1[N],cnt2[N];
vector<int> g[N];
void re()
{
    for(int i=0;i<N;i++)g[i].clear();
}
void dfs(int u,int v)
{
    dp1[u]=1;
    dp2[u]=0;
    cnt1[u]=1;
    cnt2[u]=1;
    for(auto it:g[u])
    {
        if(it!=v)
        {
            dfs(it,u);
            if(dp1[it]==dp2[it])
            {
                cnt2[it]=(cnt2[it]+cnt1[it])%md;
            }
            if(dp2[it]==MAX)dp2[it]=dp1[it],cnt2[it]=cnt1[it];
            dp1[u]+=dp2[it];
            dp2[u]+=dp1[it];
            cnt1[u]=cnt1[u]*cnt2[it]%md;
            cnt2[u]=cnt2[u]*cnt1[it]%md;
        }
    }
    if(dp2[u]>dp1[u])dp2[u]=MAX,cnt2[u]=0;
}
main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n,T,i,j,u,v ;
    cin >> T ;
    while(T--)
    {
        re();
        cin >> n;
        for(i=1;i<n;i++)
        {
            cin >> u >> v ;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        dfs(1,0);
        u=1;
        if(dp1[u]<dp2[u])
        {
            cout << dp1[u] << " " << cnt1[u] << '\n' ;
        }
        else if(dp2[u]<dp1[u])
        {
            cout << dp2[u] << " " << cnt2[u] << '\n' ;
        }
        else
        {
            cout << dp1[u] << " " << (cnt1[u]+cnt2[u])%md << '\n' ;
        }
    }
}
