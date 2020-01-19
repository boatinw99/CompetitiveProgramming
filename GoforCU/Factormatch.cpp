#include<bits/stdc++.h>
using namespace std ;
const int N=1e6+7;
int a[100009];
int text[N],pattern[N];
int KMP[N];
main()
{
	int n,k,i,j,m,x ;
	scanf("%d %d",&n,&m);
	a[1]=1;
	for(i=2;i<=100000;i++)
	{
		a[i]=2;
	}
	for(i=2;i<=50000;i++)
	{
		for(j=2;j*i<=100000;j++)
		{
			a[j*i]++;
		}
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		text[i]=a[x];
	}
	for(j=0;j<m;j++)
	{
		scanf("%d",&x);
		pattern[j]=a[x];
	}	
	for(i=1,j=0;i<=n;)
	{
		if(pattern[i]==pattern[j])
		{
			KMP[i]=j+1;
			i++; j++;
		}
		else
		{
			if(j==0)i++;
			else j=KMP[j-1];
		}
	}
	int max1=0;
	for(i=0,j=0;i+(m-j)<=n&&j<m;)
	{
		if(text[i]==pattern[j])
		{
			i++; j++;		
			max1=max(max1,j);
		}
		else
		{
			if(j==0)i++;
			else j=KMP[j-1];
		}
	}	
	printf("%d",max1);
}
