#include<stdio.h>
main()
{
	int i,a,k=0,value=0,max=0,count0=0,count1=0,j,x,y;
	scanf("%d",&a); int s[a];
	for(i=0;i<a;i++)scanf(" %d",&s[i]);
	for(i=0;i<a;i++)
	{
		printf("%d %d\n",x,y);
		if(s[i]==0&&i==a-1)
		{
			count0++;
			if(count0>max)
			{
				max=count0;	
				for(j=i;j>=0&&s[j]==0;j--)count0--;
				if(count0>0)
				for(j;j>=0&&s[j]==1;j--);
				j-=count0;
				x=j+1;
				y=a-1;
			}
		}
		else if(s[i]==0)
		{
			count0++;
		}
		else if(s[i]==1)
		{
			count1=0;
			for(j=i;s[j]==1&&j<a;j++)
			{
				count1++;
			}
			if(count0>max)
			{
				max=count0;	
				if(k==0)
				{
				x=i-count0;
				y=i-1;
				}
				else 
				{
					y=i-1;
				}	
			}
			i=j-1;
			if(count1>=count0)
			{
				k=0;
				count0=0;
			}
			else 
			{
				k=99;
			}

		}
	}
	printf("%d\n",max);
	if(a==1&&s[0]==0)printf("1");
	else if(max==0)printf("%d",a-1);
	else if(max==a)printf("%d",a);
	else 
	{
		for(i=0;i<x;i++)
		{
			if(s[i]==1)value++;
		}
		for(i=y+1;i<a;i++)
		{
			if(s[i]==1)value++;
		}
		printf("\n%d",value+=max);
	}
}
