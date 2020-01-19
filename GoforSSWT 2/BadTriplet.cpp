#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 ;
vector<int> path[N];
bool b[N];
bool findpath(int u,int v)
{
    return binary_search(path[u].begin(),path[u].end(),v);
}
void dfs(int u,int cost,int pr)
{
    vector<int>::iterator it;
    b[u]++;
    if(cost%pr==0)
    {
        printf("%d ",u);
    }
    for(it=path[u].begin();it!=path[u].end();it++)
    {
        if(b[*it]==0)
        {
            dfs(*it,cost+1,pr);
        }
    }
}
main()
{
    int n,m,u,v,i,j,a,b,c,x  ;
    bool k;
    scanf("%d %d",&n,&m);
    x=m;
    while(m--)
    {
        scanf("%d %d",&u,&v);
        path[u].push_back(v);
        path[v].push_back(u);
    }
    for(i=1;i<=n;i++)
    {
        sort(path[i].begin(),path[i].end());
    }
    for(i=1;i<=n;i++)
    {
        if(path[i].size()>=3)
        {
            a=path[i][0];
            b=path[i][1];
            c=path[i][2];
            if(findpath(a,b))
            {
                printf("%d %d %d",a,b,i);
            }
            else if(findpath(a,c))
            {
                printf("%d %d %d",a,c,i);
            }
            else if(findpath(b,c))
            {
                printf("%d %d %d",b,c,i);
            }
            else
            {
                printf("%d %d %d",a,b,c);
            }
            return 0 ;
        }
    }
    if(x==n&&n%3==0)
    {
        dfs(1,1,n/3);
        return 0 ;
    }
    printf("-1");
}
