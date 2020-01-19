#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 ;
vector<pair<int,int> > path[N];
queue<int> q;
bool b[N];
long long dfs(int value,int n)
{
    vector<pair<int,int > >::iterator it ;
    int i,j,town ;
    for(i=1;i<=n;i++)b[i]=0;
    long long ans=0;
    for(i=1;i<=n;i++)
    {
        if(b[i]!=0)continue ;
        int comp=0;
        q.push(i);
        b[i]++;
        while(!q.empty())
        {
            town = q.front(); q.pop(); comp++;
            for(it=path[town].begin();it!=path[town].end();it++)
            {
                if(it->second<=value&&b[it->first]==0)
                {
                    b[it->first]++;
                    q.push(it->first);
                }
            }
        }
        ans+=1ll*comp*(comp-1)/2;
    }
    return ans ;
}
main()
{
    int n,m,X,u,v,val,i,j ;
    scanf("%d %d %d",&n,&m,&X);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&u,&v,&val);
        path[u].push_back({v,val});
        path[v].push_back({u,val});
    }
    long long All=dfs(X,n);
    long long Sect=dfs(X-1,n);
    printf("%lld",All-Sect);
}
