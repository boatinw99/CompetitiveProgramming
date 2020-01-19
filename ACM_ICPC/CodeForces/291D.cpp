#include<bits/stdc++.h>
using namespace std ;
const int N = 1e4+9 ; 
int n,k ;
int sum[N];
int process[N];
void comp()
{
    for(int i=1;i<=n;i++)
    {
        int x = (n-i)-sum[i] ; 
        if(sum[n-x]==x)
        {
            process[i]=n-x;
            sum[i]=n-i;
        }
        else process[i]=i,sum[i]+=sum[i];
    }   
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> k ;
    for(int i=1;i<n;i++)sum[i]=1;
    sum[n]=0;
    while(k--)
    {
        comp();
        for(int i=1;i<=n;i++)
        {
            cout << process[i] << " " ;
        }
        cout << '\n' ;
    }
    return 0 ;
}