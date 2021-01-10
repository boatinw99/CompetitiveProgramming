#include<stdio.h>
int p=0,e=0;
int a[8][8]={0,0,0,0,0,-1,0,0,
			 0,0,0,-1,0,-1,0,0,
			 0,0,0,-1,0,0,0,0,
			 0,-1,-1,0,-1,0,0,0,
			 0,0,0,0,-1,0,-1,-1,
			 -1,0,0,0,-1,0,0,0,
			 0,0,0,0,-1,-1,0,0,
			 0,0,-1,0,0,0,0,0
			};
char b[50]={0};
Check(int i,int j,int count)
{   
	if(a[i][j]==-1);
	else 
	{
		count++;
		a[i][j]=count;			
		if(i-1>=0&&(a[i-1][j]==0||a[i-1][j]>count+1))
		{
			Check(i-1,j,count);
		}
		if(j-1>=0&&(a[i][j-1]==0||a[i][j-1]>count+1))
		{
			Check(i,j-1,count);
		}
		if(i+1<=7&&(a[i+1][j]==0||a[i+1][j]>count+1))
		{
			Check(i+1,j,count);
		}
		if(j+1<=7&&(a[i][j+1]==0||a[i][j+1]>count+1))
		{
			Check(i,j+1,count);
		}
	}	
}
Checkprintf(int i,int j,int count)
{   	
	if(a[i-1][j]==count-1&&i-1>=0)
	{
		b[e]='D';
		e++;

		Checkprintf(i-1,j,count-1);		
	}
	else if(a[i][j-1]==count-1&&j-1>=0)
	{   
		b[e]='R';
		e++;
	
		Checkprintf(i,j-1,count-1);
	}
	else if(a[i+1][j]==count-1&&i+1<=7)
	{
		b[e]='U';
		e++;

		Checkprintf(i+1,j,count-1);
	}
	else if(a[i][j+1]==count-1&&j+1<=7)
	{
		b[e]='L';
		e++;

		Checkprintf(i,j+1,count-1);
	}
	
}
main()
{   int i,j;
	Check(0,7,-1);
	p=a[7][0];	
	a[0][7]=0;
	printf("%d\n",p);


	Checkprintf(7,0,p);
	
	for(j=p-1;j>=0;j--)
	printf("%c ",b[j]);
}
