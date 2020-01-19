#include<bits/stdc++.h>
using namespace std ;
const int N = 1e4+9 ;
vector<int> g[N];
vector<int> ans[N];
int str[N],sz=0;
void re1()
{
    for(int i=0;i<N;i++)g[i].clear();
    for(int i=0;i<N;i++)ans[i].clear();
    for(int i=0;i<N;i++)str[i]=0;
    sz=0 ;
}
void dfs2(int u,int typ)
{
    if(typ==1)ans[sz].emplace_back(u);
    if(str[u]!=0&&str[u]!=u)dfs2(str[u],typ);
    str[u]=0;
    if(typ==-1)ans[sz].emplace_back(u);
}
void dfs1(int u,int v)
{
    int chk=0 ;
    for(auto it:g[u])
    {
        if(it!=v)
        {
            dfs1(it,u);
            if(str[it]==0);
            else if(chk==0)str[u]=it,chk=1;
            else if(chk==1)
            {
                chk=2;
                dfs2(it,-1);
                dfs2(u,1);
                sz++;
            }
            else
            {
                dfs2(it,1);
                sz++;
            }
        }
    }
    if(chk==0)str[u]=u ;
}
main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int T,n,i,j,u,v ;
    cin >> T ;
    for(j=1;j<=T;j++)
    {
        re1();
        cin >> n ;
        for(i=1;i<n;i++)
        {
            cin >> u >> v ;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        dfs1(1,0);
        if(str[1])dfs2(1,-1),sz++;
        cout << sz << '\n' ;
        for(i=0;i<sz;i++)
        {
            for(auto it:ans[i])cout << it << " " ;
            cout << '\n' ;
        }
        cout << '\n' ;
    }
}
