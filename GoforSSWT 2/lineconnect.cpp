#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
pair<int,int> a[N];
int component[N];
vector<int>path[N];
void dfs(int u,int v)
{
    vector<int>::iterator it ;
    component[u]++;
    for(it=path[u].begin();it!=path[u].end();it++)
    {
        if(*it!=v)
        {
            dfs(*it,u);
        }
    }
}
main()
{
    int n,i,j,u,v;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i].first);
        a[i].second=i;
    }
    sort(a+1,a+1+n);
    for(i=1;i<=n-2;i++)
    {
        scanf("%d %d",&u,&v);
        path[u].push_back(v);
        path[v].push_back(u);
    }
    dfs(a[1].second,1);
    int ans=INT_MAX;
    for(i=1;i<n;i++)
    {
        if(component[a[i].second]^component[a[i+1].second])
        {
            ans=min(ans,a[i+1].first-a[i].first);
        }
    }
    printf("%d",ans);
}
