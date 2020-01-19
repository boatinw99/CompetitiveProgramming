#include<bits/stdc++.h>
using namespace std ;
main()
{
	int a,i,i1,i2 ;
	scanf("%d",&a);
	int s[a];
	for(i=0;i<a;i++)
	{
		scanf("%d %d",&i1,&i2);
		if(i1>i2)s[i]=i1-i2;
		else s[i]=i2-i1;
	}
	sort(s,s+a);
	for(i=a-1;i>0;i--)
	{
		
		if(s[i-1]>s[i])s[i-1]=s[i-1]-s[i];
		else if(s[i-1]<=s[i]) 
		s[i-1]=s[i]-s[i-1];
	}
	printf("%d",s[0]);
	
}
