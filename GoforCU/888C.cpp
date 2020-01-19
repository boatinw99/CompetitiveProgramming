#include<bits/stdc++.h>
using namespace std;
main()
{
	int i,max1=INT_MAX,ch,count;
	char j;
	string s;
	cin >> s;
	bool k=0;
	for(j='a';j<='z';j++)
	{
		k=0;
	//	printf("%c ",j);
		count=0;
		for(i=0,ch=-1;i<s.size();i++)
		{
			if(s[i]==j)
			{
				if(i-ch>count)
				{
					count=i-ch;
				}
				ch=i;
			}
		}
		if(ch!=s.size()-1)
		{
			if(s.size()-ch>count)
			{
				count=s.size()-ch;
			}
		}
		max1=min(max1,count);
		
	}
	printf("%d",max1);
}
