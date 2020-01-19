#include<bits/stdc++.h>
using namespace std ;
const int N = 5009;
vector<pair<int,int> > path[N],Q;
vector<pair<int,int> > ::iterator it ;
int query[N];
bool b[N];
priority_queue<pair<int,int> > pq ;
priority_queue<int> ans ;
main()
{
    int n,m,q,u,v,val,x,town,i,j ;
    scanf("%d %d %d",&n,&m,&q);
    while(m--)
    {
        scanf("%d %d %d",&u,&v,&val);
        path[u].push_back({v,val});
        path[v].push_back({u,val});
    }
    for(i=1;i<=q;i++)
    {
        scanf("%d",&x);
        Q.push_back({x,i});
    }
    sort(Q.begin(),Q.end());
    ///MST
    pq.push({0,1});
    while(!pq.empty())
    {
        val=pq.top().first*-1; town=pq.top().second;
        pq.pop();
        if(!b[town]++)
        {
            ans.push(val);
            for(it=path[town].begin();it!=path[town].end();it++)
            {
                if(!b[it->first])
                {
                    pq.push({-it->second,it->first});
                }
            }
        }
    }
    for(it=Q.begin();it!=Q.end();it++)
    {
        while(n-it->first<ans.size()-1)
        {
            ans.pop();
        }
        query[it->second]=ans.top();
    }
    for(i=1;i<=q;i++)printf("%d\n",query[i]);
}
