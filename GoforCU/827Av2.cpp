#include<bits/stdc++.h>
using namespace std;
int n;
string y[3000009]={};
string s ;
main()
{
	int i,in,k,j,max1=0,T ;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		cin >> s;
		T=s.size();
		scanf("%d",&k);
		while(k--)
		{
			scanf("%d",&in);
			max1=max(max1,T+in-1);
			if(T>y[in].size())
			{
				y[in]=s;
			}
		}
	}
	j=1;
	//printf("\n");
	for(i=1;i<=max1;i++)
	{
		while(1)
		{
			T=y[j].size();
			if(i<=T+j-1&&i>=j)
			{		
				printf("%c",y[j][i-j]);
				break;
			}
			if(j>i)
			{
				printf("a");
				break;
			}
			j++;
		}	
	}	
}
