#include<bits/stdc++.h>
using namespace std;
typedef long double ld ;
map<ld,ld>m;
ld s[200009];
main()
{
	ld count=0,pr=0,x;
	int i,n ;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%Lf",&s[i]),m[s[i]]++,count+=s[i];
	int size=n;
	for(i=0;i<n-1;i++)
	{
		x=m[s[i]];
		pr+=(count-x*s[i]-m[(s[i]-1)]*(s[i]-1)-m[(s[i]+1)]*(s[i]+1))-s[i]*(size-x-m[s[i]-1]-m[s[i]+1]);
		size--;m[s[i]]--;count-=s[i];
	}
	cout << pr;
}
