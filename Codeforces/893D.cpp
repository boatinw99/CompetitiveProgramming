#include<bits/stdc++.h>
using namespace std;
main()
{
	int n,d,count,x,i,ch=0;
	int k=0;
	scanf("%d %d",&n,&d);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		count+=x;
		if(count>d)return 0*printf("-1");
		if(x==0&&k==0&&count<0)
		{
			count=0; 
			k=d;
		}
		else if(x==0&&!k)
		{
			if(count<0&&k+count<0)
			{
				
			}
			printf("%d ",i);
		}
	}
}
