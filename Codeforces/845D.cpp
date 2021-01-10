#include<bits/stdc++.h>
using namespace std ;
main()
{
	int i,a,spd,pr=0,count=0,in,val,l,j;
	stack<int> s;
	scanf("%d",&a);
	while(a--)
	{
		scanf("%d",&in);
		if(in==2)
		pr+=count,count=0;
		else if(in==4)
		count=0;
		else if(in==6)
		count++;
		else if(in==1)
		{
			scanf(" %d",&l);
			spd=l;
			while(!s.empty()&&s.top()<spd)s.pop(),pr++;
		}
		else if(in==3)
		{
			scanf(" %d",&val);
			if(val<spd)pr++;
			else s.push(val);
		}
		else if(in==5)
		{
			while(!s.empty())s.pop();
		}
	}
	printf("%d",pr);
}
