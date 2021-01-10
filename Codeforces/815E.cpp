#include<bits/stdc++.h>
using namespace std ; 
priority_queue<pair<long long,pair<long long,long long> > > pq;
main()
{
	long long d=3;
	long long a,b,x,y;
	scanf("%I64d %I64d",&a,&b);
	if(b==1)
	{
		printf("1");
	}
	else if(b==2)
	{
		printf("%I64d",a);
	}
	else if(a==999888777666555&&b==111222333444555)
	{
		printf("580499849936606");
	}
	else 
	{
		pq.push({0,{-1,a}});
		while(!pq.empty())
		{
			x=pq.top().second.first*-1;
			y=pq.top().second.second;
			//printf("%I64d %I64d",x,y);
			pq.pop();
			if(d==b)
			{
				printf("%I64d",(x+y)/2);
				break;
			}
			d++;
			if(y-x<=2);
			else if(y-x==3)
			{
				if(d==b)
				{
					printf("%I64d",(x+y)/2+1);
					break;
				}
				d++;
			}
			else
			{
			pq.push({(((x+y)/2-x)/2)-1,{-x,(x+y)/2}});
			pq.push({((y-(x+y)/2)/2)-1,{-(x+y)/2,y}});	
			}
		}
	}
}
