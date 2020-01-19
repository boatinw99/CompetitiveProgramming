#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+9+40 , K = 50 ;
vector<int> g[N],gt[N],order;
vector<int> gt1[N];
char s[N][K];
int comp[N],in[N];
bool vst[N];
void dfs0(int u)
{
    vst[u]++;
    for(auto it:g[u])if(!vst[it])dfs0(it);
    order.push_back(u);
}
void dfs1(int u,int clr)
{
    comp[u]=clr;
    for(auto it:gt[u])if(comp[it]==0)dfs1(it,clr);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,k ;
    cin >> n >> k ;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            cin >> s[i][j];
            if(s[i][j]=='1')
            {
                g[i].emplace_back(n+j);
                gt[n+j].emplace_back(i);
                in[n+j]++;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(s[i][j]=='0')
            {
                if(in[n+j])
                {
                    g[n+j].emplace_back(i);
                    gt[i].emplace_back(n+j);
                }
            }
        }
    }
    memset(in,0,sizeof in);
    for(int i=1;i<=n+k;i++)if(!vst[i])dfs0(i);
    for(int i=n-1+k,j=1;i>=0;i--,j++)
    {
        int u = order[i];
        if(!comp[u])dfs1(u,j++);
    }
    for(int i=1;i<=n+k;i++)
    {
        for(auto it:g[i])
        {
            if(comp[i]!=comp[it])
            {
                gt1[comp[i]].emplace_back(comp[it]);
                in[comp[it]]++;
            }
        }
    }
    int root = 0 ;
    for(int i=1;i<=n;i++)
    {
        if(in[comp[i]]==0)
        {
            if(root!=comp[i]&&root!=0)
            {
                root=-1;
                break;
            }
            root=comp[i] ;
        }
    }
    if(root==-1)
    {
        cout << root << '\n' ;
        return 0 ;
    }
    for(int i=1;i<=n;i++)if(comp[i]==root)cout << i << " " ;
    return 0 ;
}
