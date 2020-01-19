#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
vector<int> path[N];
int a[N];
pair<int,int> dfs(int u,int v)
{
    int dist1=0,dist0=a[u];
    pair<int,int> pii;
    vector<int>::iterator it ;
    for(it=path[u].begin();it!=path[u].end();it++)
    {
        if(*it!=v)
        {
            pii=dfs(*it,u);
            dist1+=pii.second;
            dist0+=pii.first;
        }
    }
    dist0=max(dist0,dist1);
    //printf("%d->%d %d\n",u,dist1,dist0);
    return {dist1,dist0};
}
main()
{
    int n,i,j,u,v ;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&u,&v);
        path[u].push_back(v);
        path[v].push_back(u);
    }
    printf("%d",dfs(0,0).second);
}
