#include<bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int>::iterator it;
int s[109];
main()
{
	int a,i,x,b;
	scanf("%d",&a);
	a=a*2;
	for(i=0;i<a;i++)
	{
		scanf("%d",&s[i]);
	}
	sort(&s[0],&s[a]);
	for(i=1;i<a;i++)
	{
		v.push_back(s[i]-s[i-1]);
	}
	int count = 0,check=INT_MAX,k=0 ;
	cout << endl ;
	for(it=v.begin();it!=v.end();it++)
	{
		printf("%d ",*it);
	}
	while(v.size()!=1)
	{
		k=0;
		check=INT_MAX;
		for(it=v.begin();it!=v.end();it++)
		{
			if(*it<check)
			{
				check=*it;
				x=k;
			}
			k++;
		}
		if(*(v.end()-1)<=check)
		{
			printf("a");
			count+=*(v.end()-1);
			v.erase(v.end()-1);
			v.erase(v.end()-1);
		}
		else if(x==0)
		{
			printf("b");
			count+=v[x];
			v.erase(v.begin());
			v.erase(v.begin());
		}
		else 
		{
			count+=v[x];
			v[x-1]+=v[x]+v[x+1];
			v.erase(v.begin()+x);
			v.erase(v.begin()+x);	
		}
		//printf("%d\n",count);
	}
	//printf("%d",count);
}
