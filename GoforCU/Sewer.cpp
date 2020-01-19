#include<bits/stdc++.h>
using namespace std;
int m,n ;
char s[100][100];
int b[100][100];
queue<pair<pair<int,int>,int> >q;
main()
{
    int i,j,x,y,count;
    scanf("%d %d",&m,&n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf(" %c",&s[i][j]);
            b[i][j]=INT_MAX;
        }
    }
    q.push({{0,0},1});
    b[0][0]=1;
    while(!q.empty())
    {
        x=q.front().first.first;
        y=q.front().first.second;
        count=q.front().second;
        q.pop();
        if((s[x][y]=='B'||s[x][y]=='R')&&y<n-1)
        {
            if(b[x][y+1]==count+1)
            {
                printf("%d\n",count+1);
                printf("%d %d",x+1,y+2);
                return 0;
            }
            else if(b[x][y+1]==INT_MAX)
            {
                q.push({{x,y+1},count+1});
                b[x][y+1]=count+1;
            }
        }
        if((s[x][y]=='B'||s[x][y]=='D')&&x<m-1)
        {
            if(b[x+1][y]==count+1)
            {
                printf("%d\n",count+1);
                printf("%d %d",x+2,y+1);
                return 0 ;
            }
            else if(b[x+1][y]==INT_MAX)
            {
                q.push({{x+1,y},count+1});
                b[x+1][y]=count+1;
            }
        }
        if((s[x][y-1]=='B'||s[x][y-1]=='R')&&y>0)
        {
            if(b[x][y-1]==count+1)
            {
                printf("%d\n",count+1);
                printf("%d %d",x+1,y);
                return 0 ;
            }
            else if(b[x][y-1]==INT_MAX)
            {
                q.push({{x,y-1},count+1});
                b[x][y-1]=count+1;
            }
        }
        if((s[x-1][y]=='B'||s[x-1][y]=='D')&&x>0)
        {
            if(b[x-1][y]==count+1)
            {
                printf("%d\n",count+1);
                printf("%d %d",x,y+1);
                return 0 ;
            }
            else if(b[x-1][y]==INT_MAX)
            {
                q.push({{x-1,y},count+1});
                b[x-1][y]=count+1;
            }
        }
 
    }
}
