#include<bits/stdc++.h>
using namespace std ;
const int N = 5009;
vector<int>path[N],pathre[N],pathcycle[N];
int pass[N],par[N],dag[N],rankk[N],rankpr[N];
queue<int>q;
stack<int> st;
void dfs(int i)
{
    vector<int>::iterator it ;
    pass[i]++;
    for(it=path[i].begin();it!=path[i].end();it++)
    {
        if(pass[*it]==0)dfs(*it);
    }
    st.push(i);
}
void dfsre(int i,int parent)
{
    vector<int>::iterator it;
    pass[i]++;
    par[i]=parent;
    for(it=pathre[i].begin();it!=pathre[i].end();it++)
    {
        if(pass[*it]==0)
        {
            dfsre(*it,parent);
        }
    }
}
main()
{
    vector<int>::iterator it;
    int n,m,u,v,i,j,x ;
    scanf("%d %d",&n,&m);
    while(m--)
    {
        scanf("%d %d",&u,&v);
        u++; v++;
        path[u].push_back(v);
        pathre[v].push_back(u);
    }
    for(i=1;i<=n;i++)
    {
        if(pass[i]==0)
        {
            dfs(i);
        }
    }
    for(i=1;i<=n;i++)pass[i]=0;
    while(!st.empty())
    {
        x=st.top();
        st.pop();
        if(pass[x]==0)dfsre(x,x);
    }
    for(i=1;i<=n;i++)
    {
        for(it=path[i].begin();it!=path[i].end();it++)
        {
            if(par[i]!=par[*it])
            {
                pathcycle[par[i]].push_back(par[*it]);
                dag[par[*it]]++;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        if(dag[i]==0&&par[i]==i)q.push(i),rankk[i]=1;
    }
    while(!q.empty())
    {
        x=q.front(); q.pop();
        for(it=pathcycle[x].begin();it!=pathcycle[x].end();it++)
        {
            dag[*it]--;
            rankk[*it]=max(rankk[*it],rankk[x]+1);
            if(dag[*it]==0)q.push(*it);
        }
    }
    for(i=1;i<=n;i++)
    {
        rankpr[rankk[par[i]]]++;
    }
    for(i=1;rankpr[i]!=0;i++)printf("%d ",rankpr[i]);

}
