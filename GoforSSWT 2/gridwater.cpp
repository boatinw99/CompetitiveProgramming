#include<bits/stdc++.h>
using namespace std ;
#define pii pair<int,int>
#define f first
#define s second
const int N = 409;
vector<pii> path[N],tree[N];
priority_queue<pair<int,pii> > pq;
bool b[N];
int euler[N*4],depth[N*4],Height[N*4],p=0;
int st[N*8];
void dfs(int u,int v,int hi)
{

}
main()
{
    int n,m,i,j,wi,u,v,x,y ;
    scanf("%d %d",&n,&m);
    for(i=1;i<n;i++)
    {
        for(j=1;j<m;j++)
        {
            scanf("%d",&wi);
            u=(i-1)*m+j;
            path[u].push_back({u+1,wi});
            path[u+1].push_back({u,wi});
        }
        for(j=1;j<=m;j++)
        {
            scanf("%d",&wi);
            u=(i-1)*m+j;
            path[u].push_back({u+m,wi});
            path[u+m].push_back({u,wi});
        }
    }
    for(j=1;j<m;j++)
    {
        scanf("%d",&wi);
        u=(n-1)*m+j;
        path[u].push_back({u+1,wi});
        path[u+1].push_back({u,wi});
    }
    for(auto it:path[1])
    {
        pq.push({-it.s,{1,it.f}}); ///wi , u->v
    }
    b[1]++;
    while(!pq.empty())
    {
        x=pq.top().f*-1;
        u=pq.top().s.f;
        v=pq.top().s.s;
        pq.pop();
        if(!b[v]++)
        {
            tree[u].push_back({v,x});
            tree[v].push_back({u,x});
            for(auto it:path[v])
            {
                if(!b[it.f])
                {
                    pq.push({-it.s,{v,it.f}});
                }
            }
        }
    }
    dfs(1,1,0);/// u v hi
}
