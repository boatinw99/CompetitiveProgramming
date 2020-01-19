//TarJan's
#include<bits/stdc++.h>
using namespace std ;
vector<int> path[199];
int times=0;
int dist[199],low[199],parent[199];
bool b[199];
void dfs(int u,int v)
{
    int child = 0;
    dist[u]=low[u]=++times;
    vector<int>::iterator it;
    for(it=path[u].begin();it!=path[u].end();it++)
    {
        if(dist[*it]==0)
        {
            parent[*it]=u;
            child++;
            dfs(*it,u);
            low[u]=min(low[*it],low[u]);
            if(parent[u]==0&&child>1)b[u]++;
            else if(parent[u]!=0&&dist[u]<low[*it])b[u]++;
            if(dist[u]<low[*it])
            {
                printf("%d %d\n",u,*it);
            }
        }
        else if(*it!=v)
        {
            low[u]=min(low[u],dist[*it]);
        }
    }
}
main()
{
    int n,m,u,v,i,j ;
    scanf("%d %d",&n,&m);
    while(m--)
    {
        scanf("%d %d",&u,&v);
        path[u].push_back(v);
        path[v].push_back(u);
    }
    dfs(1,1);
    printf("\n");
    for(i=1;i<=n;i++)
    {
        if(b[i])printf("%d ",i);
    }
}
