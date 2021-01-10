#include<bits/stdc++.h>
using namespace std ;
main()
{
	int a,i,k=0;
	int c1=0,count1=0,count2=0,value=0,max=0;
	scanf("%d",&a);	int s[a];
	for(i=0;i<a;i++)
	{
		scanf("%d",&s[i]);
		printf("%d ",value);
		//printf("%d",value);
		if(k==0&&s[i]==1)
		{
			value++;
		}
		//from here
		else 
		{
			k=99;
			if((s[i]==0&&c1==99)||i==a-1)
			{
				if(i==a-1&&s[i]==1)
				{
					value+=count2+1;
					if(count1>max)max=count1;
				}
				else if(i==a-1&&s[i]==0)
				{
					if(s[i-1]==1)
					{
						value+=count2;
						if(count1>max)max=count1;
						if(1>max)max=1;
					}
					else if(s[i-1]==0)
					{
						if(count1+1>max)max=count1+1;
					}
				}
				else
				{
					c1=0;
				if(count2>=count1)
				{
					value+=count2;
					if(count1>max)max=count1;
					count1=0;
					count2=0;
				}
				else if(count1>count2)
				{
					count2=0;
				}
				count1++;
				}
			}
			else if(s[i]==0&&c1==0)
			{
				count1++;
			}
			else if(s[i]==1)
			{
				c1=99;
				count2++;
			}			
		}
	}
	if (a==1&&s[0]==0)printf("1");
	else if(k==0)
	{
		printf("%d",value-1);	
	}
	else printf("%d",value+max);

}

