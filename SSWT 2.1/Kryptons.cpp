#include<bits/stdc++.h>
using namespace std ;
typedef unsigned u ;
const int B=50,LOG=30 ;
u F[9][LOG][B][B];
u f[9][B];
u ans[B];
u temp[B];
void pre(int base)
{
    int i,j,k,d,x0=1,x1=0,x2=0,x3=0,x4=0,x5=0 ;
    if(base==6)x5=1; if(base>=5)x4++; if(base>=4)x3++;
    if(base>=3)x2++; if(base>=2)x1++;

    F[base][0][0][24]=x5;F[base][0][0][25]=x1;
    F[base][0][0][40]=x4;
    F[base][0][0][44]=x2;F[base][0][0][49]=x3;

    F[base][0][25][0]=x0;F[base][0][25][15]=x5;
    F[base][0][25][33]=x4;
    F[base][0][25][41]=x2;F[base][0][25][44]=x3;
    if(base>=3)
    {
        F[base][0][41][3]=x0;F[base][0][41][8]=x5;
        F[base][0][41][25]=x1;
        F[base][0][41][28]=x4;F[base][0][41][41]=x3;
    }
    for(i=1;i<25;i++)F[base][0][i][i-1]=1;
    for(i=26;i<41;i++)F[base][0][i][i-1]=1;
    if(base>=3)for(i=42;i<50;i++)F[base][0][i][i-1]=1;
    for(d=1;d<LOG;d++)
    {
        for(i=0;i<B;i++)for(j=0;j<B;j++)for(k=0;k<B;k++)
            F[base][d][i][j]+=F[base][d-1][i][k]*F[base][d-1][k][j];
    }
}
u findans(int base,int n)
{
    int d=LOG-1,i,j,k ;
    for(i=0;i<B;i++)ans[i]=f[base][i];
    for(d=0;d<LOG;d++)
    {
        if((1<<d)&n)
        {
            memset(temp,0,sizeof temp);
            for(i=0;i<B;i++)
            {
                for(j=0;j<B;j++)
                {
                    temp[i]+=F[base][d][i][j]*ans[j];
                    if(F[base][d][i][j]*ans[j]!=0)
                        printf("%d %d->%u \n",i,j,F[base][d][i][j]);
                }
            }
            for(i=0;i<B;i++)ans[i]=temp[i];
        }
    }
    cout << ans[0] << " " << ans[25] << " " <<ans[41]<< '\n';
    return (ans[0]+ans[25]+ans[41]);
}
main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    ///Pre-processing
    int i,j,T,base,n ;
    for(i=2;i<=6;i++)pre(i);
    f[2][0]=0; f[2][25]=1; f[2][41]=0;
    f[3][0]=0; f[3][25]=1; f[3][41]=1;
    f[4][0]=1; f[4][25]=1; f[4][41]=1;
    f[5][0]=1; f[5][25]=2; f[5][41]=1;
    f[6][0]=1; f[6][25]=2; f[6][41]=2;
    cin >> T ;
    for(i=1;i<=T;i++)
    {
        cin >> base >> n ;
        cout << "Case " << i <<": " << findans(base,n) << '\n' ;
    }
}
