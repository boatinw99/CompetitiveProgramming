#include<stdio.h>
const int N=1e6+9;
int l[N],r[N];
int s[N];
main()
{
	int n,i,j,p,k ;
	int l1=0,r1=0 ; 
	long long pr=0;
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
		if(s[i]==k)p=i;
	}
	for(i=p;i<=n;i++)
	{
		if(s[i]<k)l1++;
		else if(s[i]>k)r1++;
		if(l1>r1)l1-=r1,r1=0;
		else r1-=l1,l1=0;
		if(l1==0)l[r1]++;
		else r[l1]++;
	} l1=0,r1=0;
	for(i=p;i>0;i--)
	{
		if(s[i]<k)l1++;
		else if(s[i]>k)r1++;
		if(l1>r1)l1-=r1,r1=0;
		else r1-=l1,l1=0;
		if(r1==0)pr+=l[l1];
		else if(l1==0)pr+=r[r1];
	}
	printf("%lld",pr);
}
