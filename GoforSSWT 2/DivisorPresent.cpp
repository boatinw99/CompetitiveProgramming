#include<bits/stdc++.h>
using namespace std ;
stack<int>st ;
main()
{
    int n,i ;
    scanf("%d",&n);
    for(i=1;i*i<n;i++)
    {
        if(n%i==0)printf("%d ",i),st.push(n/i);
    }
    if(i*i==n)printf("%d ",i);
    while(!st.empty())
    {
        printf("%d ",st.top());
        st.pop();
    }
}
