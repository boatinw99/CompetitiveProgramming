#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
vector<pair<ll,pair<ll,ll> > > v;
vector<pair<ll,pair<ll,ll> > >::iterator it ;
ll s[5000];
ll x=500000000000000;
main()
{
	ll i,n,in,j,count,y,e,o,x1;
	scanf("%I64d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&in);
		s[i]=in;
	}
	for(i=0;i<n;i++)
	{
		count=s[i];
		if(s[i]==0)
		{
			for(j=i+1;j<n&&s[j]==0;j++);
			count=s[j];
			if(s[j]>0)
			{
				for(j=j+1;j<n&&s[j]>=0;j++)
				{
					count+=s[j];
				}
				j--;
				v.push_back({count,{i,j}});
				i=j;
				}
			else
			{
				for(j=j+1;j<n&&s[j]<=0;j++)
				{
					count+=s[j];
				}
				j--;
				v.push_back({count,{i,j}});
				i=j;	
			} 
		}
		else if(s[i]>0)
		{
			for(j=i+1;j<n&&s[j]>=0;j++)
			{
				count+=s[j];
			}
			j--;
			v.push_back({count,{i,j}});
			i=j;
		}
		else
		{
			for(j=i+1;j<n&&s[j]<=0;j++)
			{
				count+=s[j];
			}
			j--;
			v.push_back({count,{i,j}});
			i=j;	
		}
	}
	y=0;
	e=v.size();
	while(1)
	{
		x=500000000000000;
		if(v.begin()->first>=0&&v.size()<=4)
		{
			it=v.begin();
			it++;
			for(;it!=v.end();++it)
			{
				printf("%I64d ",it->second.first);
				y++;
			}
			if(s[n-1]>=0)
			{
				for(y;y<3;y++)printf("%I64d ",n);
			}
			else
			{
				for(i=n-1;s[i]<=0;i--);
				printf("%I64d",i+1);
			}
			break;
		}
		else if(v.begin()->first<0&&v.size()<=3)
		{
			it=v.begin();
			it++;
			printf("0 ");
			for(;it!=v.end();++it)
			{
				printf("%I64d ",it->second.first);
				y++;
			}
			for(y;y<2;y++)printf("%I64d ",n);
			break;
		}
		i=0;
		if(v[0].first+v[1].first<0&&v[0].first>0)
		{
			i=1;
		}
		for(i;i<e;i++)
		{
			if(v[i].first<0)
			{
				o=v[i].first*-1;
			}
			else o=v[i].first;
			if(o<x)
			{
				x=o;
				x1=i;
			}
		}
		//printf("%d %d\n",x,x1);
		if(x1==0)
		{
			v[0].first+=v[1].first;
			v[0].second.second=v[1].second.second;
			v.erase(v.begin()+1);
			e--;
			if(v[0].first==0)
			{
				v[0].first=v[1].first;
				v[0].second.second=v[1].second.second;
				v.erase(v.begin()+1);
				e--;
			}
		}
		else if(x1==e-1)
		{
			v[e-2].first+=v[e-1].first;
			//printf("%d %d\n",v[e-1].second.first,v[e-1].second.second);
			v[e-2].second.second=v[e-1].second.second;
			v.erase(v.end()-1);
			e--;
		}
		else
		{
			v[x1-1].first+=x+v[x1+1].first;
			v[x1-1].second.second=v[x1+1].second.second;	
			v.erase(v.begin()+x1);
			v.erase(v.begin()+x1);
			e-=2;
		}
	}
}
