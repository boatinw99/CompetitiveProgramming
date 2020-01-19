#include<bits/stdc++.h>
using namespace std;
int s[100009];
int co[100009];
main()
{
	int n,i;
	int ch1=0,ch2=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&s[i]);
	for(i=0;i<n;i++)
	{
		if(s[i]>ch2)ch1=ch2,ch2=s[i],co[s[i]]--;
		else if(s[i]>ch1)ch1=s[i],co[ch2]++;
	}
	int max1=-999,max2;
	for(i=n;i>0;i--)
		if(co[i]>=max1)max1=co[i],max2=i;
	printf("%d",max2);
}
