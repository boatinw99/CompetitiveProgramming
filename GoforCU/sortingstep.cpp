#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
int a[N];
int bi[N];
vector<pair<int,int> > v;
vector<pair<int,int> >::iterator it;
queue<int> q ;
void update(int i,int co)
{
    for(i;i<N;i+=i&-i)bi[i]+=co;
}
int getsum(int i)
{
    int x=0;
    for(i;i>0;i-=i&-i)x+=bi[i];
    return x;
}
main()
{
    int n,i,j,x;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        v.push_back({a[i],i});
    }
    sort(v.begin(),v.end(),greater<pair<int,int> >());
    q.push(v.begin()->second);
    int max1=0;
    for(it=v.begin()+1;it!=v.end();it++)
    {
        if(it->first!=(it-1)->first)
        {
            while(!q.empty())update(q.front(),1),q.pop();
        }
        max1=max(max1,getsum(it->second));
        q.push(it->second);
    }
    printf("%d",max1+1);
}
