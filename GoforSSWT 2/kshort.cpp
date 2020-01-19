#include<bits/stdc++.h>
using namespace std ;
const int N =  1e4+9;
int dijks[N][59];
struct Edge
{
    int ter,wi,spe ;
};
vector<Edge> path[N];
vector<Edge> ::iterator it ;
priority_queue<pair<int,pair<int,int> > > pq;
///Value , town , spe
main()
{
    int n,m,s,l,i,j,u,v,val,use,k ;
    scanf("%d %d %d %d",&n,&m,&s,&l);
    while(m--)
    {
        scanf("%d %d %d",&u,&v,&val);
        path[u].push_back({v,val,0});
    }
    for(i=1;i<=s;i++)
    {
        scanf("%d %d %d",&u,&v,&val);
        path[u].push_back({v,val,1});
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=l;j++)dijks[i][j]=INT_MAX;
    }
    dijks[1][0]=0;
    pq.push({0,{1,0}});
    while(!pq.empty())
    {
        val=pq.top().first*-1;
        u=pq.top().second.first ; use=pq.top().second.second;
        pq.pop();
        if(u==n)
        {
            printf("%d",val);
            return 0 ;
        }
        if(dijks[u][use]==val)
        {
            for(it=path[u].begin();it!=path[u].end();it++)
            {
                k=it->spe ;
                if(val+it->wi<dijks[it->ter][use+k]&&use+k<=l)
                {
                    dijks[it->ter][use+k]=val+it->wi;
                    pq.push({-val-it->wi,{it->ter,use+k}});
                }
            }
        }
    }
}
