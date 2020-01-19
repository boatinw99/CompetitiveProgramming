#include<bits/stdc++.h>
using namespace std;	
typedef long long ll;
vector<string> v;
vector<string>::iterator it;
ll check(string s)
{
	ll i,co=0,d=0;
	for(i=0;i<s.size();i++)
	if(s[i]=='s')d++; else co+=d;
	return co; 
}
bool b(string l,string r)
{
	return check(l+r)>check(r+l) ;
}
main()
{
	ll n,i ; 
	string s ;
	scanf("%I64d",&n);
	for(i=0;i<n;i++)
	{
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(),v.end(),b);
	string q;
	for(it=v.begin();it!=v.end();it++)
	{
		q+=*it;
	}	
	printf("%I64d",check(q));
}
