#include<stdio.h>
main()
{  int a[20],c,i,j,f,k,g=0;
   char s[250],r[250];
	scanf("%d  ",&c);
	c--;
	
	for(i=0;i<=c;i++)
	{
		gets(s);
		gets(r);
		for(j=0;r[j]!='\0'&&g!=99;j++)
		{
			k=0;
			for(f=0;s[f]!='\0'&&k!=99;f++)
			{
				if(r[j]==s[f])
				{
					k=99;
					s[f]='0';
				}
			}
			if(k!=99)g=99;
		}
		if(k==99)
		{
			a[i]=1;
		}
		else a[i]=0;
		
		for(j;j>=0;j--)
			s[j]=0;
		for(f;j>=0;f--)
			s[f]=0;
	}
	for(i=0;i<=c;i++)
	{
		if(a[i]==1)
		{
			printf("YES");
		}
		else printf("NO");
		printf("\n");
	}
}
