#include<bits/stdc++.h>
using namespace std;
set<pair<int,pair<int,int> > > pq;
set<pair<int,pair<int,int> > >::iterator it;
main()
{
	int m,n,i,j,x,y,z,g=0;
	int a[105][105];
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++)
	{
		if(i%2==0)
		{
			a[i][0]=-1;
			for(j=0;j<n;j++)
			{
				scanf(" %d",&a[i][j+1]);	
			}	
		}
		else 
		{
			a[i][n]=-1;
			for(j=0;j<n;j++)
			{
				scanf(" %d",&a[i][j]);
			}
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<=n;j++)
		{
			printf("%2d ",a[i][j]);
		}
		printf("\n");
	}
	pq.insert({0,{(m-1)/2,0}});
	it=pq.begin();
	pq.insert({0,{(m-1)/2,0}});
	for(it;it!=pq.end();it++)
	{
		printf("%d %d %d",it->first,it->second.first,it->second.second);
		
	}
	/*while(1)
	{
		z=it->first;
		x=it->second.first;
		y=it->second.second;
		printf("%d %d %d\n",z,x,y);
		if(x==(m-1)/2&&y==n)
		{
			printf("%d",z);
			break;
		}
		pq.erase(pq.begin());
		if(y>0&&a[x][y-1]>0&&(z+1)%a[x][y-1]==0)
		{
			printf("555");
			pq.insert({z+1,{x,y-1}});
		}
		if(y<n&&a[x][y+1]>0&&(z+1)%a[x][y+1]==0)
		{
			printf("666");
			pq.insert({z+1,{x,y+1}});
		}
		if(x>0&&a[x-1][y]>0&&(z+1)%a[x-1][y]==0)
		{
			pq.insert({z+1,{x-1,y}});
		}
		if(x<n&&a[x+1][y]>0&&(z+1)%a[x+1][y]==0)
		{
			pq.insert({z+1,{x+1,y}});
		}
		//
		/*if(x%2==0)
		{
			if(x>0&&y>0&&a[x-1][y-1]>0&&(z+1)%a[x-1][y-1]==0)
			{
				pq.insert({z+1,{x-1,y-1}});
			}
			if(x<n&&y>0&&a[x+1][y-1]>0&&(z+1)%a[x+1][y-1]==0)
			{
				pq.insert({z+1,{x+1,y-1}});
			}
		}
		else
		{
			if(x>0&&y<n&&a[x-1][y+1]>0&&(z+1)%a[x-1][y+1]==0)
			{
				pq.insert({z+1,{x-1,y+1}});
			}
			if(x<n&&y<n&&a[x+1][y+1]>0&&(z+1)%a[x+1][y+1]==0)
			{
				pq.insert({z+1,{x+1,y+1}});
			}
		}*/
	//}
}
