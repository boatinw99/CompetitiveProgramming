#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
struct Point
{
    int A,B;
    int pos;
};
bool b(Point q,Point e)
{
    return q.B < e.B ;
}
vector<Point> v;
vector<Point> ::iterator it;
main()
{
    int n,i,x,y;
    ll co=0 ;
    scanf("%d",&n);
    for(i=1;i<=2*n-1;i++)
    {
        scanf("%d %d",&x,&y);
        co+=1ll*x;
        v.push_back({x,y,i});
    }
    sort(v.begin(),v.end(),b);
    ll pr = 0 ;
    for(it=v.begin();it<v.end();it+=2)
    {
        pr+=it->A;
    }
    if(pr>=co/2)
    {
        for(it=v.begin();it<v.end();it+=2)
        {
            printf("%d ",it->pos);
        }
    }
    else
    {
        for(it=v.begin()+1;it<v.end();it+=2)
        {
            printf("%d ",it->pos);
        }
        it=v.end()-1;
        printf("%d",it->pos);
    }
}
