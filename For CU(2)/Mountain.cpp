#include<stdio.h>
main()
{
	int a,i,max=0,max1=0,max2,k,j;
	scanf("%d",&a);
	int s[a][2];	
	for(i=0;i<a;i++)
	{
		scanf("%d %d",&s[i][0],&s[i][1]);
		if(s[i][1]>max) max=s[i][1];
		if(s[i][0]>max1){max1=s[i][0];max2=s[i][1];
		}
	}
	max1+=max2*2;
	int m[max][max1];
	for(i=0;i<max;i++)
		for(j=0;j<max1;j++)
			m[i][j]=0;
	for(i=0;i<a;i++)
	{
		k=s[i][0]-1;
		for(j=0;j<s[i][1];j++)
		{
			if(m[max-j-1][k]==-1)m[max-j-1][k]=2;
			else {m[max-j-1][k]++;}	
			k++;
		}
		for(j--;j>=0;j--)
		{
			if(m[max-j-1][k]==1)m[max-j-1][k]=2;
			else {m[max-j-1][k]--;}	
			k++;
		}
	}
	for(j=0;j<max1;j++)
	{
		k=0;
		for(i=0;i<max;i++)
		{
			if(k==99)
			{
				m[i][j]='X';
			}
			if(m[i][j]==1)
			{
				m[i][j]='/';
				k=99;
			}
			if(m[i][j]==-1)
			{
				m[i][j]='\\';
				k=99;
			}
		    
			else if(m[i][j]==2)
			{
				m[i][j]='v';
				k=99;
			}
			else if(k==0)
			{
				m[i][j]='.';
			}
		}
	}
	for(i=0;i<max;i++)
	{
		for(j=0;j<max1-1;j++)
		printf("%c",m[i][j]);
		printf("\n");
	}
	
}
