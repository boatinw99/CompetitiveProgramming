#include<bits/stdc++.h>
using namespace std; 
main()
{
	int a,b,c,i,j,count,value,n,pr=0 ;
	scanf("%d %d %d",&a,&b,&c);
	int s[b],max=0;
	for(i=0;i<b;i++)
	{
		scanf(" %d",&s[i]);
		max+=s[i];
	}
	sort(&s[0],&s[b]);
	for(i=0;i<=a;i++)
	{
		count=max*i;
		value=i*(b+1);
		if(count<=c)
		{
			for(j=0;j<b&&count<=c;j++)
			{
				for(n=i;n<a&&count<=c;n++)
				{
					if(count+s[j]<=c)
					{
					count+=s[j];
					value++;	
					}
					else break;
				}
			}
			if(value>pr)
			{
				pr=value;
			}
		}
	}
	printf("%d",pr);
	
}
