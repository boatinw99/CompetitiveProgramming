#include<stdio.h>
#include<queue>
using namespace std;
priority_queue<int>pq;
main()
{
	int a,b,i;
	scanf("%d %d",&a,&b);
	b--;
	while(a--)
	{
		scanf("%d",&i);
		pq.push(i);
	}
	while(b--)pq.pop();
	printf("%d",pq.top());
}
