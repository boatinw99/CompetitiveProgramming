#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > v;
vector<pair<int,int> > ::iterator it ;
pair<int,int> d;
main()
{
	v.push_back({1,2});
	v.push_back({2,4});
	v.push_back({2,3});
	v.push_back({3,1});	
	sort(v.begin(),v.end());
	int d=distance(v.begin(),lower_bound(v.begin(),v.end(),make_pair(1,3)));
	printf("%d",d);
}
