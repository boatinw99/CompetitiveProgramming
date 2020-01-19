#include<bits/stdc++.h>
using namespace std ;
const int M = 1<<22 , bit = 21 ; 
int F[M],arr[M];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ; 
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        cin >> arr[i];
        F[arr[i]]=arr[i];
    }
    for(int i=0;i<=bit;i++)
    {
        for(int mask=0;mask<M;mask++)
        {
            if(mask&(1<<i))
            {
                F[mask]=max(F[mask^(1<<i)],F[mask]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout << (F[M-1^arr[i]]>0?F[M-1^arr[i]]:-1) << " " ;
    }
    return 0 ;
}