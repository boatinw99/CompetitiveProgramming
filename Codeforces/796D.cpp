#include<bits/stdc++.h>
using namespace std ;
vector<pair<int,int> > v[300001];
vector<pair<int,int> >::iterator it ;
vector<int> Q;
vector<int>::iterator itq;
set<int> S;
set<int>::iterator its;
int A[300001];
queue<pair<pair<int,int>,int > > q;
//source,count,town
main()
{
	int n,k,d,i,p,x,y,count,sor,town;
	scanf("%d %d %d",&n,&k,&d);
	if(n==k)
	{
		printf("%d\n",n-1);
		for(i=1;i<=n-1;i++)
		{
			//scanf(" %d %d",&x,&y);
			printf("%d ",i);
		}

	}
	else
	{
	for(i=0;i<=n;i++)A[i]=INT_MAX;
	for(i=0;i<k;i++)
	{
		scanf(" %d",&p);
		A[p]=0;
		Q.push_back(p);
	}
	for(i=1;i<n;i++)
	{
		scanf(" %d %d",&x,&y);
		v[x].push_back({y,i});
		v[y].push_back({x,i});
	}		
	for(itq=Q.begin();itq!=Q.end();++itq)
	{
		for(it=v[*itq].begin();it!=v[*itq].end();)
		{
			if(A[it->first]==INT_MAX)
			{
				A[it->first]=1;
				q.push({{*itq,1},it->first});
				it++;
			}
			else 
			{
				S.insert(it->second);
				v[*itq].erase(it);
			}
		}
	}
	while(!q.empty())
	{
		sor=q.front().first.first;
		count=q.front().first.second;
		town=q.front().second;
		q.pop();
		if(count<d) 
		{
		//	printf("%d %d %d\n",sor,count,town);
			for(it=v[town].begin();it!=v[town].end();)
			{
				if(it->first!=sor)
				{
					if(count+1<A[it->first])
					{
						A[it->first]=count+1;
						q.push({{town,count+1},it->first});
						it++;
					}
					else 
					{
						S.insert(it->second);
						v[town].erase(it);
					}
				}
				else it++;
			}	
		}
	}
	printf("%d\n",S.size());
	for(its=S.begin();its!=S.end();++its)
	{
		printf("%d ",*its);
	}
	}
}
