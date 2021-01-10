#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
const int D = 509 , S = 5009 , N = D*S ;
struct state 
{
    int rem,sum,lptr;
}q[N];
bool vst[D][S];
void trace_back(int idx)
{
    if(idx==0)return ; 
    trace_back(q[idx].lptr);
    cout << q[idx].sum-q[q[idx].lptr].sum ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int d,s ; 
    cin >> d >> s ;
    int l=0,r=0 ;
    vst[0][0]++;
    while(l<=r)
    {
        if(q[l].rem==0&&q[l].sum==s)break;
        for(int i=0;i<=9;i++)
        {
            if(!vst[(q[l].rem*10+i)%d][q[l].sum+i]&&q[l].sum+i<=s)
            {
                q[++r]={(q[l].rem*10+i)%d,q[l].sum+i,l};
                vst[(q[l].rem*10+i)%d][q[l].sum+i]++;
            }
        }
        l++;
    }
    if(!vst[0][s])
    {
        cout << "-1" << '\n' ;
    }
    else trace_back(l);
    return 0 ;
}