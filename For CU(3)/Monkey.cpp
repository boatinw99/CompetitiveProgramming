#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int> > > v(200000);
vector<pair<int,int> >::iterator it,it1;
int max1=0;
main()
{
	int a,b,c,i,j,q,q1,x,e,g=0 ;
	scanf("%d %d %d",&a,&b,&c);
	int s[b];
	for(i=1;i<=b;i++)
	{
		scanf(" %d",&s[i]);
	}
	for(i=0;i<c;i++)
	{
		scanf(" %d %d",&q,&q1);
		v[q].push_back({q1,q+1});
		v[q+1].push_back({q1,q});
	}	
	scanf("%d",&x);
	e=0;
	for(i=1;i<=a;i++)
	{	
		sort(v[i].begin(),v[i].end());
	}
	while(1)
	{
		g=0;
		//printf("%d %d\n",x,e);
		for(it=v[x].begin();it!=v[x].end();it++)
		{
			if(it->first>e)
			{
				g=99;
				if(x>1)
				{
					for(it1=v[x-1].begin();it1!=v[x-1].end();it1++)
					{
						if(it1->first<it->first)
						{
							//Call(it1->first,it1->second);
						}
						else break;
					}
					//Call(it->first,x);
				}
				if(x<b)
				{
					for(it1=v[x+1].begin();it1!=v[x+1].end();it1++)
					{
						if(it1->first<it->first)
						{
							//Call(it1->first,it1->second);
						}
						else break;
					}
					//Call(it->first,x);
				}
				e=it->first;
				x=it->second;
				break;
			}
		}
		if(g==0)
		{
			if(s[x]>max1)
			{
				printf("%d\nNO",s[x]);
			}
			else printf("%d\nUSE",max1);
			break;
		}
	}
		
}
