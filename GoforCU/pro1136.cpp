#include<bits/stdc++.h>
using namespace std ;
typedef long double ld;
typedef long long ll;
vector<ll>v[4];
vector<ll>::iterator it;
main()
{
	ll i,j,x,pr=0,co1=0,co2=0,a,b,k ;
	ld p1,p2;
	scanf("%lld %lld",&a,&b);
	for(i=1;i<=a;i++)
	{
		scanf("%lld",&k);
		v[1].push_back(k);
		co1+=k;
	}
	for(i=1;i<=b;i++)
	{
		scanf("%lld",&k);
		v[2].push_back(k);
		co2+=k;
	}
	if(co1>=co2)x=1,p1=co1/a,p2=co2/b; 
	else x=2,p1=co2/b,p2=co1/a;
	ll q=p2;
	it=upper_bound(v[x].begin(),v[x].end(),q);
	while(*it>p2&&*it<p1)
	{
		if(*it<=p2||*it>=p1)
		{
			if(x==1)x=2;
			else x=1;
			swap(p1,p2);
			it=upper_bound(v[x].begin(),v[x].end(),p2);
			if(*it>p2&&*it<p1)
			{
				break;
			}
		}
		pr++;
		if(x==1)
		{
			p1=((p1*a)-*it)/(a-1);
			p2=(p2*b+*it)/(b+1);
			a--;
			b++;
		}
		else
		{
			p1=((p1*b)-*it)/(b-1);
			p2=(p2*a+*it)/(a+1);
			b--;
			a++;
		}
		it++;
	}
	printf("%lld",pr);
	
}
