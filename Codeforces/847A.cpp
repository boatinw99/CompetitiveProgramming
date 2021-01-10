#include<bits/stdc++.h>
using namespace std ;
main()
{
	int a,i,s[100],x,y,n=0,j,d ;
	bool K=0;
	scanf("%d",&a);
	for(i=0;i<a;i++)s[i]=0;
	for(i=1;i<=a;i++)
	{
			K=0;
			scanf("%d %d",&x,&y);
			for(j=0;j<n;j++)
			{
				if(s[j]==i)
				{
					K=1;
					break;
				}
			}
			if(K==1)
			{
				if((s[j-1]!=x&&x!=0)||(j-1==0&&x!=0))
				{
					for(d=n;j<d;d--)
					{
						s[d]=s[d-1];
					}
					s[j]=x;
					n++;
				}
				else if((s[j+1]!=y&&y!=0)||(j+1==))
				{
					
				}
				printf("a %d %d\n",i,j);
			}
			else if(K==0)
			{
				if(x!=0)
				{
					s[n]=x;
					n++;
				}
				s[n]=i;
				n++;
				if(y!=0)
				{
					s[n]=y;
					n++;
				}
			}
		for(j=0;j<a;j++)
		{
			printf("%d ",s[j]);
		}
		printf("\n");
	}
}
