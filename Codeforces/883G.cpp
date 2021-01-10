#include<bits/stdc++.h>
using namespace std;
int s[300009][3];
int ch[300009];
char q[300009];
vector<int> v[300009];
int n,m,k,count1=1,count2=1;
int dfs1(int i)
{
	int y=k;
	vector<int>::iterator it;
	for(it=v[i].begin();it!=v[i].end();it++)
	{
		if(s[*it][0]==1&&ch[s[*it][2]]!=1)
		{
			ch[s[*it][2]]=1;
			count1++;
			dfs1(s[*it][2]);
		}
		else if(s[*it][0]==2)
		{
			if(s[*it][1]==i&&ch[s[*it][2]]!=1)y=s[*it][2],q[*it]='+';	
			else if(ch[s[*it][1]]!=1&&s[*it][2]==i)y=s[*it][1],q[*it]='-';
				if(ch[y]!=1)
				{	
					ch[y]=1;
					count1++;
					dfs1(y);
				}
		}
	}
}
dfs2(int i)
{
	int y=k;
	vector<int>::iterator it;
	for(it=v[i].begin();it!=v[i].end();it++)
	{
		if(s[*it][0]==1&&ch[s[*it][2]]!=2)
		{
			ch[s[*it][2]]=2;
			count2++;
			dfs2(s[*it][2]);
		}
		else if(s[*it][0]==2)
		{
			if(s[*it][1]==i)
			{
				q[*it]='-';
			}
			else if(s[*it][2]==i)
			{
				q[*it]='+';
			}
		}
	}
}
main()
{
	int i,j,x,y,t;
	scanf("%d %d %d",&n,&m,&k);
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&s[i][0],&s[i][1],&s[i][2]);		
		if(s[i][0]==1)
		{
			v[s[i][1]].push_back(i);
		}
		else v[s[i][1]].push_back(i),v[s[i][2]].push_back(i);
	}
	ch[k]=1;
	dfs1(k);
	printf("%d\n",count1);
	for(i=0;i<m;i++)
	{
		if(s[i][0]==2)
		{
			if(q[i]=='+'||q[i]=='-')
			printf("%c",q[i]);
			else printf("-");
		}
	}
	ch[k]=2;
	dfs2(k);
	printf("\n%d\n",count2);
	for(i=0;i<m;i++)
	{
		if(s[i][0]==2)
		{
			if(q[i]=='+'||q[i]=='-')printf("%c",q[i]);
			else printf("-");
		}
	}
}
