#include <bits/stdc++.h>

using namespace std;

struct node
{
	int day;
	int lop;
	bool pay;
	bool operator<(const node & rhs)const
	{
		if(day==rhs.day)
		{
			if(pay==rhs.pay)
			{
				return lop>rhs.lop;
			}return !(pay);

		}
		return day>rhs.day;
	}
};

priority_queue<node> q;

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		q.push({0,x,1});
	}
	int day=0;
	while(!q.empty())
	{
		node xx=q.top();
		q.pop();
		if(xx.day<=day)
		{
			if(!xx.pay)
			{
				if(m>0)
				{
					m--;
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			break;
		}
		q.push({xx.day+xx.lop+1,xx.lop,0});
		day++;
	}
	printf("%d",day);
	return 0;
}
