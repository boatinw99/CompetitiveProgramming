#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
set<ll> s;
set<ll> ::iterator it,it1;
ll x,y,l,r ;
ll max1=0;
ll Call(ll a,ll b)
{
	b*=y;
	if(a+b<=r)
	{		
		if(a+b>=l)
		{
			s.insert(a+b);
			///printf("%I64d %I64d\n",a,b);
		}
		Call(a,b);
	}
}
main()
{
	ll a=1,b=1,d=2^20;
	long double o=2000000000000000000;
	long long g=8000000000000000000;
	scanf("%I64d %I64d %I64d %I64d",&x,&y,&l,&r);
	printf("%I64d ",g);
	for(a;a<r;a*=x)
	{   
		if(a+1>=l)
		s.insert(a+1);
		Call(a,1);
	}
	if(s.size()==0)
	{
		printf("%I64d",r-l+1);
		return 0;
	}
	it=s.begin();
	++it;
	it1=s.begin();
	for(it;it!=s.end();++it,++it1)
	{
		if(*it-*it1-1>max1&&*it>=l&&*it<=r&&*it1>=l&&*it1<=r)max1=*it-*it1-1;
	}	
	if(*s.begin()-l>max1)max1=*s.begin()-l;
	if(r-*it1>max1)max1=r-*it1;
	printf("%I64d",max1);
}
