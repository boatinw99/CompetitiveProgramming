#include<stdio.h>
#include<vector>
using namespace std ;
typedef long long ll;
vector<int> v[10][10009];
vector<int>::iterator it,it1;
int s[10][100009];
int pr[10];
int max1[10];
int p;
int Check(int i,int j)
{
	int e;
	bool k=0;
	for(e=0;e<p;e++)
	{
		if(s[e][i]+s[e][j]!=pr[e])
		{
			k++;
			break;
		}
	}
	return k;
}
main()
{
	int n,i,j,x,y ; bool k=0;
	ll maxt=1e16,r=0,co=0;
	scanf("%d %d",&n,&p);
	for(i=0;i<n;i++)
	{
		for(j=0;j<p;j++)
		
		{
			scanf("%d",&x);
			s[j][i]=x;
			v[j][x].push_back(i);
			max1[j]=max(max1[j],x);
		}
	}
	for(i=0;i<p;i++)scanf("%d",&pr[i]);
	for(i=0;i<n;i++)
	{
		k=0;
		for(j=0;j<p;j++)
		if(s[j][i]!=pr[j])
		{
			k++;
			break;
		}
		if(k==0)return 0*printf("%d",i+1);
	}
	for(i=0;i<p;i++)
	{
		co=0;
		for(j=1;j<pr[i]/2;j++)
		{
			if(pr[i]-j<=max1[i])
			co+=v[i][j].size()*v[i][pr[i]-j].size();
		}
		if(pr[i]%2==0)co+=v[i][pr[i]/2].size()*(v[i][pr[i]/2].size()-1)/2;
		else co+=v[i][pr[i]/2].size()*v[i][pr[i]/2+1].size();
		if(co<maxt)maxt=co,r=i;
	}
	for(j=1;j<pr[r]/2;j++)
	{
		if(pr[r]-j<=max1[r])
		{
			for(it=v[r][j].begin();it!=v[r][j].end();it++)
			{
				for(it1=v[r][pr[r]-j].begin();it1!=v[r][pr[r]-j].end();it1++)
				{
					y=Check(*it,*it1);	
					if(!y)
					{
						printf("%d %d",min(*it,*it1)+1,max(*it,*it1)+1);
						return 0;		
					}		
				}			
			}
			
		}
	}
	printf("NO");
	
}
