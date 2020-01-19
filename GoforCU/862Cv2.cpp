#include<bits/stdc++.h>
using namespace std;
bool b[1000009];
main()
{
	int n,x,i,co;
	scanf("%d %d",&n,&x);
	if(n==1)
	{
		printf("YES\n%d",x);
	}
	else if(n==2)
	{
		if(x==0)printf("NO");
		else printf("YES\n0 %d",x);
	}
	else 
	{
		printf("YES\n");
		b[x]++;
		for(i=1;n>0;i++)
		{
			if(b[i]==0&&b[x^i]==0)
			{
				b[i]++;
				b[x^i]++;
				printf("%d ",i);
				x=x^i;
				n--;
				if(n==1)
				{
					printf("%d",x);
					return 0;
				}
			}
		}
	}
}
