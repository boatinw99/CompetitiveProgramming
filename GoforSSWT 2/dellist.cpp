#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 ;
vector<int> v[N],ansq[N];
vector<int> ::iterator it,it1 ;
set<pair<int,int> >  s[N];///val i,j
set<pair<int,int> > ::iterator its ;
deque<int> dq[N];///pos
main()
{
    int n,m,i,j,len,x,pos,y,T ;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&len);
        dq[i].push_back(i);
        for(j=1;j<=len;j++)
        {
            scanf("%d",&x);
            v[i].push_back(x);
            s[i].insert({x,i});
        }
    }
    while(m--)
    {
        scanf("%d %d %d",&T,&x,&y);
        if(T==1)
        {
            its=s[x].lower_bound(make_pair(y,0));
            while(its!=s[x].end()&&its->first==y)
            {
                ansq[its->second].push_back(y);
                s[x].erase(its++);
            }
        }
        else
        {
            ///DQ-> pos of list
            if(dq[x].size()>=dq[y].size())
            {
                while(!dq[y].empty())
                {
                    dq[x].push_back(dq[y].front());
                    dq[y].pop_front();
                }
            }
            else
            {
                while(!dq[x].empty())
                {
                    dq[y].push_front(dq[x].back());
                    dq[x].pop_back();
                }
                swap(dq[x],dq[y]);
            }
            ///SET
            if(s[x].size()>=s[y].size())
            {
                while(!s[y].empty())
                {
                    s[x].insert(*s[y].begin());
                    s[y].erase(s[y].begin());
                }
            }
            else
            {
                its=s[x].begin();
                while(!s[x].empty())
                {
                    s[y].insert(*s[x].begin());
                    s[x].erase(s[x].begin());
                }
                swap(s[x],s[y]);
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        sort(ansq[i].begin(),ansq[i].end());
    }
    for(i=1;i<=n;i++)
    {
        while(!dq[i].empty())
        {
            x=dq[i].front();
            for(it=v[x].begin();it!=v[x].end();it++)
            {
                it1=lower_bound
                (ansq[x].begin(),ansq[x].end(),*it);
                if(it1==ansq[x].end()||*it1!=*it)
                {
                    printf("%d\n",*it);
                }
            }
            dq[i].pop_front();
        }
    }
}
