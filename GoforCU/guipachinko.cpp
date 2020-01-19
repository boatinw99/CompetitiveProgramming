#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>v[100009]; 
vector<pair<ll,ll> >q[100009];
vector<ll>pr;
ll a[100009];
void dfs(ll i,ll par)
{
	vector<ll>::iterator it;
	for(it=v[i].begin();it!=v[i].end();it++)
	{
		if(*it!=par)
		{
			dfs(*it,i);
			a[i]=max(a[i],a[*it]);
			q[i].push_back({a[*it],*it});
		}
	}
	sort(q[i].begin(),q[i].end());
}
void construct(ll i)
{
	vector<pair<ll,ll> >::iterator it;
	for(it=q[i].begin();it!=q[i].end();it++)
	{
		construct(it->second);
	}
	pr.push_back(i);
}
main()
{
	ll n,m,i,j,x ;
	scanf("%lld %lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		v[x].push_back(i);
		a[i]=i;
	}
	dfs(0,0);
	pr.push_back(0);
	construct(0);
	for(i=1;i<=n;i++)
	{
		pr[i]+=pr[i-1];
	}
	cout << endl ;
	ll val;
	ll now=0;
	while(m--)
	{
		scanf("%lld",&x);
		if(x==1)
		{
			scanf("%lld",&val);
			now+=val;
			printf("%lld",pr[now]-pr[now-1]);
			printf("\n");
		}
		if(x==2)
		{
			scanf("%lld",&val);
			now-=val;
		}
		if(x==3)
		{
			printf("%lld",pr[now]);
			printf("\n");
		}
		
	}
}
