#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l=-1,r=pow(2,32),m;
ll s[2000009];
stack<ll>st;
main()
{
	ll n,i=0;
	bool k=0;
	scanf("%lld",&n);
	for(i=0;i<n;i++)scanf("%lld",&s[i]);
	while(l+1<r)
	{
		m=(l+r)/2;
		k=0;
		for(i=0;i<n;i++)
		{
			if(s[i]>m)
			{
				if(st.empty())st.push(s[i]);
				else if(st.top()==s[i])st.pop();
				else break;
			}
		}		

		if(!st.empty())l=m;
		else r=m;
		while(!st.empty())st.pop();
	}
	printf("%lld",r);
}

