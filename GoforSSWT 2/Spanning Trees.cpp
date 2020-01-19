#include<bits/stdc++.h>
using namespace std ;
const int MAX=1e6;
main()
{
    int n,k,m,i,j ;
    scanf("%d %d",&n,&k);
    m=(n-1)+(n-1-k);
    if((n==2||n==3)&&k==0)return 0 *printf("-1");
    printf("%d\n",m);
    for(i=1;i<n-k;i++)
    {
        printf("%d %d %d\n",i,i+1,MAX);
    }
    for(i=n-k;i<n;i++)
    {
        printf("%d %d %d\n",i,i+1,1000);
    }
    m=n-1-k;
    if(m!=n-1)
    {
        for(i=1;m;i++,m--)printf("%d %d %d\n",i,i+2,1);
        return 0;
    }
    while(m)
    {
        for(i=1;i<n&&m;i++)
        {
            for(j=i+2;j<=n&&m;j++,m--)
            {
                printf("%d %d %d\n",i,j,1);
            }
        }
    }
}
