#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
int a[N];
int dis[N],n,k;
deque<pair<int,int> > dq;
void push(int x,int i)
{
    if(!dq.empty()&&dq.front().second<=i-(n-k-1))
    {
        dq.pop_front();
    }
    while(!dq.empty()&&dq.back().first<=x)
    {
        dq.pop_back();
    }
    dq.push_back({x,i});

}
main()
{
    int i,j ;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf(" %d",&a[i]);
    }
    for(i=1;i<n;i++)dis[i]=a[i+1]-a[i];
    int min1=INT_MAX;
    for(i=1;i<n;i++)
    {
        push(dis[i],i);
        if(i>=n-k-1)
        {
            min1=min(min1,dq.front().first);
        }
    }
    printf("%d",min1);
}
