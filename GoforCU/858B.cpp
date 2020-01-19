#include<bits/stdc++.h>
using namespace std; 
vector<int> v;
vector<int>::iterator it;
main()
{
	int a,b,i,x,y,q,e;
	scanf("%d %d",&a,&b);
	if(b==0)
	{
		if(a==1)printf("1");
		else printf("-1");
		return 0 ;
	}
	scanf("%d %d",&x,&y);
	if(y==1)
	{
		for(i=x;i<=109;i++)
		{
			v.push_back(i);
		}
	}
	else if(y>1)
	{
		q=x/y;
		if(x%y!=0)q++;
		e=(x-1)/(y-1);
		for(i=q;i<=e;i++)
		{
			v.push_back(i);
		}
	}
	for(i=1;i<b;i++)
	{
		scanf("%d %d",&x,&y);
		if(y==1)
		{
			q=x; //q=5;
			for(it=v.begin();it!=v.end()&&*it<q;)
			{
				v.erase(it);
			}
		}
		else
		{
			q=x/y;
			if(x%y!=0)q++;
			e=(x-1)/(y-1);
			for(it=v.begin();it!=v.end();it++)
			{
				if(q<=*it&&*it<=e);
				else 
				{
					v.erase(it);
					it--;
				}
			}
		}
	}
	int pr,pr1;
		//floor = 3 
		pr=a/v[0];
		if(a%v[0]!=0)pr++;
	if(v.size()>1)
	{
		it=v.begin();
		it++;
		for(it;it!=v.end();it++)
		{
			pr1=a/(*it);
			if(a%(*it)!=0)pr1++;
			if(pr1!=pr)
			{
				printf("-1");
				return 0;
			}
		}	
	}
	printf("%d",pr);
}
