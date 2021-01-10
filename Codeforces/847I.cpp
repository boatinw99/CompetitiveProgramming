#include<bits/stdc++.h>
using namespace std;
int k[250][250];
char s[250][250];
int a[250][250];
queue<pair<pair<int,int>,int> >qu;
//town{x,y} value
main()
{
	int m,n,q,p,count=1,i1,j1,value,d=0;
	int i,j ;
	char r[250];
	scanf("%d %d %d %d ",&m,&n,&q,&p);
	for(i=0;i<m;i++)
	{
		gets(r);
		for(j=0;j<n;j++)
		{
			k[i][j]=0;
			a[i][j]=0;
			s[i][j]=r[j];
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(s[i][j]!='*'&&s[i][j]!='.')
			{
				qu.push({{i,j},(s[i][j]-64)*q});
				k[i][j]=count;
				while(!qu.empty())
				{
					i1=qu.front().first.first;
					j1=qu.front().first.second;
					value=qu.front().second;
					a[i1][j1]+=value;
					qu.pop();
					if(value/2>0)
					{
						//L R U D
						if(k[i1][j1-1]!=count&&j1>0&&s[i1][j1-1]!='*')
						{
							//printf("L");
							k[i1][j1-1]=count;
							qu.push({{i1,j1-1},value/2});
						}
						if(k[i1][j1+1]!=count&&j1<n-1&&s[i1][j1+1]!='*')
						{
							//printf("R");
							k[i1][j1+1]=count;
							qu.push({{i1,j1+1},value/2});
						}
						if(k[i1-1][j1]!=count&&i1>0&&s[i1-1][j1]!='*')
						{
							//printf("U");
							k[i1-1][j1]=count;
							qu.push({{i1-1,j1},value/2});
						}
						if(k[i1+1][j1]!=count&&i1<m-1&&s[i1+1][j1]!='*')
						{
							//printf("D");
							k[i1+1][j1]=count;
							qu.push({{i1+1,j1},value/2});
						}
					}
				}
			}
			count++;
		}
	}
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]>p)d++;
		}
	}
	printf("%d",d);
}
