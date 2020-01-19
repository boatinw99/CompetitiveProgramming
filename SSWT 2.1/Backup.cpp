#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 1e5+9 ;
set<pii> s1,s2;
int a[N];
main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n,k,i,j,ans=0 ;
    cin >> n >> k ;
    for(i=1;i<=n;i++)cin >> a[i] ;
    for(i=n;i>=2;i--)a[i]-=a[i-1];
    for(i=2;i<=n;i++)
    {
        s1.insert({i,a[i]}); ///sort by pos
        s2.insert({a[i],i}); ///sort by val
    }
    while(k--)
    {
        pii tmp = *s2.begin();
        s2.erase(tmp);
        auto it = s1.lower_bound({tmp.se,tmp.fi});
        ans+=tmp.fi;
        if(s2.empty())break;
        auto itend=s1.end();
        itend--;
        if(it==s1.begin())
        {
            auto it1=it;
            it1++;
            s2.erase({it1->se,it1->fi});
            s1.erase(it);
            s1.erase(it1);
        }
        else if(it==itend)
        {
            auto it1=it;
            it1--;
            s2.erase({it1->se,it1->fi});
            s1.erase(it);
            s1.erase(it1);
        }
        else
        {
            auto it1=it,it2=it;
            it1++,it2--;
            int x=it2->se,y=it1->se; ///2 it
            s1.erase(it);
            s2.erase({it2->se,it2->fi});
            s2.erase({it1->se,it1->fi});
            s1.erase(it1);
            s1.erase(it2);
            s1.insert({tmp.se,x+y-tmp.fi});
            s2.insert({x+y-tmp.fi,tmp.se});
        }
    }
    cout << ans ;
}
