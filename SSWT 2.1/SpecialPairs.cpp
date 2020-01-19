#include<bits/stdc++.h>
using namespace std ;
const int N  = 1e5+9 , M = 1<<21 ;
int mask[M],a[N];
int main()
{
    int T,n,i,j ;
    cin >> T ;
    while(T--)
    {
        cin >> n ;
        memset(mask,0,sizeof mask);
        for(i=1;i<=n;i++)
        {
            cin >> a[i] ;
            mask[a[i]]++;
        }
        for(int bits=1;bits<M;bits<<=1)
        {
            for(j=0;j<M;j++)
            {
                if(mask[j]&&(j&bits)==0)mask[j+bits]+=mask[j];
            }
        }
        long long ans = 0 ;
        for(i=1;i<=n;i++)
        {
            int tmp = M-1^a[i];
            ans+=mask[tmp];
        }
        cout << ans << '\n' ;
    }
}
