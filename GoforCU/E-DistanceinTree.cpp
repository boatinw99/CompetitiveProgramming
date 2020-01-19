#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
ll n,k ;
vector<ll> v[50009];
ll dp[50009][509];
ll pr = 0 ;
void dfs(ll i,ll par)
{
	ll j;
	vector<ll>::iterator it;
	for(it=v[i].begin();it!=v[i].end();it++)
	{
		if(*it!=par)
		{
			dfs(*it,i);
		}
	}
	for(j=0;j<=k;j++)
	{
		pr+=dp[i][j]*(dp[par][k-j-1]);
	}
	for(j=0;j<k;j++)
	{
		dp[par][j+1]+=dp[i][j];
	}
}
main()
{
	ll i,j,x,y ;
	scanf("%I64d %I64d",&n,&k);
	for(i=1;i<n;i++)
	{
		scanf("%I64d %I64d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);	
	}
	for(i=1;i<=n;i++)
	{
		dp[i][0]=1;
	}
	dfs(1,0);
	printf("%I64d",pr);
}
