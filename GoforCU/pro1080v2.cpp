#include<bits/stdc++.h>
using namespace std ;
int s[509];
int qs[509];
main()
{
	int n,i,j,x,max1=0 ;
	scanf("%d",&n);
	for(i=0;i<=506;i++)s[i]=0,qs[i]=0;
	while(n--)
	{
		scanf("%d",&x);
		if(x>500)for(i=0;i<2;i--);
		s[x]++;
	}
	for(i=1;i<=500;i++)
	{
		qs[i]+=qs[i-1]+s[i];
	}
	int k;
	for(i=1;i<=500;i++)
	{   
		max1=max(max1,s[i]);
		if(s[i])
		{
			for(j=i+1;j<=500;j++)
			{
				if(s[j])
				{
				k=i+j-1;
				if(k==j)
				{
					if(i*2<=j)max1=max(max1,s[j]+1);
					else max1=max(max1,s[i]+s[j]);
				}
				else if(i*2<=j)
				{	
					if(k>500)k=500;
					max1=max(max1,(qs[k]-qs[j]+s[j]+1));
				}
				else
				{
					if(i*2<=k)
					{
						//printf("%d %d\n",i,k);
						if(k>500)k=500;
						max1=max(max1,s[i]+s[j]+qs[i*2-1]-qs[j]);
						max1=max(max1,1+s[j]+qs[k]-qs[j]);	
					}
					else
					{
						if(k>500)k=500;
						max1=max(max1,s[i]+s[j]+qs[k]-qs[j]);
					}
				}
			}
			}
		}		
	}
	printf("%d",max1);
}
