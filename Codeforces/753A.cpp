#include<bits/stdc++.h>
using namespace std;
main()
{
	int n,i,j ;
	scanf("%d",&n);
//	if(n==1)return 0*printf("1\n1");	
	for(i=1;i*(i+1)<=n*2;i++);i--;
	printf("%d\n",i);
	for(j=1;j<i;j++)printf("%d ",j);
	printf("%d",n-((i-1)*i/2));
}
