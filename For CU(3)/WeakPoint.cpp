#include<bits/stdc++.h>
using namespace std ;
vector<vector<int> > v(500009);
int s[500000]={0},j[500000]={0},d[500000]={0},n,max1=0,max2=99999;
int Call(int i,int q)
{
	int x=0,k=99 ;
	vector<int>::iterator it ;
	if(j[i]==1&&i!=n)
	{
		s[i]=99;
		return 1 ;
	}
	else
	{
		s[i]=99;
		for(it=v[i].begin();it!=v[i].end();it++)
		{
			if(s[*it]==0)
			{
			    x=Call(*it,i);
			    if(x==0&&d[i]==0)
			    {
			    	//printf("1 %d %d ",i,*it);
			    	d[i]=-1;
			    	//printf("%d\n",d[i]);
				}
				else if(x==0&&d[i]>0)
				{
					//printf("2 %d %d ",i,*it);
					d[i]*=-1;
					d[i]--;
				//	printf("%d\n",d[i]);
				}
				else if(x!=0&&d[i]<0)
				{
					//printf("3 %d %d ",i,*it);
					d[i]-=x;
					//printf("%d\n",d[i]);
				}
				else if(x!=0&&d[i]>=0)
				{
					//printf("4 %d %d ",i,*it);
					d[i]+=x;
					//printf("%d\n",d[i]);
				}
			}
			else if(*it==n&&*it!=q)
			{
				d[i]=-1;
			}
		}
	}
	if(d[i]<0)
	{
		if(d[i]*-1-1>max1&&i!=n)
		{
			max1=d[i]*-1-1;
			max2=i;
		}
		else if(d[i]*-1-1==max1&&i<max2&&i!=n)
		{
			max2=i;
		}
		return 0 ;
	}
	else if(d[i]>0)
	{
		if(d[i]>max1&&i!=n)
		{
			max1=d[i];
			max2=i;
		}
		else if(d[i]==max1&&i<max2&&i!=n)
		{
			max2=i;
		}
		return d[i]+1;
	}
}
main()
{
	int m,i,x,y  ;
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
		j[x]++; 
		j[y]++;
	}
	if(j[n]==1)
	{
		printf("%d\n%d",*v[n].begin(),m-2);
	}
	else 
	{
		Call(n,n);
	printf("%d\n%d",max2,max1);
	}
	
	
}

