#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+9 ;
struct query
{
    int type,px,py ;
};
query Q[N];
set<pair<int,int> > s[N];
set<pair<int,int> > ::iterator its;
vector<int> key,qkey;
vector<int>::iterator it;
inline void add(int in,pair<int,int> P)
{
    for(;in;in-=in&-in)s[in].insert(P);
}
inline void remove(int in,pair<int,int> P)
{
    for(;in;in-=in&-in)s[in].erase(P);
}
inline pair<int,int> findpoint(int in,pair<int,int> P)
{
    int x=INT_MAX,y=0;
    P.first++;
    for(;in<N;in+=in&-in)
    {
        its=s[in].upper_bound(P);
        if(its!=s[in].end())
        {
            if(its->first<x)
            {
                x=its->first; y=its->second;
            }
        }
    }
    return {x,y};
}
main()
{
    int n,i,j,x,y ;
    char c[9];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s %d %d",&c,&x,&y);
        if(c[0]=='a')Q[i]={1,x,y};
        else if(c[0]=='r')Q[i]={2,x,y};
        else Q[i]={3,x,y};
        key.push_back(y);
    }
    key.push_back(-1);
    sort(key.begin(),key.end());
    /*qkey.push_back();
    for(it=key.begin()+1;it!=key.end();it++)
    {

    }*/
    pair<int,int> P;
    for(i=1;i<=n;i++)
    {
        x=Q[i].px; y=Q[i].py;
        if(Q[i].type==1)///add
        {
            it=lower_bound(key.begin(),key.end(),y);
            j=it-key.begin()+1;
            add(j,{x,y});
        }
        else if(Q[i].type==2)
        {
            it=lower_bound(key.begin(),key.end(),y);
            j=it-key.begin()+1;
            remove(j,{x,y});
        }
        else
        {
            it=lower_bound(key.begin(),key.end(),y+1);
            j=it-key.begin()+1;
            P=findpoint(j,{x,y});
            if(P.first<INT_MAX)
            {
                printf("%d %d",P.first,P.second);
            }
            else printf("-1");
            printf("\n");
        }
    }
}
