#include<bits/stdc++.h>
using namespace std ;
const int N = 109;
int a[N][N][4];
char b[N][N];
int dix[4][3];
int diy[4][3];
pair<int,int> ter[4][3];
//char key[256];
priority_queue<pair<int,pair<pair<int,int>,int> > > pq;
main()
{
    int n,m,i,j,A,B,C,x,pr,di,y,d ;
    scanf("%d %d %d",&A,&B,&C);
    scanf("%d %d",&m,&n);
    ///key['L']=0; key['R']=1; key['U']=2; key['D']=3;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf(" %c",&b[i][j]);
        }
    }
    pq.push({0,{{n,1},0}});
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            a[i][j][0]=INT_MAX;
            a[i][j][1]=INT_MAX;
            a[i][j][2]=INT_MAX;
            a[i][j][3]=INT_MAX;
        }
    }
    a[n][1][0]=0;
    ///U -> L , U->R , U->D
    dix[2][0]=0,diy[2][0]=-1,ter[2][0]={B,1};
    dix[2][1]=0,diy[2][1]=1,ter[2][1]={B,0};
    dix[2][2]=1,diy[2][2]=0,ter[2][2]={A,2};
    ///D->L ,D->R ,D->U
    dix[3][0]=0,diy[3][0]=-1,ter[3][0]={B,1};
    dix[3][1]=0,diy[3][1]=1,ter[3][1]={B,0};
    dix[3][2]=-1,diy[3][2]=0,ter[3][2]={A,3};
    ///L->U,L->D,L->R
    dix[0][0]=-1,diy[0][0]=0,ter[0][0]={B,3};
    dix[0][1]=1,diy[0][1]=0,ter[0][1]={B,2};
    dix[0][2]=0,diy[0][2]=1,ter[0][2]={A,0};
    ///R->U , R->D , R->L
    dix[1][0]=-1,diy[1][0]=0,ter[1][0]={B,3};
    dix[1][1]=1,diy[1][1]=0,ter[1][1]={B,2};
    dix[1][2]=0,diy[1][2]=1,ter[1][2]={A,1};
    a[1][m+1][0]=INT_MAX ;
    pair<int,int> u ;
    int c;
    while(!pq.empty())
    {
        pr=pq.top().first*-1 ;
        x=pq.top().second.first.first;
        y=pq.top().second.first.second;
        di=pq.top().second.second ;
        pq.pop();
       // printf("%d ->%d %d\n",pr,x,y);
        if(a[x][y][di]!=pr)continue;
        if(x==1&&y==m+1&&di==0)
        {
            printf("%d",pr);
            return 0;
        }
        c=0;
        if(b[x][y]=='X')c=C;
        for(d=0;d<3;d++)
        {
            u=ter[di][d];
            if(pr+u.first+c<
               a[x+dix[di][d]][y+diy[di][d]][u.second])
            {
                a[x+dix[di][d]][y+diy[di][d]][u.second]=pr+u.first+c;
                pq.push({-pr-u.first-c,
                        {{x+dix[di][d],y+diy[di][d]},u.second}});
            }
        }
    }
}
