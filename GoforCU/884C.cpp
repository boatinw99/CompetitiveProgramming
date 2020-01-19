#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int s[100009];
bool b[100009];
main()
{
	int n,i,j,count;
	ll max1=0,max2=0,pr=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
		b[i]=0;
	}
	for(i=1;i<=n;i++)
	{
		count = 0 ;
		for(j=s[i];b[j]==0;)
		{
			b[j]=1;
			count++;
			j=s[j];
		}
		if(count>max1)
		{
			pr+=max2*max2;
			max2=max1;
			max1=count;
		}
		else if(count>max2)
		{
			pr+=max2*max2;
			max2=count;
		}
		else pr+=count*count;
	}
	printf("%I64d",pr+(max1+max2)*(max1+max2));
}
