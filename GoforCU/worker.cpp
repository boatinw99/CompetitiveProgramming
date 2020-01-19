#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
main()
{
	ll n,x,i ;
	scanf("%lld",&n);	
	vector<pair<ll,ll> > v(n);
	vector<pair<ll,ll> > :: iterator it,it1;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&x);
		v[i].second=x;
	}
	for(i=0;i<n;i++)
	{
		scanf("%lld",&x);
		v[i].first=x;
	}
	sort(v.begin(),v.end());
	ll max1=1e17,co,min1;
	for(it=v.begin();it!=v.end();it++)
	{
		co=it->second;
		min1=it->first;
			for(it1=v.begin();it1!=v.end();it1++)
			{
				if(it!=it1)
				{
					if(min1+it1->first<it1->second)co+=min1+it1->first;
					else co+=it1->second;
				}
				min1=(v.begin())->first;
			}
			max1=min(max1,co);
	}
	printf("%lld",max1);
}
