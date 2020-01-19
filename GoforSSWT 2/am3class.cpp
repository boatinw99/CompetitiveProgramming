#include<bits/stdc++.h>
using namespace std ;
struct color
{
    int a,b,c;
};
map<pair<int,pair<int,int> >,int> key;
main()
{
    int w,h,i,j,x,y,z ;
    scanf("%d %d",&w,&h);
    color P;
    for(i=1;i<=w;i++)
    {
        for(j=1;j<=3*h;j++)
        {
            scanf("%d %d %d",&x,&y,&z);
            key[{x,{y,z}}]++;
        }
    }
    if(key.size()>=8000)printf("3");
    else if(key.size()<=4000)
    {
        printf("A");
    }
    else printf("M");
}
