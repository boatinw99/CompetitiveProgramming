#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
priority_queue<pair<int,int> > NMS; ///Mana , index
priority_queue<pair<pair<int,int>,pair<int,int> > > RMS;
///Mana,half-life,index-first,index-next,
main()
{
    int n,i,j,x,h,mp,half,index ;
    char c;
    scanf("%d",&n);
    ll ans=0,max1 ;
    for(i=1;i<=n;i++)
    {
        scanf(" %c",&c);
        if(c=='c')
        {
            scanf(" %c",&c);
            if(c=='n')scanf("%d",&x),NMS.push({x,-i});
            else
            {
                scanf("%d %d",&x,&h);
                RMS.push({{x,h},{-i,-i-h}});
            }
        }
        if(c=='u')
        {
            while(!RMS.empty()&&RMS.top().second.second*-1<=i)
            {
                mp=RMS.top().first.first;
                h=RMS.top().first.second;
                j=RMS.top().second.first ;
                if(mp>1)
                {
                    RMS.push({{mp/2,h},{j,
                        RMS.top().second.second-h}});
                }
                RMS.pop();
            }
            if(!NMS.empty()&&RMS.empty())
            {
                max1=NMS.top().first;
                index=NMS.top().second*-1;
                ans+=max1;
                NMS.pop();
            }
            else if(!RMS.empty()&&NMS.empty())
            {
                ans+=RMS.top().first.first;
                RMS.pop();
            }
            else if(!RMS.empty()&&!NMS.empty())
            {
                max1=NMS.top().first;
                index=NMS.top().second*-1;
                if(max1>RMS.top().first.first)
                {
                    ans+=max1;
                    NMS.pop();
                }
                else if(max1<RMS.top().first.first)
                {
                    ans+=RMS.top().first.first ;
                    RMS.pop();
                }
                else
                {
                   ans+=max1;
                   if(index<RMS.top().second.first*-1)NMS.pop();
                   else RMS.pop();
                }
            }
        }
    }
    int size=0;
    while(!RMS.empty())
    {
        if(RMS.top().second.second*-1>n)
        {
            size++;
            RMS.pop();
            continue;
        }
        mp=RMS.top().first.first;
        h=RMS.top().first.second;
        j=RMS.top().second.first ;
        if(mp>1)
        {
            RMS.push({{mp/2,h},{j,
            RMS.top().second.second-h}});
        }
        RMS.pop();
    }
    printf("%lld\n%d",ans,size+NMS.size());
}
