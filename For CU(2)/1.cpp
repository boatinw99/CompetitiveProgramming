#include<bits/stdc++.h>
using namespace std ;	
long long s[1000000];
priority_queue<pair<long long,long long> > pq;
main()
{
	int a,b,i,j,count;
	long long sum ;
	scanf("%d %d",&a,&b);
	for(i=0;i<a;i++)
	{
		scanf(" %lld",&s[i]);
	}
	for(i=0;i<a;i++)
	{
		if(s[i]>0)
		{	
			count=0;
			sum=0;
			for(j=i;j<i+b&&j<a;j++)
			{
				if(s[j]+sum<=0)
				{
					break;
				}
				count++;
				if(s[j]+sum>0)
				{
					sum+=s[j];
					pq.push({sum,-count});
				}
				
				
			}
		}	
	}
	if(pq.empty())
	{
		printf("0");
	}
	else
	printf("%lld\n%lld",pq.top().first,pq.top().second*-1);
}
