#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+9;
struct query
{
    int c,a,b;
};
queue<query> q;
vector<int>key;
vector<int>::iterator it;
int bi[N],keysize ;
void update(int in,int co)
{
    for(;in<=keysize;in+=in&-in)bi[in]+=co;
}
int getsum(int in)
{
    int x=0;
    for(;in;in-=in&-in)x+=bi[in];
    return x;
}
string pr[6]={"sleep","eat","work","eat","work","eat"};
main()
{
    int n,m,l,r,x,y ;
    scanf("%d %d",&n,&m);
    while(m--)
    {
        scanf("%d",&y);
        if(y==1)
        {
            scanf("%d %d",&l,&r);
            q.push({y,l,r});
            key.push_back(l);
            key.push_back(r);
        }
        else
        {
            scanf("%d",&l);
            q.push({y,l,0});
            key.push_back(l);
        }
    }
    sort(key.begin(),key.end());
    keysize=key.size();
    int ans ;
    while(!q.empty())
    {
        x=q.front().c;
        l=q.front().a;
        r=q.front().b;
        q.pop();
        if(x==0)
        {
            ans=getsum
            (lower_bound(key.begin(),key.end(),l)-key.begin()+1);
            cout << pr[ans%6] << endl;
            continue ;
        }
        update(lower_bound(key.begin(),key.end(),l)-key.begin()+1,1);
        update(lower_bound(key.begin(),key.end(),r+1)-key.begin()+1,-1);


    }
}
