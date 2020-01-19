#include<bits/stdc++.h>
using namespace std;
int n,p=0;
int s[1000009],*q;
main()
{
	int i=0,in;
	scanf("%d",&n);
	for(i=0;i<1000002;i++)s[i]=INT_MAX;
	for(i=0;i<n;i++)
	{
		scanf("%d",&in);
		q=upper_bound(s,s+n,in);
		s[q-s]=in;
	}
	for(i=0;s[i]!=INT_MAX;i++);
	printf("%d",n-i);
}
