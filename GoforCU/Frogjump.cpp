#include<bits/stdc++.h>
using namespace std;
int m,n ;
int A[259][259][2];
int B[259][259];
queue<pair<pair<int,int>,int> > q;
main()
{
	int i,j,d ;
	scanf("%d %d",&m,&n);
	for(d=0;d<=1;d++)
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&A[i][j][d]);
			B[i][j]=INT_MAX;
		}
	}
	q.push({{0,0},0});
	int x,y,count;
	while(!q.empty())
	{
		x=q.front().first.first;
		y=q.front().first.second;
		count=q.front().second;
		for(i=x;i<)
		q.pop();
	}
	
}
