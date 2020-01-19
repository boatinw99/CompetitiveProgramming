#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=6e6+9;
ll s[N],dy[N],ch[N];
main()
{
	ll n,l,i;
	scanf("%lld %lld",&n,&l);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&s[i]);
	}
	dy[0]=s[0];
	for(i=1;i<n;i++)
	{
		if((i-1)-ch[i-1]+1>=l)
		{
			dy[i]=max(dy[i-1]+s[i]-s[ch[i-1]],s[i]);
			if(s[i]==dy[i])ch[i]=i;
			else ch[i]=ch[i-1]+1;
		}
		else 
		{
			dy[i]=max(dy[i-1]+s[i],s[i]);
			if(s[i]==dy[i])ch[i]=i;
			else ch[i]=ch[i-1];
		}
	}
	ll max1=0,seq=0;
	for(i=0;i<n;i++)
		{
			if(dy[i]>max1)max1=dy[i],seq=i-ch[i]+1;
			else if(dy[i]==max1)seq=min(seq,i-ch[i]+1);
		}
	printf("%lld\n%lld",max1,seq);
}
