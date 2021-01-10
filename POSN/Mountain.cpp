#include<bits/stdc++.h>
using namespace std ;
set<int> q;
set<int>::iterator it;
main()
{
	int a,max,i,k=0 ;
	scanf("%d",&a);
	scanf("%d",&max);
	int s[a];
	for(i=0;i<a;i++)
	{
		scanf(" %d",&s[i]);
	}
	for(i=0;i<a;i++)
	{
		if(i==0&&s[i]>s[i+1])
		{
			q.insert(s[i]);
			i++;
		}
		else if(i==a-1&&s[i]>s[i-1])
		{
			q.insert(s[i]);
		}
		else if(s[i]>s[i-1]&&s[i]>s[i+1]) 
		{
			q.insert(s[i]);
			i++;
		}	
		else if(s[i]>s[i+1])i++;
	}
	k=q.size();
	if(k==0)printf("-1");
	else if(k>=max)
	{
		for(it=--q.end();max>0;it--,max--)
		{
			printf("%d\n",*it);	
		}	
	}
	else
	{
		for(it=q.begin();it!=q.end();it++)
		{
			printf("%d\n",*it);
		}
	}
	
	
}
