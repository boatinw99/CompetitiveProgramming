#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 ;
typedef long long ll ;
vector<int> path[N];
int sub[N];
int dp[N];
int n;
ll ans=0;
void dfs(int u,int v)
{
    vector<int>::iterator it,it1 ;
    sub[u]=1;
    ll max1=0,max2=0,frommax1=0,frommax2=0;
    ll sub1=0,sub2=0,fromsub1=0,fromsub2 =0;
    for(it=path[u].begin();it!=path[u].end();it++)
    {
        if(*it!=v)
        {
            ///dp1->ans , dp2-> nonans;
            dfs(*it,u);
            sub[u]+=sub[*it];
            dp[u]=max(dp[u],sub[*it]);
            if(dp[*it]>max1)
            {
                max2=max1;
                frommax2=max1;
                max1=dp[*it];
                frommax1=*it;
            }
            else if(dp[*it]>max2)
            {
                max2=dp[*it];
                frommax2=*it;
            }
            ///
            if(sub[*it]>sub1)
            {
                sub2=sub1;
                fromsub2=sub1;
                sub1=sub[*it];
                fromsub1=*it;
            }
            else if(sub[*it]>sub2)
            {
                sub2=sub[*it];
                fromsub2=*it;
            }
        }
    }
    ans=max(ans,(n-sub[u])*max1);
    if(fromsub1==frommax1)
    {
        ans=max(ans,max1*sub2);
        ans=max(ans,max2*sub1);
    }
    else
    {
        ans=max(ans,max1*sub1);
    }
}
main()
{
    int i,j,x,u,v ;
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&u,&v);
        path[u].push_back(v);
        path[v].push_back(u);
    }
    dfs(1,0);
    printf("%lld",ans);
}
