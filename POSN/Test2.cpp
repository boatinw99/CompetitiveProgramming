#include<bits/stdc++.h>
using namespace std ;
main()
{
	int a,i,check,k=0;
	map<int,int> p;
	map<int,int>::iterator it;
	scanf("%d",&a);
	int s[a];
	for(i=0;i<a;i++)
	{
		scanf(" %d",&s[i]);
	}
	scanf("%d",&check);
	for(i=1;i<a-1;i++)
	{
		if(s[i-1]>s[i]&&s[i+1]>s[i])
		{
			p[s[i]]=s[i];
			k++;
			i++;
		}
	}
	//printf("%d %d",check,k);
	if(k>=check)
	{
		it=p.end();
		it--;
		for(i=check;i>0;i--,it--)
		{
			printf("%d ",it->second);
		}
	}
	else 
	{
		for(it=p.begin();it!=p.end();it++)
		{
			printf("%d",it->second);
		}
	}
	
	
}
