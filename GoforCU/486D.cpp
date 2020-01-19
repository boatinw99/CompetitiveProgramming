#include<bits/stdc++.h>
using namespace std ;
int d,n ;
vector<int>path[2009],val[2009];
vector<int>::iterator it;
const int MOD=1e9+7;
int a[2009];
int dp[2009];
bool b[2009];
int pr=0 ;
bool dfs(int v,int u,int t)
{
    int x=0 ;
    vector<int>::iterator itp;
    dp[v]=1;
    printf("%d->%d || %d\n",u,v,dp[u]);
    pr=(pr+dp[u])%MOD;
    for(itp=path[v].begin();itp!=path[v].end();itp++)
    {
        if(b[*itp]==0&&*itp!=u&&a[*itp]-t<=d)
        {
            dfs(*itp,v,t);
            if(path[v].size()>2)
            {
                dp[v]=(dp[v]*(dp[*itp]+1))%MOD;
            }
            else
            {
                dp[v]++;
            }
        }
    }
}
main()
{
    int i,j,x,y ;
    scanf("%d %d",&d,&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        val[a[i]].push_back(i);
    }
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&x,&y);
        path[x].push_back(y);
        path[y].push_back(x);
    }
    for(i=1;i<=2000;i++)
    {
        for(it=val[i].begin();it!=val[i].end();it++)
        {
           b[*it]++;
           dp[*it]=1;
           dfs(*it,*it,i);
           printf("\n");
        }
    }
    printf("%d",pr);
}
