#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e5+9,MOD=1e9+7 ;
ll ans=1;
int child[N];
vector<int> path[N];
int K;
void dfs(int town,int hi,int par)
{
    vector<int>::iterator it;
    if(hi<=2)
    {
        ans*=(K-child[par]);
    }
    else
    {
        ans*=(K-child[par]-1);
    }
    ans%=MOD;
    child[par]++;
    for(it=path[town].begin();it!=path[town].end();it++)
    {
        if(*it!=par)
        {
            dfs(*it,hi+1,town);
        }
    }

}
main()
{
    int n,i,j,u,v ;
    scanf("%d %d",&n,&K);
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&u,&v);
        path[u].push_back(v);
        path[v].push_back(u);
        child[i]++;
    }
    child[n]++;
    dfs(1,1,0);
    printf("%lld",ans);
}
