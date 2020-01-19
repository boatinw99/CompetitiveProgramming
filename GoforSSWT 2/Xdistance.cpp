#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
int X;
bool b[N];
vector<pair<int,int> > path[N],tree[N];
priority_queue<pair<int,pair<int,int> > > pq;
long long ans = 0 ;
pair<int,int> dfs(int v,int nodeall,int nodeplus,int val)
{
    vector<pair<int,int> > ::iterator it;
    int rnodeall=1,rnodeplus=0;
    pair<int,int> q;
    b[v]++;
    nodeall++;
    if(val==X)
    {
        nodeplus+=nodeall-1;
        nodeall=1;
    }
    ans+=1ll*nodeplus;
    //printf("aa %d -> %d %d || %d\n",v,nodeall,nodeplus,ans);
    for(it=tree[v].begin();it!=tree[v].end();it++)
    {
        ///town,val
        if(b[it->first]==0)
        {
            q=dfs(it->first,nodeall,nodeplus,it->second);
            if(it->second!=X)
            {
                rnodeall+=q.first; rnodeplus+=q.second;
                nodeall+=q.first; nodeplus+=q.second;
            }
            else
            {
                rnodeplus+=q.first+q.second;
                nodeplus+=q.first+q.second;
            }
        }
    }
    return {rnodeall,rnodeplus};
}
main()
{
    vector<pair<int,int> > ::iterator it;
    int n,m,i,j,u,v,x,y,town,val ;
    scanf("%d %d %d",&n,&m,&X);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&u,&v,&val);
        path[u].push_back({v,val});
        path[v].push_back({u,val});
    }
    for(i=1;i<=n;i++)
    {
        if(b[i]!=0)continue;
        for(it=path[i].begin();it!=path[i].end();it++)
        {
            pq.push({-it->second,{it->first,i}});
        }
        b[i]++;
        while(!pq.empty())
        {
            x=pq.top().first*-1; v=pq.top().second.first;
            u=pq.top().second.second; pq.pop();
            if(!b[v]++)
            {
                if(x<=X)
                {
                    tree[v].push_back({u,x});
                    tree[u].push_back({v,x});
                }
                for(it=path[v].begin();it!=path[v].end();it++)
                {
                    if(b[it->first]==0)
                    {
                        pq.push({-it->second,{it->first,v}});
                    }
                }
            }
        }
    }
    for(i=1;i<=n;i++)b[i]=0;
    for(i=1;i<=n;i++)
    {
        if(b[i]==0)
        {
            dfs(i,0,0,-1);
        }
    }
    printf("%lld",ans);

}
