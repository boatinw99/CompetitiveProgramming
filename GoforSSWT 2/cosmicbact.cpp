#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define f first
#define s second
const int N = 1e5+9 ;
vector<pair<pll,int> > vx;
vector<pair<pll,pair<ll,int> > >ans;
vector<pair<pll,pair<ll,int> > > ::iterator it1 ;
vector<pair<pll,int> > ::iterator it;
ll pr[N];
main()
{
    int n,i,j,pos1,pos,posleft;
    ll x,y,x1,y1,L,path,val ;
    scanf("%d %lld",&n,&L);
    for(i=1;i<=n;i++)
    {
        scanf("%lld %lld",&x,&y);
        vx.push_back({{x,y+i},i});
    }
    sort(vx.begin(),vx.end());
    ans.push_back({{vx.begin()->f.f,vx.begin()->f.s},
                  {0,vx.begin()->s}});
    ///x y | l posans
    for(it=vx.begin()+1;it!=vx.end();it++)
    {
        it1=ans.end()-1;
        x=it1->f.f; y=it1->f.s; posleft=it1->s.f; pos=it1->s.s;
        x1=it->f.f; y1=it->f.s; pos1=it->s;
        val=x1-x+y;
        if(val+(pos1<pos)<=y1)continue;
        while(!ans.empty())
        {
            x=it1->f.f; y=it1->f.s; posleft=it1->s.f; pos=it1->s.s;
            if(x1-x+y1+(pos<pos1)>y)
            {
                path=x1-y+y1;
                if((path-x)%2==0)
                {
                    path=path+x >> 1;
                    if(pos1<pos)
                    {
                        path--;
                    }
                }
                else
                {
                    path=path+x >> 1;
                }
                ans.push_back({{x1,y1},{path+1,pos1}});
                break ;
            }
            it1--;
            ans.pop_back();
        }
        if(ans.empty())
        {
            ans.push_back({{x1,y1},{0,pos1}});
        }
    }
    ans.push_back({{0,0},{L+1,0}});
    for(it1=ans.begin();(it1+1)!=ans.end();it1++)
    {
        pr[it1->s.s]+=(it1+1)->s.f-it1->s.f;
        //printf("%lld %lld|%d->%d\n",it1->f.f,it1->f.s,it1->s.f,it1->s.s);
    }
    for(i=1;i<=n;i++)
    {
        printf("%lld\n",pr[i]);
    }
}
