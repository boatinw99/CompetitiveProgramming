#include<bits/stdc++.h>
using namespace std;
int n,m,size;
string q;
int bi[270000];
set<int> s[300];
set<int>::iterator it;
update(int in,int co)
{
	for(;in<=size;in+=in&-in)bi[in]+=co;
}
int find(int in)
{
	int w=0,j=size/2;
	for(;j>0;j/=2)
	{
		if(bi[w+j]<in)in-=bi[w+j],w+=j;
	}
	return w+1;
}
main()
{
	int i,x,y ;
	char ch;
	scanf("%d %d",&n,&m);
	cin >> q;
	for(i=0;i<n;i++)s[q[i]].insert(i+1);
	for(size=1;size<n;size*=2); 
	for(i=1;i<=n;i++)update(i,1);
	while(m--)
	{
		scanf(" %d %d %c",&x,&y,&ch);
		x=find(x);y=find(y);
		it=lower_bound(s[ch].begin(),s[ch].end(),x);
		for(;*it<=y&&it!=s[ch].end();)
		{
			q[(*it)-1]='.';
			update(*it,-1);
			s[ch].erase(it++);
		}
	}
	for(i=0;i<q.size();i++)if(q[i]!='.')printf("%c",q[i]);
	
}
