#include<bits/stdc++.h>
using namespace std ;
vector<int> s,u ;
main()
{
	int n,m,k,l,i,j,count,q,g,d,i1,j1,j2,i2,count1,temp ;
	scanf("%d %d %d %d",&n,&m,&k,&l);
	for(i=0;i<n;i++)
	{
		scanf(" %d",&g);
		s.push_back(g);
		u.push_back(-1);
	}
	for(i=0;i<k;i++)
	{
		count=0;
		d=0;
		scanf(" %d",&q);
		i1=-1; j1=-1;

		for(g=0;g<n;g++)
		{		
				if(q<s[g])
				{
					temp=q;
					q=s[g];
				}
				else 
					temp=s[g];
			if(q-s[g]<=l)
			{
				if(u[g]!=i)
				{
					count++;
					u[g]=i;
				}
				if(d==0)
				{
					i1=g+1;
					d=99;	
				}
			}
			else if(d==99)
			{
				j1=g;
				break;
			}
		}
		count1=count;
		printf("\n%d %d %d\n",i1,j1,count);
		for(j=1;j<m;j++)
		{  
			scanf(" %d",&q);
			count+=count1;
			if(i1>0)
			{
				printf("a %d %d \n",q,s[j1]);
				if(q-s[j1]>l||q-s[j1]<-l)
				{
					printf("a ");
					count-=count1;
					i1=j1;
					for(i2=i1;i2<n;i2++)
					{
						if(q-s[i2]<=l&&q-s[i2]>=-l)
						{
							break;
						}
					}
					i1=i2+1;
					j1=i1;
				}
				else if(q-s[j1]<=l&&q-s[j1]>=-l)
				{
					for(i2=i1-1;i2<j1;i2++,count--)
					{
						if(q-s[i2]<=l&&q-s[i2]>=-l)
						{
							break;
						}
					}
					i1=i2+1;
				}
				for(j2=j1;j2<n;j2++,count++)
				{
					if(q-s[j2]<=l&&q-s[j2]>=-l);
					else break;
				}
				j1=j2;
				count1=j1-i1+1;
			}
		}
		printf("%d\n",count);
	}
}
