#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5 + 9 ;
bool b[N];
vector<int> path[N];
vector<int> color[2];
void dfs(int town,int p)
{
    vector<int>:: iterator it ;
    color[p].push_back(town); b[town]++;
    for(it=path[town].begin();it!=path[town].end();it++)
    {
        if(b[*it]==0)
        {
            dfs(*it,p^1);
        }
    }
}
main()
{
    int T,n,i,j,u,v,k ;
    vector<int>::iterator it;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=1;i<n;i++)
        {
            scanf("%d %d",&u,&v);
            path[u].push_back(v);
            path[v].push_back(u);
        }
        dfs(1,0);
        for(it=color[0].begin();it!=color[0].end();it++)
        {
            if(path[*it].size()<color[1].size())
            {
                j=*it;
                for(it=color[0].begin();it!=color[0].end();it++)
                {
                    if(*it!=j)printf("%d ",*it);
                }
                printf("%d ",j);
                sort(path[j].begin(),path[j].end());
                for(it=color[1].begin();it!=color[1].end();it++)
                {
                if(!binary_search   (path[j].begin(),path[j].end(),*it))
                    {
                        k=*it;
                        printf("%d ",k);
                        break;
                    }
                }
                for(it=color[1].begin();it!=color[1].end();it++)
                {
                    if(*it!=k)printf("%d ",*it);
                }
                printf("\n");
                break;
            }
        }
        if(it==color[0].end())printf("-1\n");
        for(i=1;i<=n;i++)
        {
            path[i].clear();
            b[i]=0;
        }
        color[0].clear(); color[1].clear();

    }
}
