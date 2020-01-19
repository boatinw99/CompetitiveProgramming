#include<bits/stdc++.h>
using namespace std ;
const int B = 50 ;
int md ;
int bs;
int ans[B][B];
int F[B][B],M[B][B],c[B][B];
int n,m;
void multi(int a[B][B],int b[B][B])
{
    int i,j,k ;
    for(i=0;i<bs;i++)for(j=0;j<bs;j++)for(k=0;k<bs;k++)
        c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j])%md ;
    for(i=0;i<bs;i++)for(j=0;j<bs;j++)a[i][j]=c[i][j],c[i][j]=0;
}
void multi2()
{
    int i,j,k ;
    for(i=0;i<B;i++)for(j=0;j<B;j++)for(k=0;k<B;k++)
        c[i][j]=(c[i][j]+1ll*F[i][k]*ans[k][j])%md;
    for(i=0;i<B;i++)for(j=0;j<B;j++)ans[i][j]=c[i][j],c[i][j]=0;
}
void multi3()
{
    int i,j,k;
    for(i=0;i<B;i++)for(j=0;j<B;j++)for(k=0;k<B;k++)
        c[i][j]=(c[i][j]+1ll*ans[i][k]*F[k][j])%md ;
    for(i=0;i<B;i++)for(j=0;j<B;j++)ans[i][j]=c[i][j],c[i][j]=0;
}
void powr(int x)
{
    if(x==1)return ;
    powr(x/2);
    multi(F,F);
    if(x&1)multi(F,M);
}
void construct(int x)
{
    int i,j ;
    memset(F,0,sizeof F);
    F[0][0]=F[0][1]=1;
    F[x-1][x-1]=F[x-1][x-2]=1 ;
    for(i=1;i<x-1;i++)F[i][i-1]=F[i][i]=F[i][i+1]=1;
    for(i=0;i<bs;i++)for(j=0;j<bs;j++)M[i][j]=F[i][j];
}
main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T,i,j,k,w,x,y ;
    cin >> T ;
    while(T--)
    {
        memset(ans,0,sizeof ans);
        cin >> n >> m >> w >> md >> x >> y ;
        ans[0][0]=x ; ans[n-1][m-1]=y ;
        if(w==0)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)cout << ans[i][j] << " ";
                cout << '\n';
            }
            cout << '\n' ;
            continue ;
        }
        bs=n;
        construct(n);
        powr(w);multi2();
        bs=m;
        construct(m);
        powr(w);multi3();
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)cout << ans[i][j] << " " ;
            cout << '\n' ;
        }
        cout << '\n' ;
    }
}
