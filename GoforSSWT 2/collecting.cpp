#include<bits/stdc++.h>
using namespace std ;
const int N = 50009;
int dijk[N][39];
int a[N];
vector<pair<int,int> > path[N];
vector<pair<int,int> > ::iterator it ;
priority_queue<pair<int,pair<int,int> > >pq;
main()
{
    int n,m,L,s,t,u,v,wi,i,j,x,y,d ;
    scanf("%d %d %d",&n,&m,&L);
    scanf("%d %d",&s,&t);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    while(m--)
    {
        scanf("%d %d %d",&u,&v,&wi);
        path[u].push_back({v,wi});
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=L+1;j++)
        {
            dijk[i][j]=INT_MAX;
        }
    }
    dijk[s][0]=0;
    pq.push({0,{s,0}});
    while(!pq.empty())
    {
        x=pq.top().first*-1;
        y=pq.top().second.first;
        d=pq.top().second.second;
        pq.pop();
        if(y==t&&d==L)
        {
            printf("%d",x);
            return 0;
        }
        if(dijk[y][d]==x)
        {
            for(it=path[y].begin();it!=path[y].end();it++)
            {
                if(a[it->first]==d+1&&
                   x+it->second<dijk[it->first][d+1])
                {
                    dijk[it->first][d+1]=x+it->second;
                    pq.push({-x-it->second,{it->first,d+1}});
                }
                else if(a[it->first]!=d+1&&
                   x+it->second<dijk[it->first][d])
                {
                    dijk[it->first][d]=x+it->second;
                    pq.push({-x-it->second,{it->first,d}});
                }
            }
        }

    }
    printf("-1");
}
