#include<bits/stdc++.h>
using namespace std ;
priority_queue<int> pq;
main()
{
	int i,n,k,j,x,co=0 ;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		pq.push(x);
	}
	while(!pq.empty())
	{
		co+=pq.top();
		for(j=0;j<k&&!pq.empty();j++)pq.pop();
	}
	printf("%d",co);
}
