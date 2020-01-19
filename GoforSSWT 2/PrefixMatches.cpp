#include<bits/stdc++.h>
using namespace std ;
deque<pair<int,int> > dq;
main()
{
    int n,i,j,len,l,r ;
    scanf("%d",&n);
    ///dq -> (l,r);
    for(i=2;i<=n;i++)
    {
        scanf("%d",&len);
        dq.push_back({i,i+len-1});
        while(!dq.empty()&&dq.front().second<i)
        {
            dq.pop_front();
        }
        if(dq.empty())
        {
            printf("0 ");
        }
        else
        {
            printf("%d ",i-dq.front().first+1);
        }
    }
}
