#include<bits/stdc++.h>
using namespace std;
vector<int>v[509];
vector<int>::iterator it;
int prime[1009],p=0;
int find(int in)
{
	int i,j,k,co=in,pr=1 ;
	for(i=0;prime[i]*prime[i]<=in&&i<p;i++)
	{
		k=1;
		while(co%prime[i]==0)co/=prime[i],k++;
		pr*=k;
	}
	if(co>1)pr*=2;
	return pr;
}
main()
{
	int m,i,j,x,y,d ;
	bool k;
	scanf("%d",&m);
	//prime
	for(i=2;i*i<=1000000;i++)
	{
		k=0;
		for(j=0;j<p&&prime[j]*prime[j]<=i;j++)
		{
			if(i%prime[j]==0)
			{
				k++;
				break;
			}
		}
		if(k==0)prime[p]=i,p++;
	}
	//
	for(i=1;i<=1000000;i++)
	{
		x=find(i);
		if(x<=500)
		v[x].push_back(i);
	}
	for(i=1;i<=500;i++)sort(v[i].begin(),v[i].end());
	while(m--)
	{
		scanf("%d %d %d",&x,&y,&d);
		printf("%d\n",upper_bound(v[d].begin(),v[d].end(),y)-lower_bound(v[d].begin(),v[d].end(),x));
	}
	
}
