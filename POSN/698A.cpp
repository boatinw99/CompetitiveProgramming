#include<bits/stdc++.h>
using namespace std ;
main()
{   int a,check=0,i,p,count=0,j,c,k ;
	scanf("%d",&a);
	int s[a];
	for(i=0;i<a;i++)
	{
		scanf("%d",&p);
		s[i]=p;
	}
	for(i=0;i<a;i++)
	{
		if(s[i]==0)
		{
			check=0;
			count++;
		}
		else if(s[i]==1)
		{
			if(check==1)
			{
				check=0;
				count++;
			}
			else check=1;
		}
		else if(s[i]==2)
		{
			if(check==2)
			{
				check=0;
				count++;
			}
			else check=2;
		}
		else if(s[i]==3)
		{
			if(check==1)
			{
				check=2;
			}
			else if(check==2)
			{
				check=1;
			}
		}
	}
	printf("%d",count);
	
	
} 
