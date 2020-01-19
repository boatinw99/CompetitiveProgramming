#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool b[200009];
vector<pair<int,int> >v[200009];
vector<pair<int,int> >::iterator it;
priority_queue<pair<int,int> >pq;
main()
{
    ll n,m,x,y,ti,i,count=0 ;
    scanf("%lld %lld",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%lld %lld %lld",&x,&y,&ti);
        v[x].push_back({y,ti});
        v[y].push_back({x,ti});
    }
    for(it=v[1].begin();it!=v[1].end();it++)
    {
        pq.push({it->second,it->first});
    }
    b[1]=1;
    while(!pq.empty())
    {
        x=pq.top().first;
        y=pq.top().second;
        pq.pop();
        if(!b[y])
        {
        b[y]=1,count+=x;
        for(it=v[y].begin();it!=v[y].end();it++)
        {
            if(b[it->first]==0)
            {
                pq.push({it->second,it->first});
            }
        }
        }
    }
    printf("%lld",count-n+1);
}
