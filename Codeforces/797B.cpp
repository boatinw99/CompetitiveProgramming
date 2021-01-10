#include<bits/stdc++.h>
using namespace std ;
int s[100009];
int x1=-1e5,x2=100000;
main()
{
	int n,co=0,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
		if(s[i]>0)co+=s[i];
		if(s[i]%2==-1&&s[i]>x1)x1=s[i];
		else if(s[i]%2==1)x2=min(s[i],x2);
	}
	if(co%2==1)return 0*printf("%d",co);
	co=max(co-x2,co+x1);
	printf("%d",co);
}
