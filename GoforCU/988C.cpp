#include<bits/stdc++.h>
using namespace std ;
map<int,pair<int,int> > ma;
int a[200009];
main()
{
	int m,k,i,j,x,y,d,e,n ;
	scanf("%d",&m);
	for(k=1;k<=m;k++)
	{
		x=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			x+=a[i];
		}
		for(i=1;i<=n;i++)
		{
			d=x-a[i];
			if(ma[d].first!=0&&k!=ma[d].first)
			{
				printf("YES\n");
				printf("%d %d\n",ma[d].first,ma[d].second);
				printf("%d %d",k,i);
				return 0;
			}
			ma[d].first=k;
			ma[d].second=i;
		}
	}
	printf("NO");
}
