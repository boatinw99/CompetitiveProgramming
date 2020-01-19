#include<bits/stdc++.h>
using namespace std ;
main()
{
	set<int> s;set<int>::iterator i;
	s.insert(4);
	s.insert(s.begin(),3);
	i=s.begin();
	
	s.insert(++i,7);
	s.insert(9);
	i = s.begin();
	int a = 0;
	++++a++;
	printf("%d\n",a);
	printf("%d",*++++++s.begin());
}
