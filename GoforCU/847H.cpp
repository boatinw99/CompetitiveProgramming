#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[100009];
bool e[100009];
priority_queue<pair<pair<ll,ll>,char> >pq;
main()
{
	ll a,i,j,x,y;
	scanf("%I64d",&a);
	for(i=0;i<a;i++)
	{
		scanf("%I64d",&s[i]);
		e[i]=0;
	}
	pq.push({{-s[0],0},'a'});
	pq.push({{-s[a-1],-a+1},'b'});
	char c;
	ll count=0;
	while(!pq.empty())
	{
		x=pq.top().first.first*-1;
		y=pq.top().first.second*-1;
		c=pq.top().second;
		pq.pop();
		e[y]=1;
		count+=x-s[y];
		s[y]=x;
	    if(c=='a'&&y<a-1&&e[y+1]==0)
	    {
	    	if(s[y+1]>=x+1)
	    	{
	    		pq.push({{-s[y+1],-y-1},'a'});
			}
			else if(s[y+1]<=x) 
			{
				pq.push({{-x-1,-y-1},'a'});
			}
		}
		else if(c=='b'&&y>0&&e[y-1]==0)
		{
			if(s[y-1]>=x+1)
	    	{
	    		pq.push({{-s[y-1],-y+1},'b'});
			}
			else if(s[y-1]<=x) 
			{
				pq.push({{-x-1,-y+1},'b'});
			}
		}
		//printf("%d %d %c\n",x,y,c);
	}
	printf("%I64d",count);
}
