#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll s[100009];
main()
{
	ll i,j,x1=0,x2=0,x3=0;
	scanf("%I64d",&n);
	for(i=0;i<n;i++)scanf("%I64d",&s[i]);
	sort(s,s+n);
	for(i=0;i<n;i++)if(s[i]==s[0])x1++;else break;j=i;
	for(i=j;i<n;i++)if(s[i]==s[j])x2++;else break;j=i;
	for(i=j;i<n;i++)if(s[i]==s[j])x3++;else break;
	ll co=0;
	if(x1>=3)printf("%I64d",x1*(x1-1)*(x1-2)/3/2);
	else if(x1==2)printf("%I64d",x2);
	else if(x1==1)
	{
		if(x2>=2)printf("%I64d",x2*(x2-1)/2);
		else if(x2==1)printf("%I64d",x3);
	}
}
