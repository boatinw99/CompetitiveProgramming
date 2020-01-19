#include<bits/stdc++.h>
using namespace std ;
main()
{
    int n,m,k,i,j,ans=0 ;
    scanf("%d %d %d",&n,&m,&k);
    while(k--)
    {
        ans+=2*n+2*m-4;
        n-=4;
        m-=4;
    }
    printf("%d",ans);
}
