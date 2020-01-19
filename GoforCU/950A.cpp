#include<bits/stdc++.h>
using namespace std;
main()
{
	int l,r,a ;
	scanf("%d %d %d",&l,&r,&a);
	while(a--)
	{
		if(l>r)r++;
		else l++;
	}
	printf("%d",min(l,r)*2);
}
