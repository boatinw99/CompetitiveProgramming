#include<bits/stdc++.h>
using namespace std ;
const int N = 1e6+9,MAX = 4e6+9 , MXBIT = 22 , M = 1<<MXBIT;
int mask[M],a[N];
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j ;
    cin >> n ;
    for(i=1;i<=n;i++)
    {
        cin >> a[i] ;
        mask[a[i]]=a[i] ;
    }
    for(int bits=1;bits<M;bits<<=1)
    {
        for(i=0;i<M;i++)
        {
            if(mask[i]&&(i&bits)==0)
            {
                mask[i+bits]=mask[i];
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        int y = (M-1)^a[i];
        cout << (mask[y]?mask[y]:-1) << " ";
    }
}
