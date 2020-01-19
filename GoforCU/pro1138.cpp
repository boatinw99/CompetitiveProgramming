#include<bits/stdc++.h>
using namespace std ;
int st[500009];
vector<int>v;
vector<int>::iterator it,it1;
queue<pair<int,int> > q;
int find(int l,int r,int x,int y,int m)
{
	int mid=(l+r)/2;
	if(l>=x&&r<=y)
	{
		return st[m];
	}
	if(r<x||l>y)
	{
		return INT_MIN;
	}
	return max(find(l,mid,x,y,2*m+1),find(mid+1,r,x,y,2*m+2));
}
void update(int l,int r,int x,int co ,int m)
{
	int mid=(l+r)/2;
	if(r<x||l>x)return ;
	if(l==r)
	{
		st[m]=co;
		return ;
	}
	update(l,mid,x,co,2*m+1);
	update(mid+1,r,x,co,2*m+2);
	st[m]=max(st[m*2+1],st[m*2+2]);
}
main()
{
	int n,k,s,i,x,y,l,r ;
	scanf("%d %d %d",&n,&k,&s);
	for(i=0;i<400000;i++)st[i]=-1;
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		q.push({x,y});
		v.push_back(x);
	}
	v.push_back(s);
	sort(v.begin(),v.end());
	it=lower_bound(v.begin(),v.end(),s);
	update(0,n,it-v.begin(),0,0);
	int pr,max1=0;
	while(!q.empty())
	{
		x=q.front().first;
		y=q.front().second;
		it=lower_bound(v.begin(),v.end(),x-k);
		l=it-v.begin();
		it1=upper_bound(v.begin(),v.end(),x+k);
		it1--;
		r=it1-v.begin();
		pr=find(0,n,l,r,0);
		it=lower_bound(v.begin(),v.end(),x);
		if(pr!=-1)
		{
			update(0,n,it-v.begin(),y+pr,0);
			max1=max(max1,y+pr);
		}
		q.pop();
	}
	printf("%d",max1);
}
