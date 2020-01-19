#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l=-1,r=1e18 ;
ll s[1000009];
main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	ll i,j,n,m,mid,co=0;
	cin >> m >> n ;
	for(i=0;i<m;i++)cin >> s[i] ; 
	while(l+1<r)
	{
		mid=(l+r)/2;
		co=0;
		for(j=0;j<m;j++)
		{
			co+=mid/s[j];
		}
		if(co>=n)r=mid;
		else l=mid;
	}
	cout << r ; 
}
