#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
vector<pair<ll,pair<ll,ll> > >query;
vector<pair<ll,pair<ll,ll> > >::iterator it;
main()
{
    int Q,j;
    ll S,a,b,c,i;
    scanf("%d",&Q);
    for(j=1;j<=Q;j++)
    {
        scanf("%lld",&S);
        printf("Case #%d:\n",j);
        for(i=1;i<S/2;i++)
        {
            a=i*i;
            c=S-i;
            b=c*2;
            c=c*c-a;
            if(c%b==0)
            {
                b=c/b;
                if(b>i&&S-b-i>b)
                {
                    query.push_back({i,{b,S-b-i}});
                }
            }
        }
        if(query.empty())printf("-1\n");
        else
        {
            sort(query.begin(),query.end());
            for(it=query.begin();it!=query.end();it++)
            {
                printf("%lld %lld %lld\n",it->first,it->second.first
                       ,it->second.second);
            }
            query.clear();
        }
    }
}
