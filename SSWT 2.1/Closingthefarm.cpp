#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+9 ;
stack<int> st;
stack<int> ans ;
vector<int> g[N];
int cnt=0,rnk[N],par[N] ;//component ;
bool vst[N];
int find(int u){return u==par[u]?u:par[u]=find(par[u]);}
void Union(int x,int y)
{
    int px=find(x),py=find(y);
    if(px==py)return ;
    cnt--;
    if(rnk[x]>=rnk[y])
    {
        rnk[x]+=rnk[y];
        par[py]=x;
    }
    else
    {
        rnk[y]+=rnk[x];
        par[px]=y;
    }
}
void update(int u)
{
    cnt++;
    vst[u]++;
    par[u]=u;
    for(auto it:g[u])if(vst[it]==1)Union(u,it);
}

main()
{
    int n,m,u,v,i,j ;
    cin >> n >> m ;
    while(m--)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for(i=1;i<=n;i++)
    {
        cin >> u ;
        st.push(u);
    }
    while(!st.empty())
    {
        update(st.top());
        st.pop();
        ans.push(cnt);
    }
    while(!ans.empty())
    {
        if(ans.top()==1)cout << "YES" << '\n' ;
        else cout << "NO" << '\n' ;
        ans.pop();
    }
}
