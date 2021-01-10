#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
vector<pii> g[N],gt[N];
struct edge
{
    int x,y,wi ; 
}E[N];
int deg[N],par[N];
int n,m,vst[N],processed[N];
//vector<int> V ; 
stack<int> st ;
vector<int> ans ; 
int dfs0(int u,int k)
{
    vst[u]=1;
    for(auto it:g[u])
    {
        if(it.se<=k)continue ; 
        if(vst[it.fi]==0)
        {
            par[it.fi]=par[u];
            int ret = dfs0(it.fi,k); 
            if(ret)return ret ; 
        }
        else if(vst[it.fi]==1)return 1 ;
    }
    vst[u]=2;
    return 0 ; 
}
bool check_SCC(int k)
{
    memset(vst,0,sizeof vst);
    memset(par,0,sizeof par);
    //V.clear();
    /// dfs0 will return 0 if there's no loop 
    for(int i=1;i<=n;i++)
    {
        if(par[i]==0)par[i]=i;
        if(vst[i]==0&&dfs0(i,k))return 1 ;
    }
    return 0 ;
}
void clear_st(int k)
{
    while(!st.empty())
    {
        int u = st.top();
        st.pop();
        processed[u]++;
        for(auto it:gt[u])
        {
            int idx = it.se ; 
            if(processed[it.fi])
            {
                ans.emplace_back(idx);
            }
            else if(E[idx].wi>k)
            {
                deg[it.fi]--;
                if(deg[it.fi]==0)
                {
                    st.push(it.fi);
                }
            }
        }
    }
}
void out(int k)
{
    for(int i=1;i<=m;i++)
    {
        gt[E[i].x].emplace_back(E[i].y,i);
        if(E[i].wi>k)
        {
            deg[E[i].y]++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(deg[i]==0&&!processed[i])
        {
     //       printf("check %d pls \n",i);
            st.push(i);
            clear_st(k);
        }
    }
    cout << k << " " << ans.size() << '\n' ;
    for(auto it:ans)
    {
        cout << it << " " ;
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m ;
    for(int i=1;i<=m;i++)
    {
        int u,v,wi ; 
        cin >> u >> v >> wi ; 
        g[u].emplace_back(v,wi);
        E[i]={u,v,wi};
    }
    int l = 0 , r = 1e9 ;
    while(l<r)
    {
        int mid = l+r>>1 ; 
        if(check_SCC(mid))l=mid+1;
        else r=mid ; 
    }
    out(r);
    return 0 ;
}