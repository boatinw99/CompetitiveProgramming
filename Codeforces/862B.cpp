#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
vector<ll> v[100009];
ll s[100009];
ll k[2]={0,0};
ll dfs(ll a,ll b)
{
	
	vector<ll>::iterator it;
	s[a]=b;
	k[b]++;
	if(b==0)b=1;
	else b=0;
	for(it=v[a].begin();it!=v[a].end();it++)
	{
		if(s[*it]==-1)
		{
			dfs(*it,b);
		}
	}
}
main()
{
	ll a,i,x,y,count=0 ;
	scanf("%I64d",&a);
	s[a]=-1;
	for(i=1;i<a;i++)
	{
		scanf("%I64d %I64d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
		s[i]=-1;
	}
	dfs(1,0);
	for(i=1;i<=a;i++)
	{
		if(s[i]==0)
		{
			count+=k[1]-v[i].size();
		}
		else count+=k[0]-v[i].size();
	}
	printf("%I64d",count/2);
}
