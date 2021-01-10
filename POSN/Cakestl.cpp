#include<bits/stdc++.h>
using namespace std ;
int main()
{   int a,b,i,c;
	priority_queue<int> pq;
	scanf("%d",&a);
	c=a;
	for(i=0;i<a;i++)
	{
		scanf("%d",&b);
		pq.push(b);	
		while(!pq.empty()&&pq.top()==c)
		{
			cout<< pq.top() << " " ;
			pq.pop() ;
			c--;
		}
			printf("\n");
	}	
}
