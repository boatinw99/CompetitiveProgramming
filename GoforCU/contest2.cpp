#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
int a[N];
int b[N];
vector<pair<int,int> > path[N];
vector<pair<int,int> > :: iterator it;
priority_queue<pair<int,int> > pq;
queue<int> q;
int max1=0,pr;
main()
{
    int n,m,s,t,i,j,x,y,u,v,T;
    scanf("%d %d",&n,&m);
    scanf("%d %d",&s,&t);
    for(i=0;i<=n;i++)a[i]=INT_MAX,b[i]=INT_MAX;
    while(m--)
    {
        scanf("%d %d %d",&u,&v,&T);
        path[u].push_back({v,T});
        path[v].push_back({u,T});
        pr+=T;
    }
    a[s]=0;
    pq.push({0,s});
    while(!pq.empty())
    {
        x=pq.top().first*-1;
        y=pq.top().second;
        pq.pop();
        if(a[y]==x)
        {
            for(it=path[y].begin();it!=path[y].end();it++)
            {
                if(x+it->second<a[it->first])
                {
                    a[it->first]=x+it->second;
                    pq.push({-x-it->second,it->first});
                }
            }
        }
    }
    b[t]=0;
    pq.push({0,t});
    while(!pq.empty())
    {
        x=pq.top().first*-1;
        y=pq.top().second;
        pq.pop();
        if(b[y]==x)
        {
            for(it=path[y].begin();it!=path[y].end();it++)
            {
                if(x+it->second<b[it->first])
                {
                    b[it->first]=x+it->second;
                    pq.push({-x-it->second,it->first});
                }
            }
        }
    }
    int max1=0;
    for(i=0;i<n;i++)
    {
        for(it=path[i].begin();it!=path[i].end();it++)
        {
            max1=max(max1,pr-a[i]-b[it->first]);
        }
    }
    printf("%d",max1);
}
