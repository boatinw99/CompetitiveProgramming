#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 2e5+9 ;
vector<int> g[N];
int a[N],dp[N],clr[N];
bool vst[N];
int st=0,ed=0;
void dfs0(int u,int v)
{
    vst[u]++;
    for(auto it:g[u])
    {
        if(it!=v&&vst[it]==0)
        {
            dfs0(it,u);
        }
        else if(it!=v&vst[it]==1)
        {
            st=it;
            ed=u;
            return ;
        }
        if(st)return ;
    }
}
pii dfs1(int u)///sum,ans
{
    vst[u]++;
    pii ans0[2]={{0,0},{0,0}};
    pii mx0[2]={{0,0},{0,0}};
    for(auto it:g[u])
    {
        if(vst[it]==0)
        {
            pii tmp=dfs1(it);
            if(clr[it]==0)
            {
                ans0[0].se=max(ans0.se,ans0);
                mx[0]
            }

            clr[u]=max(clr[u],clr[it]);
        }
    }
}
main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n,i,j,u,v ;
    cin >> n ;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(i=1;i<=n;i++)
    {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs0(0,0);
    clr[st]=1,clr[ed]=1;
    memset(vst,0,sizeof vst);
    dfs1(st);

}
