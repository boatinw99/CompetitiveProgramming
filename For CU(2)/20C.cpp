#include<bits/stdc++.h>
int s[100001]={0},s1[100001]={0}; 
using namespace std ;
void GodKong(long long a)
{
    if(a>1)
    {
    GodKong(s1[a]);
    printf("%I64d ",a);
    }
}
main()
{
    long long a,i,c,d,e,b,j,sum=0 ;
    priority_queue<pair<long long,long long> > pq ;
    scanf("%I64d %I64d",&a,&b);
    vector<vector<pair<long long,long long> > > v(a+2) ;
    vector<pair<long long,long long> >::iterator it ;
    for(i=0;i<b;i++)
    {
        cin >> c >> d >> e ;
        v[c].push_back({e*(-1),d});//e=???????
        v[d].push_back({e*(-1),c});
    }
    for(it=v[1].begin();it!=v[1].end();it++)
    {
        pq.push({it->first,it->second});
        s[it->second]=it->first ;
        s1[it->second] = 1;
    }
    while(!pq.empty())
    {
        for(it=v[pq.top().second].begin();it!=v[pq.top().second].end();it++)
        {
            if(it->first+pq.top().first > s[it->second]||s[it->second]==0)
            {
                s[it->second]=it->first + pq.top().first;
                pq.push({it->first+pq.top().first,it->second});
                s1[it->second]=pq.top().second;
            }
        }
        pq.pop();
    }
    //printf("%d %d %d",s1[0],s1[1],s1[2]);
    if(s1[a]==0)printf("-1");
    else
    {
        printf("1 ");
        GodKong(a);
    }
}
