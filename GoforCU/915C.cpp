#include<bits/stdc++.h>
using namespace std;
int a[10];	
bool k=0;
string q,e ;
void pr()
{
	int i;
	for(i=9;i>=0;i--)
	{
		while(a[i]--)
		if(k==0&&i==0)k++;
		else printf("%d",i);
	}
}
main()
{
	int i,j ;

	cin >> q >> e;
	for(i=0;i<q.size();i++)
	{
		a[q[i]-48]++;
	}
	if(q.size()<e.size())pr();	
	else
	{
		for(i=0;i<e.size();i++)
		{
			if(a[e[i]-48]!=0)
			{
				if(k==0&&e[i]-48==0)k++;
				else printf("%d",e[i]-48);
				a[e[i]-48]--;
			}
			else
			{
				j=e[i]-49;
				while(a[j]==0)j--;
				if(k==0&&j==0)k++;
				else printf("%d",j);
				a[j]--;
				pr();
				return 0;
			}
		}
	}
}
