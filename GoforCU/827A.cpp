#include<bits/stdc++.h>
using namespace std ;
pair<pair<int,int>,string> v[1000001];
char Y[2000001];	
string s;
main()
{
	int i,a,b,j,k=0,input,size,N,M,O,max1=0 ;
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
		cin >> s ;
		size=s.size();
		scanf(" %d",&b);
		for(j=0;j<b;j++)
		{
			scanf(" %d",&input);
			input--;
			if(input+size-1>max1)max1=input+size-1;
			v[k]={{input,input+size-1},s};
			k++;
			v[k]={{input+size-1,input},s};
			k++;
		}
	}
	sort(&v[0],&v[k]);
	for(i=0;i<=max1;i++)
	{
		Y[i]='a';
		M=k;
		N=-1;
		while(N+1<M)
		{
			O=(N+M)/2 ;
			if(i<v[O].first.first&&i<v[O].first.second)
			{
				M=O;
			}
			else if(i>v[O].first.first&&i>v[O].first.second)
			{
				N=O;
			}
			else if(i>=v[O].first.first&&i<=v[O].first.second)
			{
				Y[i]=v[O].second[i-v[O].first.first];
				break;
			}
			else if(i<=v[O].first.first&&i>=v[O].first.second)
			{
				Y[i]=v[O].second[i-v[O].first.second];
				break;
			}
		}	
		printf("%c",Y[i]);
	}


}
