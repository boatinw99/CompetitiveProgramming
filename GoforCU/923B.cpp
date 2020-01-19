#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
const int N=1e5+9; 
ll sum[N],a[N],b[N],mul[N],*p;
main()
{
	ll n,i,j;
	scanf("%I64d",&n);
	for(i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	for(i=1;i<=n;i++)
		scanf("%I64d",&b[i]),b[i]+=b[i-1];
	for(i=1;i<=n;i++)
	{
		p=upper_bound(b+i,b+n+1,a[i]+b[i-1]);
		mul[i-1]--;
		mul[p-b-1]++;
		sum[p-b]+=a[i]+b[i-1]-b[p-b-1];
	}
	for(i=n-1;i>0;i--)mul[i]+=mul[i+1];
	for(i=1;i<=n;i++)
	{
		printf("%I64d ",mul[i]*(b[i]-b[i-1])+sum[i]);
	}
	
}
