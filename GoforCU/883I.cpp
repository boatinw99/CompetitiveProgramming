#include<bits/stdc++.h>
using namespace std;
int s[300009];
main()
{
	int n,k,i,l=-1,r=1e9,m,j ;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
	}
	sort(s,s+n);
	int d ;
	bool b;
	for(i=0;i<n;i++)
	{
		printf("%d ",s[i]);
	}
	while(l+1<r)
	{
		b=0;
		d=n%k;
		m=(l+r)/2;
		for(i=0,j=0;i<n;)
		{					
			if(s[i+k-1]-s[i]>m||i+k-1>=n)
			{
				b=1;
				break;
			}
			for(j=0;j<=d;)
			{
				if(s[i+j+k-1]-s[i]>m)
				{
					j--;
					break;
				}
				j++;
				if(j>d)
				{
					j--;
					break;
				}
			}
			d-=j;
			i=i+j+k;
		}
		//printf("%d %d\n",m,b);
		if(b==1)l=m;
		else r=m;
	}
	printf("%d",r);
}
