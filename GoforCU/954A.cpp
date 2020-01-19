#include<bits/stdc++.h>
using namespace std;
main()
{
	int i,n,co=0;
	string s;
	scanf("%d",&n);
	cin >> s;
	for(i=0;i<n-1;)
	{
		if(s[i]!=s[i+1])co++,i+=2;
		else i++;
	}
	printf("%d",n-co);
}
