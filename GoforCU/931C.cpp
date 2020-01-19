#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll co=0;
pair<ll,ll> a[3];
ll countc[3];
main()
{
	ll i,n,j,x,d=0 ; bool k=0;
	scanf("%I64d",&n);
	for(i=0;i<n;i++)
	{
		k=0;
		scanf("%I64d",&x); co+=x;
		for(j=0;j<d;j++)
		{	
			if(x==a[j].first)
			{
				k=1;break; 
			}
		}
		if(k==1)a[j].second++;
		if(k==0)a[d].first=x,a[d].second=1,d++;
	}
	if(d==2&&(a[0].first-a[1].first==2||a[0].first-a[1].first==-2))a[2].first=(a[0].first+a[1].first)/2;
	else if(d<=2)
	{
		printf("%d\n",n);
		for(i=0;i<d;i++)while(a[i].second--)printf("%d ",a[i].first);
		return 0;
	} 
	sort(a,a+3);
	countc[0]=0; countc[2]=0;
	countc[1]=n; 
	if(co<a[1].first*n)countc[0]+=a[1].first*n-co,countc[1]-=countc[0];
	else countc[2]+=co-a[1].first*n,countc[1]-=countc[2] ;
	ll min1=min(countc[0],a[0].second)+min(countc[1],a[1].second)+min(countc[2],a[2].second);
	int l=countc[0],r=countc[2];
	while(countc[1]>1)
	{
		countc[0]++; countc[2]++;
		countc[1]-=2;
		if(min(countc[0],a[0].second)+min(countc[1],a[1].second)+min(countc[2],a[2].second)<min1)
		{
			min1=min(countc[0],a[0].second)+min(countc[1],a[1].second)+min(countc[2],a[2].second);
			l=countc[0],r=countc[2];			
		}
	}
	ll t=n-(l+r);
	printf("%I64d\n",min1);
	while(t--)printf("%I64d ",a[1].first);
	while(l--)printf("%I64d ",a[0].first);
	while(r--)printf("%I64d ",a[2].first);
}
