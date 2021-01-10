#include<stdio.h>
long long  a[10000][5000]={0},b,i,j,k,c;
main()
{
	
	a[1][0]=1,a[2][0]=1,a[3][0]=2,a[4][0]=2;
	scanf("%I64d",&b);
	for(i=5;i<=b;i++)
	{	
		if(i%2==1)
		{
			for(j=1;j<=i/2;j++)
			{
				k=i-j;
				a[i][j-1]+=a[k][j]+1;
				if(j>=2)
				{
				for(c=0;c<j-1;c++)a[i][c]+=a[i][j-1];
				}
			}
		}
		else if(i%2==0)
		{
			for(j=1;j<=(i/2)-1;j++)
			{
				k=i-j;
				a[i][j-1]+=a[k][j]+1;
				if(j>=2)
				{
				for(c=0;c<j-1;c++)a[i][c]+=a[i][j-1];
				}
			}
		}
		a[i][0]++;
	}
	printf("%I64d",a[b][0]%100999);
}
