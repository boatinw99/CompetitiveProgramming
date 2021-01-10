#include<stdio.h>
main()
{   char s[100],r[100];
	int  a[100],b[100];
	int i,j,temp,k1,k2;
    gets(s);
    gets(r);
    
	for(i=0;s[i]!='\0';i++)
	{
		a[i]=s[i];
	}
	k1=i;
    	for(i=k1;i>=1;i--)
	{
		for(j=0;j<i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("\n");
	
		for(i=1;i<=k1;i++)
		printf("%c",a[i]);
		printf("\n");
        for(i=1;i<=k1;i++)
        

	
		for(i=0;r[i]!='\0';i++)
	{
		b[i]=r[i];
	}
	k2=i;
    	for(i=k2;i>=1;i--)
	{
		for(j=0;j<i;j++)
		{
			if(b[j]>b[j+1])
			{
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
			}
		}
	}
	printf("\n");
	
		for(i=0;r[i]!='\0';i++)
		printf("%c",b[i]);
		
		if(k1!=k2)
		{
			printf("\nInvalid");
			k1=99;
		}
		else 
		{
			for(i=0;s[i]!='\0'&&k1!=7;i++)
			{
				if(a[i]==b[i]);
				else k1=7;
			}	
			if(k1==7)
		{
			printf("InValid");
		}
		else printf("Valid");
		}
	*/
	

	
}
