#include<bits/stdc++.h>
using namespace std;
string s;
main()
{
	int i,j,l,r,x,y,pr=0,z;
	cin >> s ;
	for(i=0;i<s.size();i++)
	{
		l=0,x=0,y=0 ;
		for(j=i;j<s.size();j++)
		{
			if(s[j]=='(')
			{
				if(l>=y);
				else x+=(y-l),y=l;
				l++;
			}
			else if(s[j]==')')l--;
			else y++;
			if(l<0&&x>0)x--,l++;
			else if(l<0&&y>0)y--,l++;
				if(l<0)break;
			if(l<=y)
			{
				z=y-l;
				if(x>=z&&(x-z)%2==0)pr++;
				else if(z>=x&&(z-x)%2==0)pr++;
			}
		}
	}
	printf("%d",pr);
}
