#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
vector<pair<int,int> > v[N];
vector<pair<int,int> > ::iterator it;
priority_queue<pair<int,int> > pq;
int pr= 0;
int a[N];
bool b[N];
main()
{
    int n,m,i,j,val,x,y ;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    while(m--)
    {
        scanf("%d %d",&x,&y);
        v[x].push_back({y,a[x]+a[y]});
        v[y].push_back({x,a[x]+a[y]});
    }
    pq.push({0,1});
    while(!pq.empty())
    {
        x=pq.top().first;
        y=pq.top().second;
        pq.pop();
        if(!b[y]++)
        {
            pr+=x;
            for(it=v[y].begin();it!=v[y].end();it++)
            {
                if(!b[it->first])
                pq.push({it->second,it->first});
            }
        }
    }
    printf("%d",pr);
}
