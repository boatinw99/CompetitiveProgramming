#include<stdio.h>
int k=0,n;
int a[100][100]={0};
int Call(int i,int j)
{
    int i1,b[n][n],p,o; ///p=i o=j;
    for(p=0;p<n;p++)
    {
        for(o=0;o<n;o++)
        {
            b[p][o]=a[p][o];
        }
    }
    for(i=0;i<n;i++)
    {
        if(a[i][j]==0)
        {
            a[i][j]=9;
            if(j==n-1){k=99; return 0;}
            for(i1=0;i1<n;i1++)
            {
                a[i][i1]=1;
                a[i1][j]=1;
                if(i+i1+1<n&&i1+1+j<n)
					a[i+i1+1][i1+1+j]=1;
				if(i-i1-1>=0&&i1+1+j<n)
            		a[i-i1-1][i1+1+j]=1;
            }
            a[i][j]=9;
            Call(0,j+1);
            a[i][j]=9;
            if(k==99)return 0;
            for(p=0;p<n;p++)
   			{
      		 	for(o=0;o<n;o++)
       		 	{
        			a[p][o]=b[p][o];
       		 	}
   			}
        }
    }
   /* for(p=0;p<n;p++)
    {
        for(o=0;o<n;o++)
        {
            a[p][o]=b[p][o];
        }
    }*/
}
main()
{
    int i,j,i1,j1 ;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(i1=0;i1<n;i1++)
        {
            a[i1][0]=1;
            a[i][i1]=1;
            if(i+i1+1<n)
			a[i+i1+1][i1+1]=1;
			if(i-i1-1>=0)
            a[i-i1-1][i1+1]=1;
        }
		a[i][0]=9;
        Call(0,1);
        if(k==99)
        {break;}
        for(i1=0;i1<n;i1++)
        {
            for(j1=0;j1<n;j1++)
            a[i1][j1]=0;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        printf("%d ",a[i][j]);
        printf("\n");
    }

}
