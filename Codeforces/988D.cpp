#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
ll a[200009];
ll pr[5];
main()
{
	ll n,i,j,k ;
	ll max1=0;
	scanf("%I64d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&a[i]);
	}
	sort(a,a+n);
	ll mask;
	bool d1,d2;
	for(i=0;i<n;i++)
	{
		for(mask=1;mask<=2e9;mask*=2)
		{
			d1=binary_search(a,a+n,a[i]-mask);
			d2=binary_search(a,a+n,a[i]-mask-mask);
			if(d1==1&d2==1)
			{
				max1=3;
				pr[0]=a[i];
				pr[1]=a[i]-mask;
				pr[2]=a[i]-mask-mask;
				break; 
			}
			else if(d1==1&&max1<2)
			{
				max1=2;
				pr[0]=a[i];
				pr[1]=a[i]-mask;
			}
			else if(max1==0)
			{
				max1++; 
				pr[0]=a[i];
			}	
		}
	}
	printf("%I64d\n",max1);
	for(i=0;i<max1;i++)printf("%I64d ",pr[i]);
}

