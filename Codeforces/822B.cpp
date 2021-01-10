#include<bits/stdc++.h>
using namespace std;
priority_queue<int> pq,q;
main()
{
	int m,n,i,j,max1=999999,count;
	scanf("%d %d",&n,&m);
	char s[n],t[m];
	scanf("%s",&s);
	scanf("%s",&t);
	for(i=0;i<=m-n;i++)
	{
		count=0;
		for(j=0;j<n;j++)
		{
			if(s[j]!=t[i+j])
			{
				q.push(-j);
				count++;
			}
		}
		if(count<max1)
		{
			max1=count;
			while(!pq.empty())pq.pop();
			while(!q.empty())
			{
				pq.push(q.top());
				q.pop();
			}
		}
		else 
		{
			while(!q.empty())q.pop();
		}
	}
	printf("%d\n",max1);
	while(!pq.empty())
	{
		printf("%d ",pq.top()*-1+1);
		pq.pop();
	}

}
