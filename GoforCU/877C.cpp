#include<bits/stdc++.h>
using namespace std;
main()
{
	int i,a;
	scanf("%d",&a);	
	printf("%d\n",a/2+a);
	for(i=2;i<=a;i+=2)printf("%d ",i);
	for(i=1;i<=a;i+=2)printf("%d ",i);
	for(i=2;i<=a;i+=2)printf("%d ",i);
}
