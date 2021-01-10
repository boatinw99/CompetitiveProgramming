#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pll ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
const ll INF = 1e18 ; 
const int N = 2e5+9 , inf = 2e9 , mod = 1e9+7 ;
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    int k1=0,k2=0;
    int sum1=0,sum2=0;  
    cin >> n ;
    for(int i=1;i<=n/2;i++)
    {
        char c ;
        cin >> c ;
        if(c=='?')k1++;
        else sum1+=c-'0';
    }
    for(int i=1;i<=n/2;i++)
    {
        char c ;
        cin >> c ;
        if(c=='?')k2++;
        else sum2+=c-'0';
    }
    //printf("wtf %d %d %d %d \n",k1,k2,sum1,sum2);
    if(sum1<sum2)swap(sum1,sum2),swap(k1,k2);
    if(sum1==sum2)
    {
        if(k1!=k2)
        {
            cout << "Monocarp" << '\n' ;
        }
        else cout << "Bicarp" << '\n' ;
        return 0 ;
    }
    if(k1>k2)
    {
        cout << "Monocarp" << '\n' ;
        return 0 ;
    }
    while(k1>0&&k2>0)
    {
        k1--;
        k2--;
    }
    int turn = k2/2 ;
    if(sum1-sum2==turn*9)
    {
        sum2=sum1;
    }
    if(sum1==sum2)
    {
        cout << "Bicarp" << '\n' ;  
    }
    else cout << "Monocarp" << '\n' ;
    return 0 ;
}