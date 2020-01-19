#include<bits/stdc++.h>
using namespace std ;
const int N = 50009 ;
vector<pair<int,pair<int,int> > > path[N];
vector<pair<int,pair<int,int> > > ::iterator it ;
priority_queue<pair<int,int> > pq;
int dijks[N];
void dijkstra(int mid,int n)
{
    pq.push({0,1});
    int x,y,i;
    for(i=1;i<=n;i++)dijks[i]=INT_MAX;
    dijks[1]=0;
    while(!pq.empty())
    {
        x=pq.top().first*-1;
        y=pq.top().second;
        pq.pop();
        if(dijks[y]>x)continue;
        for(it=path[y].begin();it!=path[y].end();it++)
        {
            if(x+it->second.first<dijks[it->first]&&
               it->second.second<=mid)
            {
                dijks[it->first]=x+it->second.first;
                //printf("%d->%d %d\n",y,it->first,it->second.first);
                pq.push({-x-it->second.first,it->first});
            }
        }
    }
}
main()
{
    int n,m,k,u,v,i,j,wi ;
    scanf("%d %d %d",&n,&m,&k);
    int l=0,r=m+1;
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&u,&v,&wi);
        path[u].push_back({v,{wi,i}});
        path[v].push_back({u,{wi,i}});
    }
    while(l+1<r)
    {
        int mid=l+r>>1;
        dijkstra(mid,n);
        //printf("aaa %d %d\n",mid,dijks[n]);
        if(dijks[n]<=k)
        {
            r=mid;
        }
        else l=mid;
        //return 0;
    }
    if(r>m)printf("-1");
    else
    printf("%d",r);

}
