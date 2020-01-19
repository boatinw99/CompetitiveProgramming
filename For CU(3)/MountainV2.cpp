#include<bits/stdc++.h>
using namespace std ;
set<int> s;
set<int>::iterator it;
main()
{
	int a,max,check,i,b,g=0 ;
	scanf("%d",&a);
	scanf("%d",&max);
	scanf("%d",&b);
	scanf("%d",&check);
	if(check<b)
	{
		s.insert(b);
		//printf("%d\n\n",b);	
	}
	else g=1;
	for(i=2;i<a;i++)
	{
		scanf("%d",&b);
		if(i==a-1&&b>check)
		{
			s.insert(b);
			//printf("%d\n\n",b);
		}
		else if(b>check&&g==0)
		{
			g=1;
		}
		else if(b<check&&g==1)
		{
			s.insert(check);
		//	printf("%d\n\n",check);
			g=0;
		}
		check=b;
	}
	g=s.size();
//	printf("\n\n%d",g);
	if(g==0)printf("-1");
	else if(g>=max)
	{
		for(it=--s.end();max>0;max--,it--)
		{
			printf("%d\n",*it);
		}
	}
	else
	{
		for(it=s.begin();it!=s.end();it++)
		{
			printf("%d\n",*it);
		}
	}
}
