#include<bits/stdc++.h>
using namespace std ;
int s[100001] ;
bool b[100001];
vector<long long> v[100001];
vector<long long>::iterator it ;
main()
{
	long long a,i,Ans=0,sum=0,ch ;
	bool Q=0,k;
	scanf("%I64d",&a);
	int Ro=a ;
	for(i=0;i<a;i++)
	{
		scanf(" %I64d",&s[i]);
		b[s[i]]=1;
		v[s[i]].push_back(i);
	}
	for(i=1;i<100001;++i)
	{
		if(b[i])
		{
			for(it=v[i].begin();it<v[i].end();++it)
			{
				if(Q==0)
				{
					sum=0;
					ch=*it;
					Q=1;
					sum++;
				}
				else if(ch<*it)
				{
					ch=*it;
					sum++;
				}
				else if(ch>*it)
				{
					Q=0;
					for(it;it!=v[i].end();++it)
					{
						if(ch<*it)
						{
							sum++;
							Q=1;
							v[i].erase(it);
							it--;
						}
					}
					if(Q==1)
					{
						Q=0;
						
					}
					k=99;
					Ans+=Ro;
					Ro-=sum;
				}
			}
			if(k==1)
			{
				k=0;
				i--;
			}
		}
	}
	printf("%I64d",Ans+Ro);
}
