#include<stdio.h>
typedef long long ll;
main()
{
	ll x,y,k,p=5,co=0,pr=0,j;
	scanf("%lld %lld %lld",&x,&y,&k);
	for(p;p<=x;p*=5)co+=x/p;
	pr=co%k;
	for(x=x+1;x<=y;x++)
	{
		for(j=x;j%5==0;j/=5)co++;
		pr=(pr+co)%k;
	}
	printf("%d",pr);
}
