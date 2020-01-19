#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 309,LOG=log2(N) ;
int F[LOG+1][N][N];
int ans[N][N];
int temp[N][N];
main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,m,u,v,wi1,wi2,d,i,j,k,pr ;
    bool chk ;
    cin >> n >> m ;
    for(d=0;d<=LOG;d++)for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)F[d][i][j]=-1e9;
        F[d][i][i]=0;
    }
    while(m--)
    {
        cin >> u >> v >> wi1 >> wi2 ;
        F[0][u][v]=wi1; F[0][v][u]=wi2;
    }
    for(d=1;d<=LOG;d++)
    {
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)for(k=1;k<=n;k++)
            F[d][i][j]=max(F[d][i][j],F[d-1][i][k]+F[d-1][k][j]);
    }
    d=log2(n);
    for(d;d>=0;d--)
    {
        chk=0;
        for(i=1;i<=n&&chk==0;i++)
        {
            for(j=1;j<=n;j++)
            if(F[d][i][j]+F[0][j][i]>0)
            {
                chk++;
                break ;
            }
        }
        if(chk==0)break;
    }
    if(d==-1&&chk==1)
    {
        printf("2");
        return 0 ;
    }
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)ans[i][j]=F[d][i][j];
    pr+=(1<<d);
    for(d--;d>=0;d--)
    {
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)temp[i][j]=-1e9;
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)for(k=1;k<=n;k++)
            temp[i][j]=max(temp[i][j],ans[i][k]+F[d][k][j]);
        chk=0;
        for(i=1;i<=n&&chk==0;i++)
        {
            for(j=1;j<=n;j++)
            if(temp[i][j]+F[0][j][i]>0)
            {
                chk++;
                break;
            }
        }
        if(chk==0)
        {
            pr+=(1<<d);
            for(i=1;i<=n;i++)for(j=1;j<=n;j++)
                ans[i][j]=temp[i][j];
        }
    }
    if(pr+2>n)
    {
        printf("0");
        return 0 ;
    }
    printf("%d",pr+2);
}
