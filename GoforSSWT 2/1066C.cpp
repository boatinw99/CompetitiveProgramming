#include<bits/stdc++.h>
using namespace std ;
const int N = 200009;
pair<char,int> query[N];
deque<int> dq;
pair<int,int> ans[N];
main()
{
    int n,x,size,i;
    char c;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf(" %c %d",&c,&x);
        if(c=='L')
        {
            dq.push_front(x);
        }
        else if(c=='R')dq.push_back(x);
        query[i]={c,x};
    }
    size=dq.size();
    int j=0,l=0,r=0;
    while(!dq.empty())
    {
        x=dq.front();
        ans[x].first=j;
        ans[x].second=size-j-1;
        dq.pop_front();
        //printf("aa %d->%d %d\n",x,j,size-j-1);
        j++;
    }
    stack<int> st;
    for(i=n;i>=1;i--)
    {
        x=query[i].second;
        if(query[i].first=='L')
        {
            l++;
        }
        else if(query[i].first=='R')r++;
        else
        {
            st.push(min(ans[x].first-l,ans[x].second-r));
        }
    }
    while(!st.empty())
    {
        printf("%d\n",st.top());
        st.pop();
    }
}
