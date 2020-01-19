#include<bits/stdc++.h>
using namespace std;
string s,q ;
main()
{
	int i=0;
	for(i=0;i<100000;i++)s+="1";
	s+="0";
	for(i=1;i<s.size();i++)q+=s[i];
	q+=s;
	//cout << q ;
	printf("\n%d",q.find(s)+1);
}
