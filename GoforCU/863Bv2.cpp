#include<bits/stdc++.h>
using namespace std ;
int s[200],a,max1=INT_MAX;
Find(int i,int k,int count)
{
	int j;
	if(k>0&&(s[i+1]<s[i]||s[i+2]<s[i]))
		Find(i+1,k-1,count);
		
	count+=s[i];
	if(i+2+k>=a)
	{
	//	printf("%d\n",count);
		if(count<max1)max1=count;
		return 0;
	}
	Find(i+2,k,count);
}
main()
{
	int i;
	scanf("%d",&a);
	a*=2;
	for(i=0;i<a;++i)
	{
		scanf("%d",&s[i]);
	}
	sort(s,s+a);
	for(i=a-1;i>0;i--)
	{
		s[i]-=s[i-1];
	}
	Find(1,2,0);
	printf("%d",max1);
}
