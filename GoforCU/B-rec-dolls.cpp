#include<bits/stdc++.h>
using namespace std ;
pair<int,int> a[20009];
pair<int,int>*it;
multiset<int> s;
multiset<int> ::iterator its; 
stack<int> st;
main()
{
	int n,m,i,j,k,x,y ;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&x,&y);
			a[i]={x,y};
		}
		sort(a,a+n);
		for(i=0;i<n;i++)
		{
			x=a[i].second;
			if(s.empty())
			{
				st.push(x);
			}
			else 
			{
				its=s.lower_bound(x);
				if(its==s.begin())
				{
					st.push(x);
				}
				else
				{
					its--;
					s.erase(its);
					st.push(x);
				}		
			}
			if(a[i].first!=a[i+1].first||i==n-1)
				{
					while(!st.empty())
					{
						s.insert(st.top());
						st.pop();
					}
				}
		}
		printf("%d\n",s.size());
		s.clear();
	}
}
