#include<stdio.h>
int max=0,b[10][10];
Checkmax(int i,int j,int i1,int j1)
{	int i2=j1+i-1,j2=i1+j-1;
	if(i==0&&j==0)
	{
		if(b[i2][j2]>max)
		max=b[i2][j2];
	}
	else if(i!=0&&j==0)
	{
		if(b[i2][j2]-b[i-1][j2]>max)
		{
			max=b[i2][j2]-b[i-1][j2];
		}
	}
	else if(i==0&&j!=0)
	{
		if(b[i2][j2]-b[i2][j-1]>max)
		{
			max=b[i2][j2]-b[i2][j-1];
		}
	}
	else
	{
		if(b[i2][j2]-b[i2][j-1]-b[i-1][j2]+b[i-1][j-1]>max)
		{
			max=b[i2][j2]-b[i2][j-1]-b[i-1][j2]+b[i-1][j-1];
		}
	}
	if(i2<=9&&j2<=9)
	{
		if(j2<=9)
		{
			Checkmax(i,j,i1+1,j1);
		}
		if(i2<=9)
		{
			Checkmax(i,j,i1,j1+1);
		}
	}
}
main()
{
  int a[10][10]={5 ,3, 1, 0, 9, -1 ,6, 7, 2, -2,
    -4 ,-6, 2, 5 ,6, 7, 8, 9, 0 ,10,
    5, 6 ,4 ,9 ,-2, 4, -5,6 ,-9, 7,
    2 ,-7, 8, 6 ,6, 8 ,9 ,5, 3, 1,
    1, 9, 6 ,-3 ,-5, 7, -7 ,4 ,5 ,-5,
    3 ,-3 ,3 ,6 ,1 ,3, 3, -6, 4, 1,
    -5 ,2 ,-8, 4, -2, -3, 1, 4, 7, -5,
    6, 1 ,5 ,3, 7, 2 ,-4, 2, -5, 6,
    7 ,5,6 ,9, 8, 1 ,4, 5, 2 ,2,
    8 ,-6 ,7, -8 ,4, 9, 2, -3, 3, -1};
    int i,j,c,d,c1,d1,temp;
    b[0][0]=a[0][0];
    for(i=1;i<=9;i++)
      {
	  b[0][i]=b[0][i-1]+a[0][i];
	  b[i][0]=b[i-1][0]+a[i][0];
	  }
    for(i=1;i<=9;i++)
	{
        for(j=1;j<=9;j++)
		{
            b[i][j]=b[i-1][j]+b[i][j-1]+a[i][j]-b[i-1][j-1];
        }
    }
    for(i=0;i<=9;i++)
    {
    	for(j=0;j<=9;j++)
    	printf("%d ",b[i][j]);
    	printf("\n");
	}
	scanf("%d",&c);
	scanf("%d",&d);
	scanf("%d",&c1);
	scanf("%d",&d1);
	temp=c1;
	c1=c+d1-1;
	d1=d+temp-1;
	if(c==0&&d==0)
	{
		printf("%d",b[c1][d1]);
	}
	else if(c!=0&&d==0)
	{
		printf("%d",b[c1][d1]-b[c-1][d1]);
	}
	else if(c==0&&d!=0)
	{
		printf("%d",b[c1][d1]-b[c1][d-1]);
	}
	else
	{
		printf("%d",b[c1][d1]-b[c1][d-1]-b[c-1][d1]+b[c-1][d-1]);
	}
	for(i=0;i<=9;i++)
		{
			for(j=0;j<=9;j++)
				Checkmax(i,j,1,1);
		}	
	printf("\n%d",max);
	

}
