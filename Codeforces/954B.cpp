#include<bits/stdc++.h>
using namespace std;
main()
{
	int n,j,i,d,co=0,max1=1;
	string s,q  ;
	scanf("%d",&n);
	cin >> s;
	int e;
	for(i=0;i<n;i++)
	{
		q="";
		for(j=i;j<n;j++)
		{
			q+=s[j];
			co=0;
			e=q.size();
			for(d=0;d<=n-q.size();)
			{
				if(q==s.substr(d,q.size()))
				co++,d+=q.size();
				else d++;
				if(co==2)
				{
					max1=max(max1,e);
				 	break;
				}
			}
		}
	}
	printf("%d",n-max1+1);
}
