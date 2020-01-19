#include<bits/stdc++.h>
using namespace std ;
const int N = 600 ;
int a[N][N],qs[N][N];
int divide(int i,int j,int d)//i j size
{
    if(d==1)
    {
        return 0 ;
    }
    int all,min1=INT_MAX,q[5],g[5];
    q[1]=divide(i,j-d/2,d/2); q[2]=divide(i-d/2,j,d/2);
    q[3]=divide(i-d/2,j-d/2,d/2); q[4]=divide(i,j,d/2);
    all=q[1]+q[2]+q[3]+q[4];

    g[1]=qs[i][j-d/2]-qs[i][j-d]-qs[i-d/2][j-d/2]+qs[i-d/2][j-d];
    g[2]=qs[i-d/2][j]-qs[i-d][j]-qs[i-d/2][j-d/2]+qs[i-d][j-d/2];
    g[3]=qs[i-d/2][j-d/2]-qs[i-d/2][j-d]-qs[i-d][j-d/2]+qs[i-d][j-d];
    g[4]=qs[i][j]-qs[i][j-d/2]-qs[i-d/2][j]+qs[i-d/2][j-d/2];
    int P=(d*d)/4;
    for(i=1;i<=4;i++)
    {
        for(j=1;j<=4;j++)
        {
            ///(i,j)->(0,1);
            if(i!=j)
            {
                min1=min(min1,all-q[i]-q[j]+g[i]+P-g[j]);
            }
        }
    }
    return min1 ;
}
main()
{
    int n,i,j;
    char c;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf(" %c",&c);
            a[i][j]=c-'0';
            qs[i][j]=qs[i][j-1]+qs[i-1][j]-qs[i-1][j-1]+a[i][j];
        }
    }
    printf("%d",divide(n,n,n));
}
