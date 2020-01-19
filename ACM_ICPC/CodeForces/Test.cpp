#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
const int N = 1e9+7 ; 
map<int,int> mp ; 
//bool vst[N];
int main()
{
	ll mod = 1e9+7 ; 
	int cnt = 1 ;
	ll val = 1 ;
	while(1)
	{
		if(mp[val])break ;
		mp[val]++;
		cnt++;
		val=10*val%mod ;
	}
	cout << cnt ; 
}