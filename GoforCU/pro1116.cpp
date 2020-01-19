#include<bits/stdc++.h>
using namespace std ;
double s[1000009];
main()
{
	int i,j,n,k;
	double x;
	double max1=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lf",&s[i]);
	}
	for(i=1;i<=n;)
	{
		while(s[i+1]>=s[i]&&i<=n)i++;
		x=s[i];
		for(j=i+1;j<=n&&s[j]<=s[i];j++)x=min(s[j],x);
		max1=max(max1,(s[i]-x)/2);
		i=j;	
	}
	printf("%.6lf",max1);
}
