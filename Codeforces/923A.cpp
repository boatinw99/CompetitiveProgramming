#include<bits/stdc++.h>
using namespace std;
int s[1000009],q=0;
bool e[1000009];
int min1=0;
int find(int o)
{
	int j;
	for(j=q-1;j>=0;j--)
	{
		//printf("%d\n",j);
		if(o%s[j]==0)
		{
			return s[j];
		}
	}
	return 0 ;
}
int P(int i)
{
	int x=find(i);	
	if(x==i||x==0)return 1;
	min1=min(min1,i-x+1);
	return x;
}
main()
{
	int n,i,j;
	bool b;
	scanf("%d",&n);
	for(i=2;i<1000000;i++)
	{
		b=0;
		for(j=0;j<q&&s[j]*s[j]<=i;j++)
		{
			if(i%s[j]==0)
			{
				b=1;
				break;
			}
		}
		if(!b)e[i]++,s[q]=i,q++;
	}
	int x=P(n);
	min1=n-x+1;
	for(i=1;i<x;i++)
	{
		P(n-i);
	}
	printf("%d",min1);
}
