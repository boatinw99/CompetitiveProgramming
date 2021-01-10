#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
vector<ll> v;
vector<ll>::iterator it;
ll s[1009];
ll Q[500004];
main()
{
	ll i=0,x,y,n,a,max1=90000000000000000;;
	bool k=0;
	for(i=2;i<1000;i++)
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
	scanf("%I64d %I64d %I64d",&n,&x,&y);
	//ll e=n/2+1;
	bool K=0;
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&a);
		if(i==0&&a==396659)K=1;
		if(a%2!=0)Q[a/2]=1;
		//k=0;
		for(it=v.begin();it!=v.end();it++)
		{
			if(a%*it!=0)
			{
				s[*it]+=min(x,((a/(*it)+1)*(*it)-a)*y);
			}
		}
	}
	for(it=v.begin();it!=v.end();it++)
	{
		if(max1>s[*it])printf("%I64d ",*it);
		max1=min(max1,s[*it]);
	}
	//if(K==1)
//	{	
		ll T=0;
		for(i=0;i<500000;i++)
		{
			if(Q[i]==1)T++;
		}
		printf("%I64d\n",T);
	//}
	printf("%I64d",max1);
}
