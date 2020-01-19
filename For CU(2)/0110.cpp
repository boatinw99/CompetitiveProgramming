#include<stdio.h>
int count=0;
int s[100];
int Check1(int,int);
int Check(int,int);
Check0(int a,int b)
{   
	if(a<=b)
	{ 
	    if(a==0)
		{  s[0]=0;
		   Check1(a+1,b);
		}
		else if(a>=1&&s[a-1]!=0)
		{
			s[a]=0;
			Check1(a+1,b);
		}
		else 
		{
			Check1(a,b);
		}
	}
}
Check1(int a,int b)
{   
	if(a<=b)
	{
	   if(a==0)
	   {
	   		s[0]=1;
	   		Check(a+1,b);
	   }
	   else 
	   {
	    s[a]=1;	
		Check(a+1,b);
	   }
	}
}
Check(int a,int b)
{   
   if(a<=b)
   {  
   	Check0(a,b);
	Check1(a,b);
	count++;
   }
}
main()
{   int a ;
	scanf("%d",&a);
	Check(0,a-1);
	printf("%d",count+1);
}
