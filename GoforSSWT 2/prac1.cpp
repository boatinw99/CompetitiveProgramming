///SCC kosaraju
#include<bits/stdc++.h>
using namespace std;
const int N = 500;
vector<int>path[N],pathre[N];
bool visited[N];
stack<int> st;
void dfs(int u)
{
    vector<int>::iterator it ;
    visited[u]++;
    for(it=path[u].begin();it!=path[u].end();it++)
    {
        if(visited[*it]==0)
        {
            dfs(*it);
        }
    }
    st.push(u);
}
void dfsre(int u)
{
    vector<int>::iterator it ;
    visited[u]++;
    for(it=pathre[u].begin();it!=pathre[u].end();it++)
    {
        if(visited[*it]==0)
        {
            dfsre(*it);
        }
    }
}
main()
{
    int n,m,i,j,u,v,ans=0 ;
    scanf("%d %d",&n,&m);
    while(m--)
    {
        scanf("%d %d",&u,&v);
        path[u].push_back(v);
        pathre[v].push_back(u);
    }
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)dfs(i);
    }
    for(i=1;i<=n;i++)visited[i]=0;
    while(!st.empty())
    {
        if(visited[st.top()]==0)
        {
            dfsre(st.top());
            printf("par = %d \n",st.top());
            ans++;
        }
        st.pop();
    }
    printf("all = %d",ans);
}
