#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
typedef long long ll ;
ll ans=0;
int power[N];
bool inpath[N];
int S,R,T ;
vector<pair<int,int> > path[N]; /// go , value;
bool dfs(int v,int u,int terminal)
{
    int b=0 ;
    vector<pair<int,int> >::iterator it;
    if(v==terminal)
    {
        inpath[v]++;
        return 1;
    }
    for(it=path[v].begin();it!=path[v].end();it++)
    {
        if(it->first!=u)
        {
            b=dfs(it->first,v,terminal);
            if(b==1)
            {
                ans-=it->second;
                inpath[v]++;
                return 1;
            }
        }
    }
    return 0 ;
}
ll dp(int v,int u)
{
    vector<pair<int,int> >::iterator it;
    ll maxreturn=0,dpreturn ;
    for(it=path[v].begin();it!=path[v].end();it++)
    {
        if(it->first!=u)
        {
            dpreturn=dp(it->first,v);
            dpreturn=max(1ll*0,dpreturn-2*it->second);
            maxreturn+=dpreturn;
        }
    }
    return max(maxreturn+power[v],1ll*0);
}
main()
{
    int n,i,j,u,v,val ;
    vector<pair<int,int> >::iterator it;
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        scanf("%d %d %d",&u,&v,&val);
        path[u].push_back({v,val});
        path[v].push_back({u,val});
    }
    for(i=1;i<=n;i++)scanf("%d",&power[i]);
    scanf("%d %d %d",&S,&T,&R);
    dfs(S,S,R);
    dfs(R,R,T);
    for(i=1;i<=n;i++)
    {
        if(inpath[i]==1)
        {
            ans+=power[i];
            for(it=path[i].begin();it!=path[i].end();it++)
            {
                if(inpath[it->first]==0)
                {
                    ans+=max(dp(it->first,i)-2*it->second,1ll*0);
                }
            }
        }
    }
    printf("%lld",ans);
}
