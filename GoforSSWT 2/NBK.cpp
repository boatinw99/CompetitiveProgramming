#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
int qs[N],a[N];
vector<pair<int,int> >v;
vector<pair<int,int> >::iterator it;
main()
{
    int n,k,i,j,x ;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&qs[i]);
        qs[i]+=qs[i-1];
    }
    for(i=1;i<=k;i++)
    {
        scanf("%d",&x);
        v.push_back({x,i});
    }
    sort(v.begin(),v.end(),greater<pair<int,int> >());
    j=n;
    for(it=v.begin();it!=v.end();it++)
    {
        while(qs[j]>it->first&&j>0)
        {
            j--;
        }
        a[it->second]=j;
    }
    for(i=1;i<=k;i++)
    {
        printf("%d\n",a[i]);
    }
}
