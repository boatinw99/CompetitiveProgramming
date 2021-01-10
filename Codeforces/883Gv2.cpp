#include<bits/stdc++.h>
using namespace std;
int s[300009][3];
int ch[300009];
char e[300009];
queue<int> q;
vector<int> v[300009];
vector<int>::iterator it;
main()
{
	int i,j,x,y,t,n,m,k,count1=1,count2=1;
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
	q.push(k);
	while(!q.empty())
	{
		i=q.front();
		q.pop();
		y=k;
		for(it=v[i].begin();it!=v[i].end();it++)
		{
			if(s[*it][0]==1&&ch[s[*it][2]]!=1)
			{
				ch[s[*it][2]]=1;
				count1++;
				q.push(s[*it][2]);
			}
			else if(s[*it][0]==2)
			{
				if(s[*it][1]==i&&ch[s[*it][2]]!=1)y=s[*it][2],e[*it]='+';	
				else if(ch[s[*it][1]]!=1&&s[*it][2]==i)y=s[*it][1],e[*it]='-';
					if(ch[y]!=1)
					{	
						ch[y]=1;
						count1++;
						q.push(y);
					}
			}
		}
	}
	printf("%d\n",count1);
	for(i=0;i<m;i++)
	{
		if(s[i][0]==2)
		{
			if(e[i]=='+'||e[i]=='-')
			printf("%c",e[i]);
			else printf("-");
		}
	}
	ch[k]=2;
	q.push(k);
	while(!q.empty())
	{
		i=q.front();
		q.pop();
		for(it=v[i].begin();it!=v[i].end();it++)
	{
		if(s[*it][0]==1&&ch[s[*it][2]]!=2)
		{
			ch[s[*it][2]]=2;
			count2++;
			q.push(s[*it][2]);
		}
		else if(s[*it][0]==2)
		{
			if(s[*it][1]==i)
			{
				e[*it]='-';
			}
			else if(s[*it][2]==i)
			{
				e[*it]='+';
			}
		}
	}
	}
	printf("\n%d\n",count2);
	for(i=0;i<m;i++)
	{
		if(s[i][0]==2)
		{
			if(e[i]=='+'||e[i]=='-')printf("%c",e[i]);
			else printf("-");
		}
	}
}
