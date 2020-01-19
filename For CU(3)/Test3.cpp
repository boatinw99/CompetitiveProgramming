#include<bits/stdc++.h>
using namespace std ;
char s[2000];
int a,max1=0,count1=1,check;
Call(string q,string w,int i,int j,int k)
{
	int i1,j1;
	if(k==a)
	{
		count1 = 0 ;
		if(i>=1)count1++;
		if(q[1]!=q[0]&&i>=2)count1+=2;
		else if(i>=2)count1+=1;
		if(i>=3)
		{
			for(i1=2;i1<i;i1++)
			{
				check=0;
				if(q[i1]==q[i1-1])check++;
				if(q[i1]==q[i1-2])check++;
				if(q[i1-1]==q[i1-2])check++;
				count1+=3-check;
				if(check==3)count1+=1;
			}
		}
		if(j>=1)count1++;
		if(w[1]!=w[0]&&j>=2)count1+=2;
		else if(j>=2)count1+=1;
		if(j>=3)
		{
			for(j1=2;j1<j;j1++)
			{
				check=0;
				if(w[j1]==w[j1-1])check++;
				if(w[j1]==w[j1-2])check++;
				if(w[j1-1]==w[j1-2])check++;
				count1+=3-check;
				if(check==3)count1+=1;
			}
		}
		if(count1>=max1)
		{
			max1=count1;
			for(i1=0;i1<i;i1++)printf("%c ",q[i1]);
			printf("||");
			for(j1=0;j1<j;j1++)printf("%c ",w[j1]);
			printf("%d\n",max1);
				
		}
		return 0 ;
	}
	else
	{
	string c=q;
	q[i]=s[k];
	Call(q,w,i+1,j,k+1);
	w[j]=s[k];
	Call(c,w,i,j+1,k+1);
	}
	
}
main()
{
	int i ;
	scanf("%d",&a);
	string q="aasadasdasda",w="aasdasdasd";
	for(i=0;i<a;i++)
	{
		scanf(" %c",&s[i]);
	}
	Call(q,w,0,0,0);
	printf("%d",max1);
}
