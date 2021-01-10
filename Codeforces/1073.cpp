#include<bits/stdc++.h>
using namespace std ;
priority_queue<int> pq;
main()
{
	int l,t,m,x; char c;
	scanf("%d %d",&l,&t);
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d",&x);
		scanf(" %c",&c);
		if(c=='L')x-=t; else x+=t;
		x%=2*l;
		if(x<0)x+=2*l;
		if(x>l)x=2*l-x;
		pq.push(-x);
	}
	while(!pq.empty())
	{
		printf("%d ",pq.top()*-1);
		pq.pop();
	}
}
