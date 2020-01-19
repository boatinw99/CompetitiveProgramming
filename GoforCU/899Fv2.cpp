#include<bits/stdc++.h>
using namespace std;
int bi[500009],n,m;
int size;
set<int>v[500];
set<int>::iterator it ;
string s;
int update(int in,int co)
{
	while(in<=size)
	{
		bi[in]+=co,in+=in&-in;
	}
}
int find(int in)
{
	int q=0,j=size/2;
	for(;j>0;j/=2)
	{
		if(bi[q+j]<in)
			{
				in-=bi[q+j];
				q+=j;
			}	
	}
	return q+1 ;
}
main()
{
	int x,y,i,j;
	char ch;
	scanf("%d %d",&n,&m);
    	cin >> s;
		for(size=1;size<n;size*=2);   
    for(i=1;i<=n;i++)update(i,1);
    for(i=0;i<s.size();i++)
    {
    	v[s[i]].insert(i+1);
	}
	while(m--)
	{
		scanf(" %d %d %c",&x,&y,&ch);
		x=find(x);
		y=find(y);
		it=lower_bound(v[ch].begin(),v[ch].end(),x);
		if(!v[ch].empty())
		for(;*it<=y&&it!=v[ch].end();)
		{
			update(*it,-1);
			s[(*it)-1]='.';
			v[ch].erase(it++);
		}
	}
	for(i=0;i<s.size();i++)
		if(s[i]!='.')printf("%c",s[i]);
}
