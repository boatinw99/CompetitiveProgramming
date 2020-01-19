#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
int a[N],b[N],pos[N];
int color[N],path[N];
bool dfs(int u)
{
    color[u]=1;
    bool q = 0 ;
    if(a[u]!=0)
    {
        if(color[path[u]]==1&&path[u]!=u)
        {
            q=1;
        }
        else if(path[u]==u);
        else q=dfs(path[u]);
    }
    color[u]=2;
   // printf("%d->%d\n",u,q);
    return q;
}
main()
{
    int T,n,m,i,j,x,y ;
    bool con,q ;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        con=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            pos[a[i]]=i;
            color[i]=0;
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
            path[pos[b[i]]]=i;
        }
        q=0;
        for(i=1;i<=n;i++)
        {
            if(color[i]==0)q = dfs(i);
            if(q==1)break;
        }
        if(q==1)printf("NO\n");
        else printf("YES\n");
    }
}
