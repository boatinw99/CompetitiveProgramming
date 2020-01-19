#include<bits/stdc++.h>
using namespace std ;
set<string> s;
set<string>::iterator it;
char c[15];
main()
{
	int a,i,i1 ;
	string q ;
	scanf("%d",&a);
	for(i=0;i<a;i++)
	c[i]='0' ;
	s.insert(c);
	it=s.begin();
	for(i=a-1;i>=0;i--)
	{
		if((*it)[i]=='0')
		{
			q=*it;
			q[i]='1';
			s.insert(q);
			for(i1=0;i1<a;i1++)
			printf("%c",(*it)[i1]);
			printf(" ");
			for(i1=0;i1<a;i1++)
			printf("%c",(q)[i1]);
			printf("\n");
		}
	}
	for(it=++s.begin();it!=--s.end();it++)
	{
		for(i=a-1;i>=0;i--)
		{
			if((*it)[i]=='0')
			{
				q=*it;
				q[i]='1';
				s.insert(q);
				for(i1=0;i1<a;i1++)
			printf("%c",(*it)[i1]);
			printf(" ");
			for(i1=0;i1<a;i1++)
			printf("%c",(q)[i1]);
			printf("\n");
			}
		}
	}
}
