#include<bits/stdc++.h>
using namespace std ;
const int N = 10009;
vector<pair<int,int> > path[N];
vector<pair<int,int> > ::iterator it ;
priority_queue<pair<int,pair<int,int> > > pq;
///val town min1ormin2
int dijk[N][2];
main()
{
    int n,m,i,j,u,v,edge,x,y,d,s,t,wi ;
    scanf("%d %d",&n,&m);
    scanf("%d %d",&s,&t);
    while(m--)
    {
        scanf("%d %d %d",&u,&v,&wi);
        path[u].push_back({v,wi});
    }
    pq.push({0,{s,0}});
    for(i=1;i<=n;i++)dijk[i][0]=dijk[i][1]=INT_MAX;
    dijk[s][0]=0;
    while(!pq.empty())
    {
        x=pq.top().first*-1;
        y=pq.top().second.first;
        d=pq.top().second.second;
        pq.pop();
        if(y==t&&d==1)
        {
            printf("%d",x);
            return 0;
        }
        if(dijk[y][d]==x)
        {
            if(d==0)
            {
                for(it=path[y].begin();it!=path[y].end();it++)
                {
                    if(it->second+x<dijk[it->first][0])
                    {
                        dijk[it->first][1]=dijk[it->first][0];
                        pq.push({-dijk[it->first][0],{it->first,1}});
                        dijk[it->first][0]=it->second+x;
                        pq.push({-it->second-x,{it->first,0}});
                    }
                    else if(it->second+x<dijk[it->first][1])
                    {
                        dijk[it->first][1]=it->second+x;
                        pq.push({-it->second-x,{it->first,1}});
                    }
                }
            }
            else if(d==1)
            {
                for(it=path[y].begin();it!=path[y].end();it++)
                {
                    if(it->second+x<dijk[it->first][1])
                    {
                        dijk[it->first][1]=it->second+x;
                        pq.push({-it->second-x,{it->first,1}});
                    }
                }
            }
        }
    }
}
