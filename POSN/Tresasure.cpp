#include<bits/stdc++.h>
using namespace std ;
vector<pair<pair<int,int>,int> >v;
vector<pair<pair<int,int>,int> >::iterator it1;
map<int,pair<int,int> > p;
map<int,pair<int,int> >::iterator it,it2;
main()
{
	int m,n,a,b,c,i,j,k;
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		v.push_back({{b,c},a});
	}
	sort(v.begin(),v.end());
	it1=v.begin();
	p[it1->first.first]={it1->first.second,it1->second};
	for(i=1;i<m;i++)
	{
		a=v[i].first.first;
		b=v[i].first.second;
		c=v[i].second;
		it=p.begin();
		k=0;
		while(1)
		{
			it2=--p.end();
			if(p[a].first==b)
			{
				p[a].second*=c;
				break;
			}
			else if(a>(it2)->second.first)
			{
				if(k==0)
				{
					///fuck
				}
				p[a]={b,c};
				
				printf("\n%d %d -> %d\n\n",a,b,c,(it2)->second.first);
				break;
			}
			else 
			{
				if(a==it->first&&b>it->second.first)
				{
					p[a].second*=c;
					printf("%d %d -> %d\n",a,p[a].first,p[a].second);
					a=it->second.first+1;
					it++;	
				}	
				else if(a>it->first&&b>=it->second.first&&a<=it->second.first)
				{
					p[a]={it->second.first,it->second.second*c};
					printf("%d %d -> %d\n",a,p[a].first,p[a].second);
					if(b==it->second.first)
					{
					p.erase(it);
					break;	
					}
					a=it->second.first+1;					
					p.erase(it);
					
					it++;
				}
				else if(a>it->first&&b<=it->second.first)
				{
					p[a]={b,c*it->second.second};
					printf("%d %d -> %d\n",a,b,p[a].second);
					if(b<it->second.first)
					{
					p[b+1]={it->second.first,it->second.second};
					printf("%d %d -> %d\n",b+1,p[b+1].first,p[b+1].second);
					}
					
					p.erase(it);
					//it->second.first=a-1;
					//printf("%d %d -> %d\n",it->first,it->second.first,it->second.second);
					break;	
				} 
				else if(b<p[a].first)
				{
					p[b+1]={p[a].first,p[a].second};
					printf("%d %d -> %d\n",b+1,p[b+1].first,p[b+1].second);
					p[a].first=b;
					p[a].second*=c;
					printf("%d %d -> %d\n",a,p[a].first,p[a].second);;
					break;
				}
				else 
				{
					if(k==0)
					{
						
					}
					else it++;
				}
			}
			
		}
	}

}
