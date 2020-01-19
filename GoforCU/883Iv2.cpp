#include<bits/stdc++.h>
using namespace std;
int s[300009];
int ch[300009];
main()
{
	int n,k,l=-1,r=1e9,i,j,m ;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
	}
	sort(s,s+n);
	while(l+1<r)
	{
		m=(l+r)/2;
		ch[0]=m;
		for(i=0,j=0;i<n;i++)
		{
			if(ch[i]==m)
			{			
				if(j-i<k)j=i+k-1;
				if(j>=n)break;
				while(s[j]-s[i]<=m)
				{
					j++;
					ch[j]=m;
					if(j>=n)break;
				}	
			}
		}
		if(ch[n]==m)r=m;
		else l=m;
	}
	printf("%d",r);
}
