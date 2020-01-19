#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
priority_queue<ll>pq;
main()
{
	ll n,i,ch=0,x,in,q;
	scanf("%I64d",&n);
	int w0=0,w1=0;
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&in);
		q=sqrt(in);
		x=min(in-q*q,(q+1)*(q+1)-in);
		if(x==0)
		{
			if(!in)w0++;
			else if(in)w1++;
			ch++;
		}
		else pq.push(-x);
	}
	ll count=0;
	while(ch<n/2)
	{
		ch++;
		count+=-pq.top();
		pq.pop();
	}
	while(ch>n/2&&w1>0)w1--,count++,ch--;
	while(ch>n/2&&w0>0)w0--,count+=2,ch--;
	
	printf("%I64d",count);
}
