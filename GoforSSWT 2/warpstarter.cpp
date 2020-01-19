#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
typedef long long ll;
set<pair<int,int> > s;
set<pair<int,int> > ::iterator it,it1,it2 ;
vector<pair<int,int> > v;
ll now = 0;
bool sorty(pair<int,int> p1,pair<int,int> p2)
{
    return p1.second<p2.second;
}
void push(int i)
{
    int x=v[i].first,y=v[i].second ;
    it=s.lower_bound({x,y});
    if(s.empty());
    else if(it==s.begin())
    {
        now+=abs(y-it->second);
    }
    else
    {
        it1=it ; it1--;
        if(it==s.end())
        {
            now+=abs(y-it1->second);
        }
        else
        {
            if(y>=it->second&&y>=it1->second)
            {
                now+=1ll*(y-max(it->second,it1->second))*2;
            }
            else if(y<=it->second&&y<=it1->second)
            {
                now+=1ll*(min(it->second,it1->second)-y)*2;
            }
        }
    }
    s.insert({x,y});
}
void pop(int i)
{
    int x=v[i].first,y=v[i].second;
    it=s.lower_bound({x,y});
    if(s.empty());
    else if(it==s.begin())
    {
        it1=it;
        it1++;
        now-=abs(y-it1->second);
    }
    else
    {
        it2=it;
        it2++;
        if(it2==s.end())
        {
            it--;
            now-=abs(y-it->second);
            it++;
        }
        else
        {
            /// it1 | it | it2
            it1=it; it1++;
            it2=it; it2--;
            if(y>=it1->second&&y>=it2->second)
            {
                now-=1ll*(y-max(it1->second,it2->second))*2;
            }
            else if(y<=it1->second&&y<=it2->second)
            {
                now-=1ll*(min(it2->second,it1->second)-y)*2;
            }
        }
    }
    s.erase(it);
}
main()
{
    int n,k,i,j,x,y,l=0,r=0 ;
    ll ans=LONG_LONG_MAX ;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&x,&y);
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),sorty);
    for(;r<n;r++)
    {
        push(r);
        while(v[r+1].second==v[r].second&&r<n)
        {
            push(r);
            r++;
        }
        while(r-l+1>k)
        {
            pop(l);
            l++;
        }
        while(v[l+1].second==v[l].second&&l<r)
        {
            pop(l);
            l++;
        }
        if(r-l+1==k)
        {
           // printf("a %d %d | %lld %d\n",l,r,now,
                //   s.rbegin()->first-s.begin()->first);
            ans=min(ans,now+s.rbegin()->first-s.begin()->first);
        }
    }
    printf("%lld",ans);
}
