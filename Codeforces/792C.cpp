#include<bits/stdc++.h>
using namespace std;
string s;
int a[100009][3];
int y[100009][3];
main()
{
	int i,j,k,d,t ; bool b=0;
	cin >> s;
	for(i=0;i<s.size();i++)if(s[i]=='0')b++;
	for(i=0;i<100003;i++)for(j=0;j<=2;j++)a[i][j]=1e8;
	a[0][0]=1; a[0][(s[0]-'0')%3]=0;
	for(i=1;i<s.size();i++)
	{
		if(s[i]=='0'&&a[i-1][0]==i)a[i][0]=i+1;
		else
		{
			a[i][0]=a[i-1][0]+1;
			a[i][(s[i]-'0')%3]=a[i-1][0];
			//y[i][s[i]-'0']=0;
		}
		for(j=1;j<=2;j++)
		{
			if(a[i-1][j]!=1e8)
			{
				if(a[i-1][j]+1<=a[i][j])
				{
					a[i][j]=a[i-1][j]+1;
					y[i][j]=j;			
				}
				if(a[i-1][j]<=a[i][(s[i]-'0'+j*10)%3])
				{
					a[i][(s[i]-'0'+j*10)%3]=a[i-1][j];
					y[i][(s[i]-'0'+j*10)%3]=j;	
				}
			}
		}
	}
	if(a[s.size()-1][0]==s.size())
	{
		if(b)printf("0");
		else printf("-1");
		return 0;
	}
	j=0;
	for(i=s.size()-1;i>=0;i--)
	{
		if(a[i][j]!=a[i-1][y[i][j]])
		{	
			if(a[i-1][y[i][j]]==1e8)break;
			s[i]='a';	
		}
		j=y[i][j];
	}
	for(i=0;i<s.size();i++)
	{
		if(s[i]!='a')printf("%c",s[i]);
	}
	
	
}
