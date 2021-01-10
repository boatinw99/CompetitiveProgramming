#include<bits/stdc++.h>
using namespace std ;
double s[1009];
int a,k=0;
Dif(double m1,int i,int j,int di)
{
	if((s[di]-s[i])/(di-i)==m1)
	{
		if(di<a)
		Dif(m1,i,j,di+1);
		else if(j!=-1&&di==a)
		{
			k=1;
			return 0 ;
		}
	}
	else if(j==-1)
	{
		j=di;
		if(di<a)
		Dif(m1,i,j,di+1);
		else 
		{
			k=1;
			return 0 ;
		}
	}
	else if(j!=-1&&(s[di]-s[j])/(di-j)==m1)
	{
		if(di<a)
		Dif(m1,i,j,di+1);
		else 
		{
			k=1;
			return 0 ;
		}	
	}
}
main()
{
	int i,x=0 ;
	double m1;
	cin >> a;
	for(i=1;i<=a;i++)
	{
		cin >> s[i];
	}
	m1=s[2]-s[1];
	x=Dif(m1,1,-1,3);
	if(k==1)
	{
		printf("Yes");
		return 0;
	}
	m1=(s[3]-s[1])/2.0;
	if((s[2]-s[1])!=m1)
	x=Dif(m1,1,2,4);
	if(k==1)
	{
		printf("Yes");
		return 0;
	}
	m1=s[3]-s[2];
	if(s[2]-s[1]!=m1)
	x=Dif(m1,2,1,4);
	if(k==1)
	{
		printf("Yes");
		return 0;
	}
	printf("No");
	
}
