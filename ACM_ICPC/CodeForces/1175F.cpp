#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 3e5+9 , PB = 98765431 ;
ll P[N],H[N],chk[N];
int A[N],n,ans ;
ll gethash(int l,int r)
{
    return H[r]-H[l-1];
}
void precomp()
{
    P[0]=1;
    for(int i=1;i<N;i++)
    {
        P[i]=P[i-1]*PB ;
        chk[i]=chk[i-1]+P[i];
    }
    for(int i=1;i<=n;i++)
    {
        H[i]=H[i-1]+P[A[i]];
    }
}
void getans()
{
    int i,mx=1; 
    for(i=1;i<=n&&A[i]!=1;i++);
    for(i++;i<=n;i++)
    {
        if(A[i]==1)
        {
            mx=1;
            continue ; 
        }
        mx=max(mx,A[i]);
        if(gethash(i-mx+1,i)==chk[mx])ans++;
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        cin >> A[i] ;
        if(A[i]==1)ans++;
    }
    precomp();
    getans();
    reverse(A+1,A+1+n);
    precomp();
    getans();
    cout << ans << '\n' ; 
}