#include<bits/stdc++.h>
using namespace std ;
const int N = 200009;
vector<int>child[N];
vector<int>::iterator it ;
pair<int,int> path[N];
int hi[N];
pair<int,int> pathreal[N];
int s, a, b;
int dir() {
 int res = ((s & 8) >> 3);
 s = (s * a + b) % 40507;
 return res;
}
int dfs(int u,int par,int depth)
{
    child[par].push_back(u);
    hi[u]=depth;
    if(path[u].first!=-1&&path[u].second!=-1)
    {
        pathreal[par]={path[u].first,path[u].second};
        dfs(path[u].first,path[u].first,depth+1);
        dfs(path[u].second,path[u].second,depth+1);
    }
    else if(path[u].first!=-1)
    {
        dfs(path[u].first,par,depth+1);
    }
    else if(path[u].second!=-1)
    {
        dfs(path[u].second,par,depth+1);
    }
}
void findans(int u,int L)
{
    if(pathreal[u].first!=0&&hi[pathreal[u].first]<=L)
    {
        int res=dir();
        if(res==0)
        {
            findans(pathreal[u].first,L);
        }
        else findans(pathreal[u].second,L);
    }
    else
    {
        int x=hi[u];
        if(L-x+1>child[u].size())printf("%d\n",*child[u].rbegin());
        else printf("%d\n",child[u][L-x]);
        return ;
    }

}
main()
{
    int n,m,i,j,u,v,L ;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&u,&v);
        path[i]={u,v};
    }
    dfs(0,0,0);
    while(m--)
    {
        scanf("%d %d %d %d",&L,&s,&a,&b);
        findans(0,L);
    }
}
