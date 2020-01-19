#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
main()
{
	ll n,k,i,j,x;
	scanf("%I64d %I64d",&n,&k);
	for(i=1;i<=n/2;i++)
	{
		if(n%i==0&&k*(k+1)/2<=i)
		{
			for(j=1;j<k;j++)
			{
				printf("%d ",j*(n/i));
			}
			printf("%d",(i-(k-1)*k/2)*(n/i));
			return 0;
		}
	}
	
	
}
