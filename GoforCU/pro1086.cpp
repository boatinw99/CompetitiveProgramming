#include<bits/stdc++.h>
using namespace std ;
int s[10009];
main()
{
	int n,k,a,i,j,di,t,co;
	int max1=0,r=0;
	scanf("%d %d %d",&n,&k,&a);
	j=1;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&di);
		for(t=0;t<di;t++)
		{
			s[j+t]=i;
		}
		j+=di;
	} int k1=0;
	for(i=1;s[i];i++)
	{
		k1=1; co=1;
		for(j=i+a;k1<k&&s[j];j+=a,k1++)
		{
			if(s[j]!=s[j-a])co++;
		}
		if(k1==k)
		{
			if(co>max1)max1=co,r=i;
			else if(co==max1)r=min(r,i);
		}
	}
	printf("%d %d",r,max1);
}
