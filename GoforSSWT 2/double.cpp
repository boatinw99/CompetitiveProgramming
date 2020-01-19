#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
int a[N],qs[N],*p;
main()
{
    int n,i,j ;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        qs[i]=qs[i-1]+a[i];
    }
    if(qs[n]%2==1)
    {
        printf("NO");
        return 0 ;
    }
    int x= qs[n]/2 ,l,r;
    for(i=1;i<=n;i++)
    {
        p=lower_bound(qs+1,qs+n+1,x+qs[i-1]);
        if(*p==x+qs[i-1])
        {
            if(i==1)
            {
                printf("%d",p-qs);
            }
            else
            {
                printf("%d %d",i-1,p-qs);
            }
            return 0;
        }
    }
    printf("NO");
}
