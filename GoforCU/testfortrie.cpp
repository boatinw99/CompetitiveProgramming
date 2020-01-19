#include<bits/stdc++.h>
using namespace std ;
vector<string> s;
vector<string>::iterator it;
string v ;
main()
{
	int i,j ;char c,p,o,q,g;
	string d="";
	for(i=0;i<10000000;i++)
	{
		v+=('a'+(i%15));
	}
	for(c='a';c<='z';c++)
	{
		s.push_back(v+c);
	}
	d='a'+5;
	for(j=0;j<50;j++)
	{
		it=lower_bound(s.begin(),s.end(),v+d);
	}	
}
