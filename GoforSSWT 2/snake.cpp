#include<bits/stdc++.h>
using namespace std ;
vector<int> v;
vector<int>::iterator it ;
main()
{
    int n,m,k,s,t,wi ;
    scanf("%d %d %d",&n,&m,&k);
    while(n--)
    {
        scanf("%d %d %d",&s,&t,&wi);
        v.push_back(wi+t-s);
    }
    sort(v.begin(),v.end(),greater<int>());
    int ans=m-1;
    for(it=v.begin();*it>=0&&k>0&&it!=v.end();it++)
    {
        ans-=*it;
        k--;
    }
    printf("%d",ans);
}
