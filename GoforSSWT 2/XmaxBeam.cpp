#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
pair<int,int> a[N];
deque<pair<int,int> > dqmax,dqmin ;
int l,r ;
main()
{
    int Q,x,y,i,j,n,H;
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%d %d",&n,&H);
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&a[i].first,&a[i].second);
        }
        sort(a+1,a+1+n);
        l=-1; r=1e6+9;
        while(l+1<r)
        {
            int mid=l+r >> 1;
            bool b=0;
            for(i=1;i<=n;i++)
            {
                x=a[i].first; y=a[i].second;
                while(!dqmax.empty()&&x-dqmax.front().first>mid)
                    dqmax.pop_front();
                while(!dqmin.empty()&&x-dqmin.front().first>mid)
                    dqmin.pop_front();
                while(!dqmax.empty()&&dqmax.back().second<=y)
                    dqmax.pop_back();
                while(!dqmin.empty()&&dqmin.back().second>=y)
                    dqmin.pop_back();
                dqmax.push_back({x,y});
                dqmin.push_back({x,y});
                if(!dqmax.empty()&&!dqmin.empty()
                   &&dqmax.front().second-dqmin.front().second>=H)
                {
                    b++;
                    break;
                }
            }
            if(b)r=mid;
            else l=mid;
            while(!dqmin.empty())dqmin.pop_back();
            while(!dqmax.empty())dqmax.pop_back();
        }
        printf("%d\n",(r>1e6)?(-1):r);
    }
}
