#include<bits/stdc++.h>
using namespace std;
bool A[100009];
int k=0;
pair<int,int>B[100009];
vector<int> v[100009];
vector<int>::iterator it;
int search(int i,int d)
{
	int j=B[i].second;
	v[k].push_back(i);
	A[i]++;
	if(j==d)
	{
		k++;
		return 0;
	}
	else
	{
		search(j,d);
	}
}
main()
{
	int n,i ;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&B[i].first);
		B[i].second=i;
	}
	sort(B+1,B+n+1);
	for(i=1;i<=n;++i)
	{
		if(A[i]==0)
		{
			search(i,i);
		}
	}
	printf("%d\n",k);
	for(i=0;i<k;i++)
	{
		printf("%d ",v[i].size());
		for(it=v[i].begin();it!=v[i].end();++it)
		{
			printf("%d ",*it);
		}
		printf("\n");
	}
}
