#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,size ;
string s;
ll dy[62];
main()
{
	ll i,j,x,k ;
	scanf("%I64d %I64d",&n,&q);
	for(i=0;i<=60;i++)dy[i]=pow(2,i);
	for(i=0;pow(2,i)<=n+1;i++)
		dy[i]=pow(2,i);size=i-1;
	while(q--)
	{
		scanf("%I64d",&x);
		for(j=0;j<size&&x%dy[j]==0;j++);k=j-1;
		cin >> s;
		for(i=0;i<s.size();i++)
		{
			if(s[i]=='L'&&x%2==0)
			{
				x-=dy[k-1];
				k--;
			}
			else if(s[i]=='R'&&x%2==0)
			{
				x+=dy[k-1];
				k--;
			}
			else if(s[i]=='U'&&k!=size-1)
			{
				if((x+dy[k])%dy[k+2]==0)x-=dy[k];
				else x+=dy[k];
				k++;
			}
		}
		printf("%I64d\n",x);
	}
}
