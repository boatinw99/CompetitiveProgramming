#include<bits/stdc++.h>
using namespace std ;
int a[200009];
int b[200009];
main()
{
	int i,n,j,x ;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		b[x]=i;
	}
	for(i=2;i<=n;)
	{
		if(b[a[i]]>b[a[i-1]])
		{
			i++;
		}
		else break ;
	}
	printf("%d",n-i+1);
}
