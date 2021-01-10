#include<bits/stdc++.h>
using namespace std;
int bi[240009],n,m;
vector<int>v[400];
vector<int>::iterator it ;
string s;
int update(int in)
{
	while(in<=n)
	{
		bi[in]++;
		in+=in&-in;
	}
}
int sum(int in)
{
	int co=0;
	while(in>0)
	{
		co+=bi[in];
		in-=in&-in;
	}
	return co;
}
main()
{
	int x,y,i,j;
	char ch;
	scanf("%d %d",&n,&m);
    	cin >> s;
    for(i=0;i<s.size();i++)
    {
    	v[s[i]].push_back(i+1);
	}
	int dx,dy,dx1,dy1;
    while(m--)
    {
    	scanf(" %d %d %c",&x,&y,&ch);
    	dx=sum(x),dy=sum(y);x+=dx,y+=dy;
		while(dx1=sum(x),dx!=dx1)
    	{
    		//if(x+dx1-dx>n)break;
    		x+=dx1-dx;
			dx=dx1;
		}
		while(dy1=sum(y),dy!=dy1&&y<=n)
		{
			//if(y+dy1-dy>n)break;
			y+=dy1-dy,dy=dy1;	
		}
		it=lower_bound(v[ch].begin(),v[ch].end(),x);
		if(!v[ch].empty())
		for(it;*it<=y&&it!=v[ch].end();)
		{
			update(*it);
			s[(*it)-1]='.';
			v[ch].erase(it);
		}
	}
	for(i=0;i<s.size();i++)
	{
		if(s[i]!='.')printf("%c",s[i]);
	}
}
