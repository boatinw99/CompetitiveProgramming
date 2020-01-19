#include<bits/stdc++.h>
using namespace std ;
int s[20009];
int dy[20009][2];
main()
{
	int n,a,b,x,i,j ;
	scanf("%d %d %d",&n,&a,&b);
	s[0]=0; s[a+1]=n;
	for(i=1;i<=a;i++)
	{
		scanf("%d",&s[i]);
	}
	for(i=1;i<=b;i++)
	{
		scanf("%d",&x);
		for(j=i;j<=a+1-b+i;j++)
		{
			dy[j][1]=max(dy[j-1][0],dy[j-1][1])+(s[j]-s[j-1])*x;
			dy[j-1][0]=dy[j-1][1];
		}
		dy[j-1][0]=dy[j-1][1];
	}
	printf("%d",dy[a+1][0]);
}
