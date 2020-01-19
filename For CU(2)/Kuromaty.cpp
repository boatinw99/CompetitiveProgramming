#include<stdio.h>
char s[100][100];
int m,n ;
main()
{
	int i,j,i1,j1,i2,j2,k=0,max=0,g=0; 
	scanf("%d %d ",&n,&m);
	char q[n];
	for(i=0;i<m;i++)
	{
		gets(q);
		for(j=0;j<n;j++)
		{
			s[i][j]=q[j];
		}
	}
		for(i=0;i<m;i++)
		{
		
		for(j=0;j<n;j++)
		{   k=0;
			if(s[i][j]!='T')
			{
				k++;
				g=0;
				for(i1=i+1,j1=j+1;g!=99&&i1<m&&j1<n;i1++,j1++)
				{
					for(i2=i;i2<=i1&&g!=99;i2++)
					{
						if(s[i2][j1]=='T'){
						g=99; break;
						}
					}
					for(j2=j;j2<=j1&&g!=99;j2++)
					{
						if(s[i1][j2]=='T'){g=99;break;
						}
					}
					if(g!=99){ //printf("%d\n",k);
					k++;}
				}
				if(k>max)
				{
					max=k;
				}
			}
			//printf("%d\n",k);
		}
		}
        printf("%d",max);
	
	
	
}
