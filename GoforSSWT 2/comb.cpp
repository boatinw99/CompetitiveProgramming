#include<bits/stdc++.h>
using namespace std;
int fact[15];
int C(int n,int r)
{
    return fact[n]/fact[r]/fact[n-r];
}
main()
{
    int n,k,pos,i,j,p=1 ;
    scanf("%d %d %d",&n,&k,&pos);
    fact[0]=1;
    for(i=1;i<=12;i++)fact[i]=fact[i-1]*i;
    for(i=1;i<=k;i++)
    {
        while(C(n-p,k-i)<pos)
        {
            pos-=C(n-p,k-i);
            p++;
        }
        printf("%d ",p);
        p++;
    }
}
