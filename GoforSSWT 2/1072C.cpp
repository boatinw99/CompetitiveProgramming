#include <bits/stdc++.h>
using namespace std;
vector<int> u,v;
vector<int>::iterator it ;
main()
{
    int a,b,i=0;
    scanf("%d %d",&a,&b);
    while(1ll*i*(i+1)/2<=(a+b))i++;i--;
    for(i;i>0;i--)
    {
        if(b>=a)
        {
            b-=i;
            v.push_back(i);
        }
        else u.push_back(i),a-=i;
    }
    printf("%d\n",u.size());
    for(it=u.begin();it!=u.end();it++)printf("%d ",*it);
    if(!u.empty())printf("\n");
    printf("%d\n",v.size());
    for(it=v.begin();it!=v.end();it++)printf("%d ",*it);
}
