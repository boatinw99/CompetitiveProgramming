#include<bits/stdc++.h>
using namespace std;
int a[200009],b[200009];
bool c[200009];
main()
{
	int n,i,j=1,count=0;
	scanf("%d",&n);
	//  3 2 2 3
	//  0 2 2 0
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[a[i]]++;
	}
	for(i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			for(j;j<=n;)
			{
				if(b[a[j]]>1&&i<a[j])
				{
					b[a[j]]--;
					a[j]=i;
					j++;
					count++;
					break;
				}
				else if(b[a[j]]>1&&c[a[j]]>0&&i>a[j])
				{
					b[a[j]]--;
					a[j]=i;
					j++;
					count++;
					break;
				}
				else 
				{
					c[a[j]]++;
					j++;
				}
			}
		}
	}
	printf("%d\n",count);
	for(i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
}
