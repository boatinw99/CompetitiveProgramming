#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
typedef pair<ll,ll> pll ;
#define fi first
#define se second 
const int N = 2e5+9 ; 
int A[N],B[N],n;
bool hd[N]; 
bool query(int x)
{
    memset(hd,0,sizeof hd);
    for(int i=1;i<=n;i++)hd[A[i]]++;
    for(int i=1;i<=x-1;i++)hd[B[i]]++;
    int now = 1 ; 
    for(int i=x;i<=n;i++)
    {
        if(hd[now])
        {
            hd[B[i]]++;
        }
        else return 0 ; 
        now++;
    }
    return 1 ; 
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        cin >> A[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin >> B[i]; 
    }
    int i = 1 ;
    for(i;B[i]!=1&&i<=n;i++);
    if(i<=n)
    {
        bool bl = 0 ; 
        for(int j=i+1;j<=n;j++)if(B[j]!=B[j-1]+1)bl++;
        if(bl==0)
        {
            for(int j=1;j<=n;j++)hd[A[j]]++;
            ///for(int j=1;j<i;j++)hd[B[j]]++;
            bool chk = 1 ; 
            int nxt = n-i+2 ; 
            ///printf("wtf %d \n",nxt);
            for(int j=1;j<i;j++)
            {
                if(hd[nxt])
                {
                    nxt++;
                    hd[B[j]]++;
                }
                else 
                {
                    chk = 0 ;
                    break;
                }
            }
            if(chk)
            {
                //printf("wtf \n");
                cout << i-1 << '\n' ; 
                return 0 ;
            }
        }
    }
    int l = 0 , r = n+1 ; 
    while(l+1<r)
    {
        int mid = l+r >> 1 ;
        bool ret = query(mid); 
        if(ret)r=mid;
        else l=mid ;
    }
    //printf("a %d %d %d\n",l,r,query(l));
    cout << r+n-1 << '\n' ; 
    return 0 ;
}