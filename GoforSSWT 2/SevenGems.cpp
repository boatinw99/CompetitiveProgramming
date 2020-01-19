#include<bits/stdc++.h>
using namespace std ;
const int N = 209;
char a[N][N];
int dp[N][N][7][(1<<7)];
int b[N][N];
int check[1<<7];
int dix[5]={0,0,1,-1,0};
int diy[5]={1,-1,0,0,0};
int bit[7];
struct P
{
    int times,x,y,mask,num ;
};
queue<struct P> q;
int main()
{
    int n,m,i,j ;
    int d=0;
    struct P V,E ;
    ///Preprocess
    bit[0]=1;
    for(i=1;i<7;i++)bit[i]=bit[i-1]*2;
    scanf("%d %d",&n,&m);
    int st,ed;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf(" %c",&a[i][j]);
            if(a[i][j]=='G')
            {
                a[i][j]='A'+d;
                d++;
            }
            else if(a[i][j]=='S')st=i,ed=j,a[i][j]='.';
        }
    }
    dp[st][ed][0][0]=1;
    q.push({0,st,ed,0,0});
    int ti,k ;
    char u;
    while(!q.empty())
    {
        V=q.front();
        q.pop();
        ti=(V.times+1)%6;
        if(V.mask==(1<<7)-1)
        {
            printf("%d",dp[V.x][V.y][V.times][V.mask]-1);
            return 0 ;
        }
        for(i=0;i<5;i++)
        {
            E=V;
            E.x+=dix[i];
            E.y+=diy[i];
            u=a[E.x][E.y];
            E.times=ti;
            k=u-'A';
            if(E.x<=0||E.y<=0||E.x>n||E.y>m);
            else if(u>='A'&&u<='G')
            {
                E.num+=((E.mask&bit[k])==0);
                E.mask=E.mask|bit[k];
                if(!dp[E.x][E.y][ti][E.mask])
                {
                    dp[E.x][E.y][ti][E.mask]=dp[V.x][V.y][V.times][V.mask]+1;
                    q.push(E);
                }
            }
            else if(u>='1'&&u<='6')
            {
                if(dp[E.x][E.y][ti][E.mask]==0&&
                    (ti==u-'1'||E.num>=u-'0'))
                {
                    dp[E.x][E.y][ti][E.mask]=dp[V.x][V.y][V.times][V.mask]+1;
                    q.push(E);
                }
            }
            else if((u=='.')&&dp[E.x][E.y][ti][E.mask]==0)
            {
                dp[E.x][E.y][ti][E.mask]=dp[V.x][V.y][V.times][V.mask]+1;
                q.push(E);
            }
        }
    }
    printf("-1");
}
