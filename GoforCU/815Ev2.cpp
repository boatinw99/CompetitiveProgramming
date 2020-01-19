#include<bits/stdc++.h>
using namespace std ; 
queue<pair<int,int> > q;
main()
{
	int d=3;
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
	else 
	{
		q.push({1,a});
		while(!q.empty())
		{
			x=q.front().first;
			y=q.front().second;
			//printf("%I64d %I64d %d\n",x,y,d);
			q.pop();
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
			q.push({x,(x+y)/2});
			q.push({(x+y)/2,y});	
			}
			
			//printf("%I64d %I64d %I64d   ",(x+y)/2-x,-x,(x+y)/2*-1);
		//	printf("%I64d %I64d %I64d\n",(y-(x+y)/2),-(x+y)/2,-y);
		}
	}
}
