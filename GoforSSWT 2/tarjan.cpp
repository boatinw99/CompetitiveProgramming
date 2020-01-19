#include<bits/stdc++.h>
using namespace std ;
const int N = 50;
int times=0;
int dist[N],low[N],par[N],ans[N];
vector<int>path[N];
vector<int>::iterator it ;
void dfs(int u,int v)
{
    vector<int>::iterator it ;
    int child=0;
    times++;
    dist[u]=low[u]=times;
    for(it=path[u].begin();it!=path[u].end();it++)
    {
        if(dist[*it]==0)
        {
            child++;
            par[*it]=u;
            dfs(*it,u);
            low[u]=min(low[u],low[*it]);
            //printf("aaa %d %d||%d %d\n",u,*it,dist[u],low[*it]);
            if(dist[u]<low[*it])
            {
                printf("bridge -> %d %d\n",u,*it);
            }
            if(par[u]!=0&&dist[u]<=low[*it])
            {
                ans[u]++;
            }
            else if(par[u]==0&&child>=2)
            {
                ans[u]++;
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
    int n,m,i,j,u,v ;
    scanf("%d %d",&n,&m);
    while(m--)
    {
        scanf("%d %d",&u,&v);
        path[u].push_back(v);
        path[v].push_back(u);
    }
    for(i=1;i<=n;i++)
    {
        if(dist[i]==0)
        {
            dfs(i,i);
        }
    }
    for(i=1;i<=n;i++)
    {
        if(ans[i]!=0)printf("%d ",i);
    }
}
