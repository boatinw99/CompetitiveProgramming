#include<bits/stdc++.h>
using namespace std ;
const int N = 1e6+9;
char A[N],B[N];
int pat[N];
string s;
string d="No COI Secret Code" ;
deque<pair<char,int> > dq;
main()
{
    int m,n,w,i,j ;
    scanf("%d",&w);
    while(w--)
    {
        scanf("%s %s",&A,&B);
        n=strlen(A);
        m=strlen(B);
        for(i=1,j=0;i<m;)
        {
            if(B[i]==A[j])
            {
                pat[i]=j+1;
                i++; j++;
            }
            else
            {
                if(j<=0)pat[i++]=0;
                else j=pat[j-1];
            }
        }
        for(i=0,j=0;i<n;)
        {
            if(dq.empty())dq.push_back({A[i],A[i]==B[j]}),j=(A[i++]==B[0]);
            else
            {
                if(A[i]==B[j])
                {
                    dq.push_back({A[i],j+1});
                    i++;j++;
                }
                else
                {
                    if(j==0)dq.push_back({A[i],0}),i++;
                    else
                    {
                        j=pat[j-1];
                    }
                }
            }
            if(j==m)
            {
                for(int k=0;k<m;k++)
                {
                    dq.pop_back();
                }
                j=(dq.empty())?0:dq.back().second;
            }
        }
        char c;
        if(dq.empty())s+=d;
        while(!dq.empty())
        {
            c=dq.front().first;
            s.push_back(c);
            dq.pop_front();
        }
        s.push_back('\n');
    }
    cout << s;
}
