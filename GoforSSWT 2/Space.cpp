#include<bits/stdc++.h>
using namespace std ;
const int N = 10009,M=2009;
int a[3][M];
int ans[3];
main()
{
    int n,m,i,j,x,y,z  ;
    char c;
    scanf("%d %d",&m,&n);
    for(i=1;i<=n+1;i++)
    {
        if(i%3==1)x=2,y=1,z=0;
        if(i%3==2)x=0,y=2,z=1;
        if(i%3==0)x=1,y=0,z=2;
        if(i==n+1)
        {
            for(j=1;j<=m;j++)a[x][j]=0;
        }
        else
        for(j=1;j<=m;j++)
        {
            scanf(" %c",&c);
            if(c=='0')a[x][j]=0;
            else a[x][j]=a[y][j]+1;
        }
        for(j=1;j<=m;j++)
        {
            if(a[y][j]>0&&a[y][j-1]==0&&a[x][j]==0&&a[x][j+1]==0&&
               a[x][j-1]==0)
            {
                if(a[y][j]==a[y][j+1])
                {
                    //printf("aa -> %d %d --- ",i,j);
                    ans[0]++;
                }
                else if(a[y][j]==a[z][j-1]+2&&a[y][j]==a[z][j+1]+2)
                {
                    //printf("bb -> %d %d --- ",i,j);
                    ans[1]++;
                }
                else
                {
                    //printf("cc -> %d %d ---",i,j);
                    ans[2]++;
                }
            }
        }
    }
    printf("%d %d %d",ans[0],ans[1],ans[2]);
}
