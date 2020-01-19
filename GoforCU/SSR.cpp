#include<bits/stdc++.h>
using namespace std ;
int a[1000009];
main()
{
	int n,k,i;
	scanf("%d %d",&n,&k);
	string s;
	for(i=1;i<=k;i++)
	{
		s="";
		cin >> s;
		a[i]=a[i-1];
		if(s=="UR")
		{
			a[i]++;
		}
	}
	for(i=k+1;i<=n;i++)
	{
		s="";
		cin >> s;
		a[i]=a[i-1]-a[i-k];
		if(s=="UR")
		{
			a[i]++;	
		}
	}
	int max1=0;
	for(i=k;i<=n;i++)
	{
		max1=max(max1,a[i]);
	}
	printf("%d",max1);
}
