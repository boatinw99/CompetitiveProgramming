#include<bits/stdc++.h>
using namespace std ;
vector<double> a,b;
vector<double>::iterator it,it1;
main()
{
    int n,m,i,j ;
    double l,r,x,sum1=0,sum2=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%lf",&x);
        a.push_back(x);
        sum1+=x;
    }
    for(i=1;i<=m;i++)
    {
        scanf("%lf",&x);
        b.push_back(x);
        sum2+=x;
    }
    if(sum1/n<sum2/m)
    {
        //printf("a");
        swap(a,b);
        swap(n,m);
        swap(sum1,sum2);
    }
    l=sum1/n; r=sum2/m;
    int ans=0;
    ///l,r ; l>r
    a.push_back(INT_MAX*1.0);
    it1=a.begin();
    while(1)
    {
        it=upper_bound(it1,a.end(),r);
        if(*it>=l)break;
        sum1-=*it;
        sum2+=*it;
        ans++;
        it1=it+1;
        n--; m++;
        l=sum1/n; r=sum2/m;
    }
    printf("%d",ans);
}
