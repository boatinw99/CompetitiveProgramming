#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
int a[N];
vector<int>v;
vector<int>::iterator it ;
main()
{
    int n,m,k,i,j,ans=0;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=2;i<=m;i++)
    {
        v.push_back(a[i]-a[i-1]-1);
        ans+=a[i]-a[i-1]-1;
    }
    sort(v.begin(),v.end(),greater<int>());
    for(it=v.begin();it!=v.end()&&k>=2;it++,k--)
    {
        ans-=*it;
    }
    printf("%d",ans);
}
