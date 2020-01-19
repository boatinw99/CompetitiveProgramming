#include<bits/stdc++.h>
using namespace std ;
const int N=6e6+7;
typedef long long ll ;
ll s[N],mi[N];
ll c[N][2];
main()
{
	ll i,j,d,n,k,q,co=0;
	ll max1=0,r=0;
	scanf("%lld %lld",&n,&k);	
	for(i=1;i<=n;i++)scanf("%lld",&s[i]);
	for(i=1;i<=n;i++)
	{
		if(s[i]<=0)
		{
			mi[i]=i;
			q=s[i];
			for(j=i-1;j>0;)
			{
				if(!mi[j])
				{
					if(q+s[j]<=0)mi[j]=i,q+=s[j];
					else break ;
					j--;
				}
				else
				{
					q+=c[j][0];
					j=c[j][1];
				}
			}
			c[i][0]=q; c[i][1]=j;
		}
	}
	//
	for(i=1;i<=n;i++)if(!mi[i])mi[i]=N;
	//
	for(i=1,j=1;i<=n;i++)
	{
		co+=s[i];
		if(i-j==k)co-=s[j],j++;
		while(i>mi[j]&&j<i)
		{
			co-=s[j];
			j++;
		}
		if(co>max1)max1=co,r=i-j+1;
		else if(co==max1)r=min(r,i-j+1);
	}
	printf("%lld\n%lld",max1,r);
} 
