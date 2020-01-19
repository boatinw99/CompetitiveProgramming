#include<bits/stdc++.h>
using namespace std ;
const int N = 3e5+9;
set<int> s;
set<int>::iterator it;
int ans[N];
main()
{
    int n,m,l,r,x,i ;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)s.insert(i);
    while(m--)
    {
        scanf("%d %d %d",&l,&r,&x);
        it=s.lower_bound(l);
        for(it;it!=s.end()&&*it<=r;)
        {
            if(*it!=x)
            {
                ans[*it]=x;
                s.erase(it++);
            }
            else it++;
        }
    }
    for(i=1;i<=n;i++)
    printf("%d ",ans[i]);
}
