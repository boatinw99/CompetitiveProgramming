#include<bits/stdc++.h>
using namespace std ;
typedef  double ld ;
typedef pair<int,int> pii;
const int N = 1e5+9;
pii P[N];
pii strip[N];
int n;
bool compareX(pii x , pii y)
{
    if(x.first==y.first)return x.second<y.second;
    return x.first<y.first;
}
bool compareY(pii x,pii y)
{
    if(x.second==y.second)return x.first<y.first;
    return x.second<y.second;
}
ld dist(pii x,pii y)
{
    ld X=(x.first-y.first);
    ld Y=(x.second-y.second);
    return sqrt(X*X+Y*Y);
}
ld closest(int l,int r)
{
    int i,j,k=0 ;
    ld d=1e15;
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
    ld dl=closest(l,mid),dr=closest(mid+1,r);
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
    int w,x,y,i,R,D ;
    scanf("%d",&w);
    while(w--)
    {
        scanf("%d %d %d",&n,&R,&D);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&P[i].first,&P[i].second);
        }
        sort(P,P+n,compareX);
        printf("%s\n",(closest(0,n-1)<2*R+D)?("N"):("Y"));
    }

}
