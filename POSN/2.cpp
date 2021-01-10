#include<bits/stdc++.h>
using namespace std;
int max1,k=0,q=-1 ;
vector<set<int> > v(200000) ;
int Call(int i,int count)
{
	set<int>::iterator it;
	//if(q!=-1)return 0;
	if(i==0)
	{
		for(it=v[0].end();it!=v[0].begin();)
		{
			it--;
			if((*it)+count<=max1&&(*it)+count>q)
			{
				q=count+(*it);
				return 0;	
			}
		}
	}
	else 
	{
	for(it=v[i].end();it!=v[i].begin();)
	{
		it--;
		Call(i-1,(*it)+count);
		//if(q!=-1)return 0;
	}	
	}
}
main()
{
	
	int a,i,m,j,input,check,x ;
	scanf("%d %d",&a,&max1);
	set<int>::iterator it;
	for(i=0;i<a;i++)
	{
		scanf(" %d",&m);
		while(m--)
		{
			scanf(" %d",&input);
			v[i].insert(input);
		}
	}
		for(it=v[a-1].end();it!=v[a-1].begin();)
		{
			it--;
			Call(a-2,*it);
		}
		printf("%d",q);
}
