#include<stdio.h>
int s[6],i,e[260],a,j,g,g2;
char b[6],c[260]; ///s -> cage ,, e = nub;
main()
{
	gets(b);
	for(i=0;i<3;i++)
	{
		s[i]=b[i]-48;
	}
	gets(c);
	g=s[0];  g2=s[2];
	for(i=0;c[i]!='\0';i++)
	{
		e[i]=c[i]-48;
	}
	for(i=0;c[i]!='\0';i++)
	{
		a=e[i];
		//printf("%d %d %d\n",s[0],s[1],s[2]);
		for(j=0;j<3;j++)
		{
			a=(a+s[j]-1)%9;
			if(a==0)a=9;
			//if(a==-1)printf("fuck");
			//printf("%d ",a);
		}
	//	printf("\n");
		s[0]=(s[0]+g)%9;
		s[1]--;
		if(s[1]==0)s[1]=9;
		s[2]=(s[2]+g2)%9;
		printf("%d",a);
	}
}
