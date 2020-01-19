#include<bits/stdc++.h>
using namespace std ;
const int N = 1009;
struct Point
{
    int x,y ;
};
Point a[N];
double ans[N];
main()
{
    int n,c,i,l,r ;
    double pr = 0 ;
    scanf("%d %d",&n,&c);
    for(i=1;i<=n;i++)
    {
        ans[i]=INT_MAX;
        scanf("%d %d",&a[i].x,&a[i].y);
    }
    while(c--)
    {
        scanf("%d %d",&l,&r);
        for(i=1;i<=n;i++)
        {
            double X=l-a[i].x,Y=r-a[i].y;
            ans[i]=min(ans[i],sqrt(X*X+Y*Y));
        }
    }
    for(i=1;i<=n;i++)pr=max(pr,ans[i]);
    printf("%.4f",pr);
}
