#include<bits/stdc++.h>
using namespace std ; 
typedef long long ll ; 
typedef pair<int,int> pii ;
#define fi first
#define se second 
const int N = 1e4+9 , crange = 5001 ;
vector<pair<int,pii>> ver,hor ;
vector<int> edline[N]; 
int f[N];
void update(int idx,int val)
{
    for(;idx<N;idx+=idx&-idx)
    {
        f[idx]+=val;
    }
}
int getsum(int idx)
{
    int cnt = 0 ;
    for(;idx;idx-=idx&-idx)
    {
        cnt+=f[idx];
    }
    return cnt ;
}
int main()
{
    int n ;
    cin >> n ;
    for(int i=1,x1,y1,x2,y2 ;i<=n;i++)
    {
        cin >> x1 >> y1 >> x2 >> y2 ;
        x1+=crange;
        x2+=crange;
        y1+=crange;
        y2+=crange;
        if(x1>x2)swap(x1,x2);
        if(y1>y2)swap(y1,y2);
        if(x1==x2) //hor
        {
            hor.push_back({x1,{y1,y2}});
        }
        else ver.push_back({y1,{x1,x2}});
    }
    sort(hor.begin(),hor.end());
    ll ans = 0 ;
    for(int i=0,x,y1,y2 ;i<hor.size();i++)
    {
        x=hor[i].fi;
        y1=hor[i].se.fi;
        y2=hor[i].se.se;
        for(auto it:ver)
        {
            if(it.se.fi<=x&&x<it.se.se)
            {
                update(it.fi,1);
                edline[it.se.se].push_back(it.fi);
            }
        }
        int r = x ;
        for(int j=i+1;j<hor.size();j++)
        {
            while(r<hor[j].fi)
            {
                while(!edline[r].empty())
                {
                    update(edline[r].back(),-1);
                    edline[r].pop_back();
                }
                r++;
            }
            int R = min(y2,hor[j].se.se),L=max(y1,hor[j].se.fi);
            if(L<=R)
            {
                int cnt = getsum(R)-getsum(L-1);
                ans+=cnt*(cnt-1)/2;
            }
        }
        while(r<N)
        {
            while(!edline[r].empty())
            {
                update(edline[r].back(),-1);
                edline[r].pop_back();
            }
            r++;
        }
    }
    cout << ans << '\n' ;
    return 0 ;
}