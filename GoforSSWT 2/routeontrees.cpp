#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
vector<pair<int,int> > path[N];
vector<pair<int,int> > ::iterator it ;
priority_queue<pair<int,pair<int,int> > > pq;
int dijk[N][6];
main()
{
    int n,m,k,i,j,u,v,wi,x,y,d ;
    scanf("%d %d %d",&n,&m,&k);
    while(m--)
    {
        scanf("%d %d %d",&u,&v,&wi);
        path[u].push_back({v,wi});
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=k;j++)dijk[i][j]=INT_MAX;
    }
    pq.push({0,{1,0}});//x y k
    dijk[1][0]=0;
    while(!pq.empty())
    {
        x=pq.top().first*-1;
        y=pq.top().second.first;
        d=pq.top().second.second;
        pq.pop();
        if(y==n)
        {
            printf("%d",x);
            return 0 ;
        }
        if(dijk[y][d]==x)
        {
            //printf("%d->%d %d\n",x,y,d);
            for(it=path[y].begin();it!=path[y].end();it++)
            {
                if(it->second<-100)
                {
                    if(d<k&&x<dijk[it->first][d+1])
                    {
                        dijk[it->first][d+1]=x;
                        pq.push({-x,{it->first,d+1}});
                    }
                }
                else
                {

                    wi=max(it->second,0);
                    if(x+wi<dijk[it->first][d])
                    {
                        dijk[it->first][d]=x+wi;
                        pq.push({-x-wi,{it->first,d}});
                    }
                }
            }
        }
    }
    printf("-1");
}
