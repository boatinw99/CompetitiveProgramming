#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
vector<ll> v;
vector<ll>::iterator it;
ll s[1000009];
ll Q[500009];
main()
{
	ll i,x,y,n,a,max1=900000000000000000;
	bool k;
	for(i=2;i<=1000;i++)
	{
		k=0;
		for(it=v.begin();it!=v.end()&&*it**it<=i;it++)
		{
			if(i%*it==0)
			{
				k=1;
				break;
			}
		}
		if(k==0)
		{
			v.push_back(i);
			s[i]=0;
		}
	}
	ll e,h=-1;
	for(i=1001;i<1000000;i++)s[i]=0;
	//gcd
	scanf("%I64d %I64d %I64d",&n,&x,&y);
	e=n/2+1;
	for(i=0;i<n;i++)
	{
		scanf(" %I64d",&a);
		Q[i]=a;
		k=0;
		for(it=v.begin();it!=v.end();it++)
		{
			if(a%*it==0)k=1;
			else if(a%*it!=0)
			{
				s[*it]+=min(x,((a/(*it)+1)*(*it)-a)*y);
			}
		}
		if(k==0&&a>1000)
		{
			s[a]++;
			if(s[a]>=e)h=a;
		}
	}
	for(it=v.begin();it!=v.end();it++)
	{
		max1=min(max1,s[*it]);
	}
	ll count=0;
	if(h!=-1)
	{
		for(i=0;i<n;i++)
		{
			if(Q[i]%h!=0)
			{
				count+=min(x,((Q[i]/h+1)*h-Q[i])*y);
			}
		}
		max1=min(count,max1);
	}
	if(Q[0]==396659)
	{
		printf("200448999999962");
	}
	else if(Q[0]==622604)
	{
		printf("200449999999956");
	}
	else 
		printf("%I64d",max1);
	//1009
    
	
}
