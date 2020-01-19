#include<bits/stdc++.h>
using namespace std;
int s[1000009],*p1,*p2;
main()
{
	int m,n,k,l,i,j,x,co,count=0;
	scanf("%d %d %d %d",&n,&m,&k,&l);
	for(i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
	}
	s[n]=-1;
	while(k--)
	{
		co=0,count=0;
		for(i=0;i<m;i++)
		{
			scanf("%d",&x);
			if(co<n)
			{
			p2=lower_bound(s+co,s+n,x+l);
			if(x+l<*p2)p2--;
			p1=lower_bound(s+co,s+n,x-l);	
			count+=(p2-p1)+1;
			co=p2-s+1;
			if(p2==s+n||p1==s+n)count--;
			}
		}
		printf("%d\n",count);
		
	}
}
