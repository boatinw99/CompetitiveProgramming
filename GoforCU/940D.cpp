#include<bits/stdc++.h>
using namespace std;
int s[100009];
string q;
int minl=-1e9,maxl=1e9;
int minr=-1e9,maxr=1e9;
main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&s[i]);
	cin >> q;
	int i1,i2,i3,i4;		
	int max1,min1;
	for(i=4;i<n;i++)
	{
			max1=max(s[i-4],s[i-3]);
			max1=max(max1,s[i-2]);
			max1=max(max1,s[i-1]);
			max1=max(max1,s[i]);
			min1=min(s[i-4],s[i-3]);
			min1=min(min1,s[i-2]);
			min1=min(min1,s[i-1]);
			min1=min(min1,s[i]);
			i1=q[i-1]-48;
			i2=q[i-2]-48;
			i3=q[i-3]-48;
			i4=q[i-4]-48;
		if(!i1&&!i2&&!i3&&!i4&&(q[i]-48))
		{
			minl=max(max1+1,minl);
		}
		else if(i1&&i2&&i3&&i4&&!(q[i]-48))
		{
			maxr=min(maxr,min1-1);
		}/*
		else if(!i1&&!i2&&i3&&!i4)
		{
			maxl=min1;
		}
		else if(i1&&i2&&i3&&i4)
		{
			minr=max1;
		}*/
	}
	printf("%d %d",minl,maxr);
}
