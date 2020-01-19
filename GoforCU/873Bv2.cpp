#include<bits/stdc++.h>
using namespace std;
int q[200009]={0};
//-100,000 to 100,000 ;
main()
{
	int a,i;
	int count=0;
	int max1=0;
	char o;
	scanf("%d",&a);
	for(i=1;i<=a;i++)
	{
		scanf(" %c",&o);
		if(o=='0')count--;
		else count++;
		if(count==0)max1=max(max1,i);
		else if(q[count+100000]==0)
		{
			q[count+100000]=i;
		}
		else 
		{
			max1=max(max1,i-q[count+100000]);			
		}
	}
	printf("%d",max1);
}
