#include<bits/stdc++.h>
using namespace std;
main()
{
	int x,y,ex,ey;
	scanf("%d %d",&x,&y);
	scanf("%d %d",&ex,&ey);
	int ax,ay;
	ax=x-ex;
	ay=y-ey;
	if(ax<0)ax*=-1;
	if(ay<0)ay*=-1;
	int count=(ax+1)*2+(ay+1)*2;
	if(ax==0||ay==0)count+=2;
	printf("%d",count);
	
}
