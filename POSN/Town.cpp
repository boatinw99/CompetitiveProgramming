#include<bits/stdc++.h>
using namespace std;
int s[500009];
main()
{
	int a,i,b,min=9,j,count,min1,k=0,g;
	scanf("%d",&a);
	scanf("%d",&b);
	int s[a];
	for(i=0;i<a;i++)
	{
		scanf(" %d",&s[i]);
	}
	min=s[0]+s[1];
	for(i=1;i<=b;i++)
	{
		s[i]+=s[0];
		if(s[i]<min){min=s[i];g=i;}	
	}
	for(i=b+1;i<a;i++)
	{
		if(i-b>g)
		{  
			min=99999999;
			for(j=g+1;j<i;j++)
			{
				if(s[j]<min)
				 {
				 min=s[j];
				 g=j;
				 }	
			}
		}
		s[i]=s[i]+min;
	}
	printf("%d",s[a-1]);
}
