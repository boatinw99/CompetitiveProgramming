#include<bits/stdc++.h>
using namespace std;
int s[1009];
main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
		if(s[i]%s[0]!=0)return 0*printf("-1");
	}
	printf("%d\n",2*n);
	for(i=0;i<n;i++)
		printf("%d %d ",s[i],s[0]);
}
