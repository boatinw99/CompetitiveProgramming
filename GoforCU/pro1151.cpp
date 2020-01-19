#include<bits/stdc++.h>
using namespace std;
int s[200009],*p,r=0;
main()
{
	int m,i,j,x ;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d",&x);
		p=lower_bound(s,s+r,x);
		s[p-s]=x;
		if(p-s==r)r++;
	}
	printf("%d",r);
}
