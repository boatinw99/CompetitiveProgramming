#include<stdio.h>
main()
{
	int s[101][2],i,a,x,y,d,q;
	int e[101],j;
	scanf("%d",&a);
	for(i=1;i<=a;i++)
	{
		scanf("%d %d",&x,&y);
		s[i][0]=x;
		s[i][1]=y;
		e[i]=0;
	}
	int m0,m1;
	for(i=1;i<=a;i++)
	{
		if(e[i]==0)
		{	
			m0=i,m1=i;
			e[i]=i;
		while(s[m0][0]!=0||s[m1][1]!=0)
		{
			e[m0]=i;
			e[m1]=i;
			if(s[m0][0]!=0)
			{
				m0=s[m0][0];
			}
			if(s[m1][1]!=0)
			{
				m1=s[m1][1];
			}	
		}
		e[m0]=i;
		e[m1]=i;	
		}	
	}
	for(i=1;i<=a;i++)
	{
		if(s[i][0]!=0&&s[i][1]!=0)
		{
		//	printf("%d %d\n",s[i][0],s[i][1]);
		}
		if(s[i][1]==0)
		{
			for(j=1;j<=a;j++)
			{
				if(s[j][0]==0&&e[j]!=e[i])
				{
					s[j][0]=i;
					s[i][1]=j;
					if(s[j][1]==0)
					{
						e[j]=e[i];
					}
					else
					{
						q=e[j];
					for(d=1;d<=a;d++)
					{
						if(e[d]==q)
						{
							e[d]=e[i];
						}
					}
					}
					
					break;
				}
			}
		}
		if(s[i][0]==0&&s[i][1]!=0)
		{
			for(j=1;j<=a;j++)
			{
				if(s[j][1]==0&&e[j]!=e[i])
				{
					s[j][1]=i;
					s[i][0]=j;
					q=e[j];
					for(d=1;d<=a;d++)
					{
						if(e[d]==q)
						{
							e[d]=e[i];	
						}
								
					}			
					break;
				}
			}
			
		}
		printf("%d %d\n",s[i][0],s[i][1]);
	}
}
