#include<bits/stdc++.h>
using namespace std ;
const int M=1009;
char s[M];
int dy[M][M];
main()
{
	int n,i,j ;
	scanf("%d ",&n);
	gets(s+1);
	for(i=n;i>=1;i--)
	{
		dy[i][i]=1;
		for(j=i+1;j<=n;j++)
		{
			dy[i][j]=max(dy[i+1][j],dy[i][j-1]);
			if(s[i]==s[j])
			{
				dy[i][j]=max(dy[i][j],dy[i+1][j-1]+2);
			}
		}
	}
	printf("%d",dy[1][n]);
}
