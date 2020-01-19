#include<bits/stdc++.h>
using namespace std ;
const int N = 15;
bool use[N];
int fact[N];
int C(int n,int r)
{
    return fact[n]/fact[n-r];
}
main()
{
    int n,k,pos,i,j,p;
    scanf("%d %d %d",&n,&k,&pos);
    fact[0]=1;
    for(i=1;i<=12;i++)fact[i]=fact[i-1]*i;
    for(i=1;i<=k;i++)
    {
        for(p=1;p<=n;p++)
        {
            if(use[p]==0&&C(n-i,k-i)<pos)
            {
                pos-=C(n-i,k-i);
            }
            else if(use[p]==0)
            {
                break;
            }
        }
        use[p]++;
        printf("%d ",p);
    }
}
