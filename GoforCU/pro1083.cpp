#include<bits/stdc++.h>
using namespace std ;
int s[1000009];
int lo[1000009];
int qs[1000009];
main()
{
	int i,n,j,m,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&s[i]); 
	for(i=1;i<=n;)
	{
		lo[i]=i; qs[i]=qs[i-1];
		for(j=i+1;j<=n&&s[j]>=s[j-1];j++)
		{
			lo[j]=i;
		} 
		qs[j-1]=qs[i]+s[j-1]-s[i];
		i=j;
	}
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d %d",&x,&y);
		printf("%d\n",s[y]-s[lo[y]]+qs[lo[y]-1]-qs[lo[x]-1]-s[x]+s[lo[x]]);
	}
}
