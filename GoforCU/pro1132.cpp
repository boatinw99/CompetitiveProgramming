#include<bits/stdc++.h>
using namespace std ;
main()
{
	int m,n,i,j,k,d;
	bool q;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d %d",&n,&k);
		d=k;
		q=0;
		while(d<=n)
		{
			if(d==n)
			{
				q++;
				break;
			}
			d=d*2-k+1;
		}
		if(q==1)printf("B\n");
		else printf("A\n");
	}
}
