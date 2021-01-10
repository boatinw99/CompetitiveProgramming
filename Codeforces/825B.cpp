#include<bits/stdc++.h>
using namespace std;
main()
{
	int i,j,e,p ;
	bool k,q ;
	char s[10][10];
	string d ;
	for(i=0;i<10;i++)
	{
		cin >> d ;
		for(j=0;j<10;j++)
		s[i][j]=d[j];
	}
	//
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(s[i][j]!='O')
			{	
				k=0;
				p=0;
				for(e=0;e<=4;e++)
				{
					if(s[i][j+e]=='O')
					{
						k=1;
						break ;
					}
					else if(j+e>9)
					{
						k=1;
						break;
					}
					else if(s[i][j+e]=='X')
					{
						p++;
					}
				}
				if(p!=4)k=1;
				if(!k)
				{
					printf("YES");
					return 0;
				}
				//1
				k=0;
				p=0;
				for(e=0;e<=4;e++)
				{
					if(s[i+e][j]=='O')
					{
						k=1;
						break ;
					}
					else if(i+e>9)
					{
						k=1;
						break;
					}
					else if(s[i+e][j]=='X')
					{
						p++;
					}
				}
				if(p!=4)k=1;
				if(!k)
				{
					printf("YES");
					return 0;
				}
				//2
				k=0;
				p=0;
				for(e=0;e<=4;e++)
				{
					if(s[i+e][j+e]=='O')
					{
						k=1;
						break ;
					}
					else if(j+e>9||i+e>9)
					{
						k=1;
						break;
					}
					else if(s[i+e][j+e]=='X')
					{
						p++;
					}
				}
				if(p!=4)k=1;
				if(!k)
				{
					printf("YES");
					return 0;
				}
				//3
				k=0;
				p=0;
				for(e=0;e<=4;e++)
				{
					if(s[i+e][j-e]=='O')
					{
						k=1;
						break ;
					}
					else if(j-e<0||i+e>9)
					{
						k=1;
						break;
					}
					else if(s[i+e][j-e]=='X')
					{
						p++;
					}
				}
				if(p!=4)k=1;
				if(!k)
				{
					printf("YES");
					return 0;
				}
			}			
		}
	}
	printf("NO");
}
