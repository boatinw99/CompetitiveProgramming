#include<bits/stdc++.h>
using namespace std;
main()
{
	int n,k,i;
	scanf("%d %d",&n,&k);
	printf("%d\n",n-k+1);
	for(i=1;i<=n-k+1;i++)
	{
		printf("%d %d\n",i,i+1);
	}
	int j=(n-2)/(k-1);
	int j1=(n-2)/(k-1);
	for(i=n-k+3;i<=n;i++,j+=j1)
	{
		if(j+1>n-k+1)j=1;
		printf("%d %d\n",i,j+1);
	}
}
