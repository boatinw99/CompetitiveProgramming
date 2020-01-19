#include<bits/stdc++.h>
using namespace std ;
vector<int> ans,hi;
vector<int>::iterator it ;
const int N = 2e5+9 ;
int a[N];
main()
{
    int n,k,i,j,min1=INT_MAX ;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        min1=min(min1,a[i]);
    }
    for(i=1;i<=n;i++)
    {
        if(min1!=a[i])
        hi.push_back({a[i]-min1});
    }
    sort(hi.begin(),hi.end());
    int size=hi.size(),times=0;
    for(it=hi.begin();it!=hi.end();it++)
    {
        while(times<*it)
        {
            times++;
            ans.push_back(size);
        }
        size--;
    }
    if(ans.size()==0)
    {
        printf("%d",0);
        return 0 ;
    }
    int pr=1,now=0;
    for(it=ans.begin();it!=ans.end();it++)
    {
        if(now+*it>k)
        {
            pr++;
            now=0;
        }
        now+=*it;
    }
    printf("%d",pr);

}
