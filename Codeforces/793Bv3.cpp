#include<bits/stdc++.h>
using namespace std ;
char A[1000][1000];
bool B[1000][1000][4];
int C[1000][1000];
//0 1 2 3 
//U D L R
queue<pair<pair<int,int>,pair<int,int> > > q;
main()
{
	int a,b,i,j,x,y,count,di ;
	string Q;
	scanf("%d %d",&a,&b);
	for(i=0;i<a;i++)
	{
		cin >> Q;
		for(j=0;j<b;j++)
		{
			A[i][j]=Q[j];
			B[i][j][0]=0;
			B[i][j][1]=0;
			B[i][j][2]=0;
			B[i][j][3]=0;
			C[i][j]=2;
			if(Q[j]=='S')
			{
				B[i][j][0]=1;
				B[i][j][1]=1;
				B[i][j][2]=1;
				B[i][j][3]=1;
				C[i][j]=-1;
				q.push({{-1,-1},{i,j}});
			}
		}
	}
	while(!q.empty())
	{
		x=q.front().second.first;
		y=q.front().second.second;
		count=q.front().first.second;
		di=q.front().first.first;
		q.pop();
		if(A[x][y]=='T')
		{
			printf("YES");
			return 0;
		}
		if(A[x-1][y]!='*'&&!B[x-1][y][0]&&x>0&&di!=1)
		{
			//printf("%d %d\n",x-1,y);
			B[x][y][di]=1;
			if(di==0&&count<=C[x-1][y])
			{
				C[x-1][y]=count;
				q.push({{0,count},{x-1,y}});	
			}	
			else if(di!=0&&count+1<=C[x-1][y])
			{
				C[x-1][y]=count+1;
				q.push({{0,count+1},{x-1,y}});
			}
		}
		if(A[x+1][y]!='*'&&!B[x+1][y][1]&&x<a-1&&di!=0)
		{
			B[x][y][di]=1;
			if(di==1&&count<=C[x+1][y])
			{
				//printf("%d %d %d\n",count,x+1,y);
				C[x+1][y]=count;
				q.push({{1,count},{x+1,y}});	
			}	
			else if(di!=1&&count+1<=C[x+1][y])
			{
				C[x+1][y]=count+1;
				//printf("%d %d %d\n",count+1,x+1,y);
				q.push({{1,count+1},{x+1,y}});
			}
		}
		if(A[x][y-1]!='*'&&!B[x][y-1][2]&&y>0&&di!=3)
		{
			//printf("%d %d\n",x,y-1);
			B[x][y][di]=1;
			if(di==2&&count<=C[x][y-1])
			{	
				C[x][y-1]=count;
				q.push({{2,count},{x,y-1}});	
			}	
			else if(di!=2&&count+1<=C[x][y-1])
			{
				C[x][y-1]=count+1;
				q.push({{2,count+1},{x,y-1}});
			}
		}
		if(A[x][y+1]!='*'&&!B[x][y+1][3]&&y<b-1&&di!=2)
		{
			B[x][y][di]=1;
			if(di==3&&count<=C[x][y+1])
			{
				C[x][y+1]=count;
				//printf("%d %d %d %d\n",count,di,x,y+1);
				q.push({{3,count},{x,y+1}});	
			}	
			else if(di!=2&&count+1<=C[x][y+1])
			{
				C[x][y+1]=count+1;
				//printf("%d %d %d %d\n",count,di,x,y+1);
				q.push({{3,count+1},{x,y+1}});
			}
		}
	}
	printf("NO");
}
