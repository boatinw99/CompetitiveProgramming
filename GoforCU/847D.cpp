#include<bits/stdc++.h>
using namespace std;
int s[250][200000];
int q[200000];
main()
{
	int n,T,i=0,input,m,max=0,j=0,count=0,x=0,out;
	scanf("%d %d",&n,&T);
	m=T-n;
	if(n-T>=0)
	m=1;
	/*for(i=0;i<=(n-1)/800;i++)
	{
		for(j=0;j<200000;j++)
		s[i][j]=0;
	}*/
	if(n-T>=0)
	n=T-1;	
	for(i=0;i<n;i++)
	{
		scanf("%d",&input);
		if(input-m-i<0&&input<T)
		{
			q[i]=0;
			s[i/800][q[i]]++;
		}
		else if(input<T)
		{
			q[i]=input-m-i;	
			s[i/800][q[i]]++;
		}
		else 
		q[i]=INT_MAX;
	}
	for(j=1;j<200000;j++)
	{
		s[0][j]+=s[0][j-1];
	}
	for(i=1;i<=(n-1)/800;i++)
	{
		for(j=0;j<199999;j++)
		{
			s[i][j+1]+=s[i][j];
			s[i][j]+=s[i-1][j];
		}
		s[i][j]+=s[i-1][j];
	}
	//start
	for(i=n-1;i>=0;i--)
	{
		x=0;
		out=0;
		if(i/800==(n-1)/800)
		{
			for(j=i+1;j<n;j++)
			{
				if(q[j]<count)
				{
					x++;
				}
			}
			out=s[i/800][count]-x;
			if(out>max)max=out;	
		}
		else 
		{
			for(j=i+1;j<(i/800)*800+800;j++)
			{
				if(q[j]<count)
				{
					x++;
				}
			}
			out=s[i/800][count]-x;
			if(out>max)max=out;
		}
		count++;
	}
	printf("%d",max);
}
