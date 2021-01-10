#include<stdio.h>
int a[10]={5,6,3,1,0,2,4,8,9,7};
int temp,last = 9 ;
int reheap(int index)
{
	if(index*2+1<=last)
	{
		reheap(index+1);
	}
	if(index*2+1<=last&&index*2+2<=last)
	{
		if(a[index*2+1]>a[index]&&a[index*2+1]>a[index*2+2])
		{
			temp=a[index];
			a[index]=a[index*2+1];
			a[index*2+1]=temp;
			
		}
		else if(a[index*2+2]>a[index]&&a[index*2+1]<a[index*2+2])
		{
			temp=a[index];
			a[index]=a[index*2+2];
			a[index*2+2]=temp;
		}
	}
	else if(index*2+2>last&&index*2+1<=last)
	{
		if(a[index*2+1]>a[index])
		{
			temp=a[index];
			a[index]=a[index*2+1];
			a[index*2+1]=temp;
		}
	}
}
main()
{
	for(int i=0;i<=9;i++)
	{
		reheap(0);
		printf("%d ",a[0]);
		a[0]=a[last];
		last--;
	}
}

