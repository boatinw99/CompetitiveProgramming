#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll n;
vector<ll> u,v;
vector<ll>::iterator it;
ll s[100009];
ll search1(ll ch,ll M)
{
	ll Q,N=0 ;
	while(N<M)
	{
		Q=(M+N)/2;
		if(u[Q]>ch)
		{
			M=Q;
		}
		else if(u[Q]<ch)
		{
			N=Q;
		}
		else
		{
			return Q;	
		}
		
	} 
}
ll search2(ll ch,ll M)
{
	ll Q,N=0,o=M ;
	while(N<M)
	{
		Q=(M+N)/2;
		if(v[Q]>ch)
		{
			M=Q;
		}
		else if(v[Q]<ch)
		{
			N=Q;
		}
		else
		{
			return Q;	
		}
		
	} 
}
main()
{
	ll i,x,y;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld %lld",&x,&y);
		s[y]=x;
	}
	for(i=1;i<=n;i++)
	{
		u.push_back(s[i]);
		v.push_back(s[i]);
	}
	sort(u.begin(),u.end());
	sort(v.begin(),v.end());
	ll count=0;
	for(i=1;i<=n;i++)
	{
		x=search1(s[i],n-i+1);
		count+=(x)*s[i];
		u.erase(u.begin()+x);
	}
	for(i=n;i>=1;i--)
	{
		x=search2(s[i],i);
		count+=(i-x-1)*s[i];
		v.erase(v.begin()+x);
	}
	printf("%lld",count);
}
