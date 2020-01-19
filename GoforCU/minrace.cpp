#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
int a[N];
multiset<int> s;
multiset<int>::iterator it;
main()
{
    int n,k,x,y,i,j ;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&x,&y);
        a[y]=x;
    }
    s.insert(a[1]);
    for(i=2;i<=n;i++)
    {
        it=s.upper_bound(a[i]-1);
        if(it==s.begin())
        {
            s.insert(a[i]);
        }
        else
        {
            it--;
            s.erase(it);
            s.insert(a[i]);
        }
    }
    printf("%d",s.size());
}
