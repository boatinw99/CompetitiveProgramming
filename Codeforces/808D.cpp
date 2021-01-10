#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l,r,n ;
ll s[100009];
ll qs[100009];
main()
{
	ll i,j,x,y,sum1,sum2,m ;
	scanf("%I64d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%I64d",&s[i]);
		qs[i]=qs[i-1]+s[i];
	}
	for(i=1;i<=n;i++)
	{
		l=1,r=n+1;
		while(l+1<r)
		{
			m=(l+r)/2;
			if(m>=i)
			{
				sum2=qs[n]-qs[m-1];
				sum1=qs[m-1];
			}
			else 
			{
				sum2=qs[n]-qs[m-1]-s[i];
				sum1=qs[m-1]+s[i];
			}	
			//printf("%d %d\n",sum1,sum2);
			if(sum1==sum2)return 0*printf("YES");
			if(sum1<sum2)l=m;
			else r=m;
		}	
		//printf("\n");
	}
	printf("NO");
}



