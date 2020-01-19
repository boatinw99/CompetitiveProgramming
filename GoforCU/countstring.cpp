#include<bits/stdc++.h>
using namespace std ;
main()
{
	string s;
	cin >> s;
	int co=0;
	for(int i=0;i<s.length();i++)if(s[i]=='P')co++;
	cout << co;
}
