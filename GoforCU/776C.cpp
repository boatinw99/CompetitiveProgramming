#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll>m;
set<ll>v;
set<ll>::iterator it;
ll n,k;
ll qs[100009];
main()
{
	ll i,t,co=0;
	scanf("%I64d %I64d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%I64d",&qs[i]);
		qs[i]+=qs[i-1];
		v.insert(qs[i]);
		m[qs[i]]++;
	}
	if(k==1)
	{
		return 0;	
	}
	else if(k==-1)
	{
		return 0;
	}
	bool d;
	ll q;
	for(i=1;i<=n;i++)
	{
		q=m[qs[i]];
		for(t=1;t<=1e14+2;t*=k)
		{
			d=binary_search(v.begin(),v.end(),t+qs[i-1]);
			if(d&&q)co+=m[t+qs[i-1]];
		}	
		m[qs[i]]--;
		//if(q-1<=0)v.erase(qs[i]);
	}	
	printf("%I64d",co);
}
