#include<bits/stdc++.h>
using namespace std ;
int dp[309][309][3];
char s[309];
int se[3][3]={{2,1,0},{2,1,1},{1,2,1}};
void Check(int i,int j,int b)
{
	int x,y,d1 ;
	for(d1=i;d1<j;d1++) //0
	{
		if(dp[i][d1][0]==b&&dp[d1+1][j][2]==b)
		{
			dp[i][j][0]=b;
			break;
		}
	} 
	for(d1=i;d1<j;d1++) //1
	{
		if((dp[i][d1][0]==b&&dp[d1+1][j][1]==b)||(dp[i][d1][1]==b&&dp[d1+1][j][1]==b)||(dp[i][d1][1]==b&&dp[d1+1][j][2]==b)||(dp[i][d1][2]==b&&dp[d1+1][j][0]==b)||(dp[i][d1][2]==b&&dp[d1+1][j][2]==b))     
		{
			dp[i][j][1]=b;
			break;
		}
	}
	for(d1=i;d1<j;d1++) //2
	{
		if((dp[i][d1][0]==b&&dp[d1+1][j][0]==b)||(dp[i][d1][1]==b&&dp[d1+1][j][0]==b)||(dp[i][d1][2]==b&&dp[d1+1][j][1]==b))
		{
			dp[i][j][2]=b;
			break;
		}
	}
	
}
main()
{
	int m=20,n,i,j,x ;
	for(x=1;x<=20;x++)
	{
		scanf("%d ",&n);
		gets(s+1);
		if(s[1]!='0')
		{
			printf("no\n");
		}
		else
		{
			for(i=1;i<=n;i++)
		{
			dp[i][i][0]=(s[i]=='0')*x;
			dp[i][i][1]=(s[i]=='1')*x;
			dp[i][i][2]=(s[i]=='2')*x;
		}
		for(i=n-1;i>0;i--)
		{
			for(j=i+1;j<=n;j++)
			{
				Check(i,j,x);
			}	
		}	
		if(dp[1][n][0]==x)
		{
			printf("yes\n");
		}
		else printf("no\n");
		}
	}
}
