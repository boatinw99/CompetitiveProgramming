#include<bits/stdc++.h>
using namespace std;
int s[109][109];
int b[109][109];
queue<pair<int,pair<int,int> > >q ;
main()
{
    int m,n,i,j,co,x,y ;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i%2==0)
            scanf("%d",&s[i][j+1]);
            else scanf("%d",&s[i][j]);
        }
    }
    n++;
    if(s[(m-1)/2-1][0]==1)
        q.push({1,{(m-1)/2-1,0}});
    if(s[(m-1)/2][1]==1)
        q.push({1,{(m-1)/2,1}});
    if(s[(m-1)/2+1][0]==1)
        q.push({1,{(m-1)/2+1,0}});
    while(!q.empty())
    {
        co=q.front().first;
        x=q.front().second.first;
        y=q.front().second.second;
        q.pop();
        co++;
        if((x==(m-1)/2&&y==n-1))
        {
            printf("%d",co-1);
            return 0;
        }
        if(s[x-1][y]!=0&&co%s[x-1][y]==0&&x>0&&b[x-1][y]!=co)
           {
               b[x-1][y]=co;
               q.push({co,{x-1,y}});
           }
        if(s[x][y+1]!=0&&co%s[x][y+1]==0&&y+1<n&&b[x][y+1]!=co)
           {
               b[x][y+1]=co;
               q.push({co,{x,y+1}});
           }
        if(s[x][y-1]!=0&&co%s[x][y-1]==0&&b[x][y-1]!=co)
           {
               b[x][y-1]=co;
               q.push({co,{x,y-1}});
           }
        if(s[x+1][y]!=0&&co%s[x+1][y]==0&&x!=m-1&&b[x+1][y]!=co)
           {
               b[x+1][y]=co;
               q.push({co,{x+1,y}});
           }
          ///
        if(x%2==0)
        {
           if(s[x-1][y-1]!=0&&co%s[x-1][y-1]==0&&x>0&&y>0&&b[x-1][y-1]!=co)
           {
               b[x-1][y -1]=co;
               q.push({co,{x-1,y-1}});
           }
           if(s[x+1][y-1]!=0&&co%s[x+1][y-1]==0&&x!=m-1&&y>0&&b[x+1][y-1]!=co)
           {
               b[x+1][y-1]=co;
               q.push({co,{x+1,y-1}});
           }
        }
        else
        {
            if(s[x-1][y+1]!=0&&co%s[x-1][y+1]==0&&x>0&&b[x-1][y+1]!=co)
            {
                b[x-1][y+1]=co;
                q.push({co,{x-1,y+1}});
            }
            if(s[x+1][y+1]!=0&&co%s[x+1][y+1]==0&&x!=m-1&&b[x+1][y+1]!=co)
            {
                b[x+1][y+1]=co;
                q.push({co,{x+1,y+1}});
            }
        }
    }
}
