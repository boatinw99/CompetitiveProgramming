#include<bits/stdc++.h>
using namespace std;
vector<int>v[200009];
vector<int>::iterator it;
int s[200009];
bool b[100009];
bool pa[200009];
bool d[100009];
int R[100009][2];
queue<int> q; 
int Do(int i)
{
	int x,y=i ;
	while(!q.empty())q.pop();
	for(it=v[i].begin();it!=v[i].end();it++)b[*it]++; pa[i]++; pa[s[i]]++;
	for(it=v[s[i]].begin();it!=v[s[i]].end();it++)if(!b[*it])q.push(*it);
	while(!q.empty())
	{
		x=q.front(); q.pop(); 
		if(pa[R[x][0]]&&pa[R[x][1]])return 0;
		if(!pa[R[x][0]])i=R[x][0];
		else i=R[x][1]; 
		for(it=v[i].begin();it!=v[i].end();it++)b[*it]++; pa[i]++; pa[s[i]]++;
		for(it=v[s[i]].begin();it!=v[s[i]].end();it++)if(!b[*it])q.push(*it);
	}
	
}
main()
{
	int K=5,n,m,i,j,x,y ;
	bool k=0;
	while(K--)
	{
		k=0;
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&x,&y);
			R[i][0]=x; R[i][1]=y;	
			v[x].push_back(i);
			v[y].push_back(i);
		}
		for(i=1;i<=m/2;i++)scanf("%d %d",&x,&y),s[x]=y,s[y]=x;
		Do(R[1][0]);
		for(i=1;i<=n;i++)
		{
			if(!b[i])
			{
				k++; break;
			}
		}
		for(i=1;i<=n;i++)b[i]=0; for(i=1;i<=m;i++)pa[i]=0;
		if(k==0)printf("Y");
		else 
		{
			Do(R[1][1]); k=0;
			for(i=1;i<=n;i++)
			{
				if(!b[i])
				{
					k++; break;
				}
			}
			if(k==0)printf("Y");
			else printf("N");
			for(i=1;i<=n;i++)b[i]=0; for(i=1;i<=m;i++)pa[i]=0;
		}
	}
}
