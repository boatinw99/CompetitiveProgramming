#include<bits/stdc++.h>
using namespace std;
const int N=1e9,M=1e6+3 ;
main()
{
	int i,n,m,co=2 ;
	scanf("%d %d",&n,&m);
	if(n==2&&m==1)return 0*printf("2 2\n1 2 2\n");
	printf("2 %d\n",M);
	printf("1 %d 2\n",n);
	for(i=2;i<n-1;i++)
	{
		printf("1 %d 1\n",i);
		co++;
	}
	printf("1 %d %d\n",n-1,M-co);
	int w=m-n+1;
	for(i=2;w>0;i++)
	{ 
		for(int j=i+1;j<=n&&w>0;j++,w--)
		printf("%d %d %d\n",i,j,N);
	}
}
