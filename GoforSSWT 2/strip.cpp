#include<bits/stdc++.h>
using namespace std ;
struct P
{
    int pos,l,r,mul;
};
const int N = 40009,size=1e5+9;
pair<pair<int,int>,int> query[N/2];
vector<P> rec;
vector<P>::iterator it ;
int bi[size],ans[N/2];
bool sortx(P p1,P p2)
{
    return p1.pos<p2.pos;
}
void update(int i,int co)
{
    for(;i<size;i+=i&-i)bi[i]+=co;
}
int getsum(int i)
{
    int sum=0;
    for(;i;i-=i&-i)sum+=bi[i];
    return sum;
}
main()
{
    int n,m,k,a,b,c,d,i,j,x,y ;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        a++; b++; c++; d++;
        rec.push_back({a,b,d,1});
        rec.push_back({c+1,b,d,-1});
    }
    sort(rec.begin(),rec.end(),sortx);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&x,&y);
        x++; y++;
        query[i]={{x,y},i};
    }
    sort(query+1,query+1+m);
    it=rec.begin();
    for(i=1;i<=m;i++)
    {
        while(it!=rec.end()&&it->pos<=query[i].first.first)
        {
            update(it->l,it->mul);
            update(it->r+1,-it->mul);
            it++;
        }
        ans[query[i].second]=getsum(query[i].first.second);
        //printf("%d %d -> %d ans =%d\n\n",query[i].first.first,
           // query[i].first.second,query[i].second
           // ,ans[query[i].second]);
    }
    for(i=1;i<=m;i++)
    {
        printf("%d\n",ans[i]);
    }
}
