#include<bits/stdc++.h>
using namespace std ;
typedef pair<double,double> pii;
const int N = 100009 ;
pii P[N];
pii strip[N];
bool compareX(pii x,pii y)
{
    if(x.first==y.first)return x.second<y.second;
    return x.first < y.first ;
}
bool compareY(pii x,pii y)
{
    if(x.second==y.second)return x.first<y.first ;
    return x.second<y.second;
}
double dist(pii x,pii y)
{
    double X=x.first-y.first,Y=x.second-y.second;
    if(X>1e4+1||Y>1e4+1)return 1e5;
    return sqrt(X*X+Y*Y);
}
double closest(int l,int r)
{
    int i,j,k=0 ;
    double d = 1e5 ;
    if(r-l+1<=3)
    {
        for(i=l;i<r;i++)
        {
            for(j=i+1;j<=r;j++)
            {
                d=min(d,dist(P[i],P[j]));
            }
        }
        return d;
    }
    int mid=(l+r)/2;
    double dl=closest(l,mid),dr=closest(mid+1,r);
    d=min(dl,dr);
    for(i=l;i<=r;i++)
    {
        if(abs(P[i].first-P[mid].first)<d)
        {
            strip[k++]=P[i];
        }
    }
    sort(strip,strip+k,compareY);
    for(i=0;i<k;i++)
    {
        for(j=i+1;j<k&&strip[j].second-strip[i].second<d;j++)
        {
            d=min(d,dist(strip[i],strip[j]));
        }
    }
    return d;
}
main()
{
    int i,n,q ;
    double d;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lf %lf",&P[i].first,&P[i].second);
        }
        sort(P,P+n,compareX);
        d=closest(0,n-1);
        if(d>10000)printf("No answer");
        else printf("%.1f",d);
        printf("\n");
    }


}
