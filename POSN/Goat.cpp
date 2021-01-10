#include<stdio.h>
int s[10][10];
int a,b;
void Check(int i,int j,int k)
{
    int g = s[i][j];
	if(i==a-1&&j==b-1)
    {
        s[i][j]=k;
    }
    else
    {
if(j>0&&g-s[i][j-1]>=-1&&g-s[i][j-1]<=1&&s[i][j-1]>=0)
    {
		if(s[i][j]<0);
		 else 
		 {
		 	s[i][j]=k;
		 	k--;
		 }
      // printf("L");
        Check(i,j-1,k);
    }   
    if(i<a&&g-s[i+1][j]>=-1&&g-s[i+1][j]<=1&&s[i+1][j]>=0)
    {
		 if(s[i][j]<0);
		 else 
		 {
		 	s[i][j]=k;
		 	k--;
		 }
       // printf("D");
        Check(i+1,j,k);
    } 	if(i>0&&g-s[i-1][j]>=-1&&g-s[i-1][j]<=1&&s[i-1][j]>=0)
    {
        if(s[i][j]<0);
		 else 
		 {
		 	s[i][j]=k;
		 	k--;
		 }
 	//	printf("U");
         Check(i-1,j,k);

    }if(j<b&&g-s[i][j+1]>=-1&&g-s[i][j+1]<=1&&s[i][j+1]>0)
    {
        if(s[i][j]<0);
		 else 
		 {
		 	s[i][j]=k;
		 	k--;
		 }
     //   printf("R");
        Check(i,j+1,k);
    }


    
    }
}
void Walk(int i,int j,int k)
{
    
    if(i>0&&s[i-1][j]==k)
    {
        k++;
        Walk(i-1,j,k);
    }
    if (j>0&&s[i][j-1]==k)
    {
        k++;
        Walk(i,j-1,k);
    } if(i<a&&s[i+1][j]==k)
    {
        k++;
        Walk(i+1,j,k);
    }
	if(j<b&&s[i][j+1]==k)
    {
        k++;
        Walk(i,j+1,k);
    }
    
    
	printf("%d %d\n",i+1,j+1);
}
main()
{
    int i,j,c;
    scanf("%d %d",&a,&b);
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            scanf("%d",&c);
            s[i][j]=c;
        }
    }
    Check(0,0,-1);
    printf("\n");
	/*for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            printf("%d ",s[i][j]);
        }
        printf("\n");
    }*/
    if(s[a-1][b-1]<0)
    {printf("1\n");
    Walk(a-1,b-1,s[a-1][b-1]+1);
    }
    else printf("0");

}
