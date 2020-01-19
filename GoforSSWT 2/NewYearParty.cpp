#include<bits/stdc++.h>
using namespace std ;
const int N = 409;
bool b[N][N];
int s[N];
int degree[N];
bool a[N];
queue<int> q ;
main()
{
    int Q,n,m,i,j,x,y ;
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
        {
            s[i]=-1;
            a[i]=0;
            degree[i]=0;
            for(j=1;j<=n;j++)
            {
                b[i][j]=0;
            }
        }
        while(m--)
        {
            scanf("%d %d",&x,&y);
            b[x][y]++; b[y][x]++;
            degree[x]++; degree[y]++;
        }
        bool b1=0,b2=0;
        int co=0;
        for(i=1;i<=n;i++)
        {
            if(degree[i]==n-1)co++;
        }
        while(!q.empty())q.pop();
        for(i=1;i<=n;i++)
        {
            if(degree[i]<n-1)
            {
                a[i]++;
                q.push(i);
                s[i]=0;
                break;
            }
        }
        int x;
        bool e=0;
        while(!q.empty())
        {
            i=q.front();
            q.pop();
            x=s[i] ;
            for(j=1;j<=n;j++)
            {
                if(b[i][j]==0&&i!=j)
                {
                    if(s[j]==-1)
                    {
                        a[j]++;
                        s[j]=x^1;
                        q.push(j);
                    }
                    else if(s[j]==x)
                    {
                        printf("-1");
                        e++;
                        break;
                    }
                    else if(s[j]==x^1&&a[j]==0)
                    {
                        a[j]++;
                        q.push(j);
                    }
                }
            }
            if(e==1)break;
        }
        int l=0,r=0;
        if(e!=1)
        {
            for(i=1;i<=n;i++)
            {
                l+=(s[i]==0);
                r+=(s[i]==1);
            }
            x=abs(l-r);
            if(co<=x)printf("%d",x-co);
            else
            {
                printf("%d",(co-x)%2);
            }
        }
        printf("\n");


    }

}
