#include<bits/stdc++.h>
using namespace std ;
const int N = 1009;
vector<pair<int,int> > v;
vector<pair<int,int> > ::iterator it ;
int a[N];
main()
{
    int n,m,i,j,ans,x ;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++)
    {
        ans=0;
        for(j=i;j<=n;j++)
        {
            ans+=a[j];
            v.push_back({ans,j-i+1});
        }
    }
    sort(v.begin(),v.end());
    for(it=v.begin()+1;it!=v.end();it++)
    {
        it->second=max(it->second,(it-1)->second);
    }
    while(m--)
    {
        scanf("%d",&x);
        it=lower_bound(v.begin(),v.end(),make_pair(x+1,0));
        it--;
        if(it>=v.begin())printf("%d\n",it->second);
        else printf("0\n");
    }
}
