#include<stdio.h>
main()
{
	int a,i,max=0,j,k,value,f=0,q,g=0;
	scanf("%d",&a);
	int s[a];
		
	
	for(i=0;i<a;i++)
	scanf(" %d",&s[i]);
	for(i=0;i<a;i++)
	{
		f=0;
		for(j=0;j<i;j++)
		f+=s[j];
		for(j=i;j<a;j++)
		{	
			k=i;
			value=0;
			while(k<=j)
			{
				if(s[k]==0)value++;
				k++;
			}
			g=0;
			for(q=j+1;q<a;q++)g+=s[q];
			//printf("%d\n",value+f+g);
			if(value+f+g>max)max=value+f+g;
		}
	}
	printf("%d",max);
}
