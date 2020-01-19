#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second 
const int N = 4e5+9 , mod = 1e9+7 ; 
int n,k ; 
int a[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> k ; 
    for(int i=2;i<=n+1;i++)
    {
        char c ;
        cin >> c ;
        a[i] = c-'0' ;
    }
    ///start i = 2 end n+1 ;  
    int last = n+1 ;
    for(int i=2;i<last&&i+k<=n+1;i++)
    {
        if(a[i]<a[i+k])
        {
            int sum = 1 ; 
            for(int j=i+k-1;j>=1&&sum==1;j--)
            {
                a[j]++;
                if(a[j]==10)a[j]=0;
                else sum=0;
            }
            break ; 
        }
    } 
    int st=2 ;
    if(a[1]!=0)st = 1 ;
    cout << n-st+2 << '\n' ; 
    for(int i=st;i<=n+1;i++)
    {
        cout << a[i];
        a[i+k]=a[i];
    }
    return 0 ;
}