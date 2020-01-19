#include<bits/stdc++.h>
using namespace std ;
const int N = 80009,MOD=1e9-1;
int bi[N][49];
int pos[N];
void update(int i,int j,int co)
{
    for(;i<N;i+=i&-i)bi[i][j]=(bi[i][j]+co)%MOD;
}
int getsum(int i,int j)
{
    int sum=0;
    for(;i;i-=i&-i)sum=(sum+bi[i][j])%MOD;
    return sum;
}
main()
{
    int n,k,i,j,x,y,sum ;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        pos[x]=i;
    }
    for(i=n;i>=1;i--)
    {
        x=pos[i];
        for(j=k-1;j>=1;j--)
        {
            sum=getsum(x,j);
            update(x,j+1,sum);
        }
        update(x,1,1);
    }
    printf("%d",getsum(n,k));
}
