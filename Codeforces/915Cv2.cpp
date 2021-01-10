#include<bits/stdc++.h>
using namespace std;
string s,q ;
int a[10];
int pr()
{
	int i;
	for(i=9;i>=0;i--)
	{
		while(a[i]--)printf("%d",i);
	}
}
int dfs(string e,int i)
{
	int j,x;
	if(a[q[i]-48]!=0)
	{
		a[q[i]-48]--;
		if(i>=s.size()-1)
		{
			cout << e;
			cout << q[i];
			return 0 ;
		}
		x=dfs(e+q[i],i+1);
	}
	else
	{
		for(j=q[i]-49;j>=0;j--)
		{
			if(a[j]>0)
			{
				cout << e;
				printf("%d",j);
				a[j]--;
				pr();
				return 0;
			}
		}
		return 1;
	}
	if(x==1)
	{
	a[q[i]-48]++;
		for(j=q[i]-49;j>=0;j--)
		{
			if(a[j]>0)
			{
				cout << e;
				printf("%d",j);
				a[j]--;
				pr();
				return 0;
			}
		}
		
		return 1;
	}


	
}
main()
{
	int i,j,x;
	cin >> s >> q;
	for(i=0;i<s.size();i++)
	{
		a[s[i]-48]++;
	}
	if(s.size()<q.size())pr();
	else
	{
		if(a[q[0]-48]==0)
		{
			int j=q[0]-49;
			while(a[j]==0)j--;
			printf("%d",j);
			a[j]--;
			pr();
		}
		else
		{
			string p;
			p=q[0];
			a[q[0]-48]--;
			x=dfs(p,1);
			if(x==1)
			{
				a[q[0]-48]++;
				j=q[0]-49;
				while(a[j]==0)j--;
				if(j>=0)printf("%d",j);
				a[j]--;
				pr();
			}
		}
	}
}
