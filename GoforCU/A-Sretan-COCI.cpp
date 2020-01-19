#include<bits/stdc++.h>
using namespace std ;
int K ;
int a[34],*p;
void pr(int i,int k)
{
	//printf("\n%d %d\n",i,k);
	if(i==0)return ;
	if(k<=(a[i]+a[i-1])/2)
	{
		printf("%d",4);
		pr(i-1,k-a[i-1]+a[i-2]);
	}
	else 
	{
		printf("%d",7);
		pr(i-1,k-a[i]+a[i-1]);
	}	
}
main()
{
	scanf("%d",&K);
	int i ;
	a[0]=1; 
	for(i=1;i<=30;i++)a[i]=a[i-1]*2;
	for(i=2;i<=30;i++)
	{
		a[i]+=a[i-1];
	}
	p=lower_bound(a+1,a+31,K);
	pr(p-a,K);
}
