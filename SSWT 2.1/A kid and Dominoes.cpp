#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9,MAX=1e9 ;
int a[N],range[N];
bool vst[N];
main()
{
    int n,i,j,m,a1,a2,a3,a4,b1,b2,b3,b4,b5,a5 ;
    cin >> n ;
    a[0]=a[n+1]=MAX ;
    for(i=1;i<=n;i++)
    {
        cin >> a[i] ;
    }
    for(i=1;i<=n;i++)
    {
        if(a[i-1]<a[i])range[i]=range[i-1]+1;
        else range[i]=1;
    }
    int ans=1;
    for(i=n;i>=1;i--)
    {
        b2=i-range[i]+1;
        b1=b2+1;
        b3=b2-1;
        b4=b3-1;
        b5=b3-range[b3];
        if(b2==1)
        {
            ans=max(ans,i);
            break;
        }
        a1=a[b1],a2=a[b2],a3=a[b3],a4=a[b4],a5=a[b5];
        ans=max(ans,range[i]);
        if(a4>a3)
        {
            if(a2!=1)ans=max(ans,range[i]+1);
            if(a3<a1)ans=max(ans,range[i]+1);
            if(a4<a1&&a[b4-1]<a2)ans=max(ans,range[i]+range[b4]+1);
            if(a[b4-1]<a2)ans=max(ans,range[b2]+range[b4]+1);
            if(a3<a1&&a4<a1)ans=max(ans,range[i]+2);
        }
        else
        {
            //printf("a %d\n",i);
            if(b5>0&&a5<a1&&a[b5-1]<a2&&a3<a5)
                ans=max(ans,range[i]+range[a3]+range[a5]);
            if(b5>0&&a[b5-1]<a2&&a3<a5)ans=max(ans,range[a3]+range[5]+1);
            if(a3<a1&&a1!=MAX)ans=max(ans,range[b3]+1);
            if(a1>a3&&a1-a3>1&&a3!=n)ans=max(ans,range[i]+range[b3]);
            if(a2>a4)ans=max(ans,range[b3]+1);
            if(a2>a4&&a2-a4>1)ans=max(ans,range[i]+range[b3]);
            if(a3<a1&&a4<a2)ans=max(ans,range[i]+range[b3]);
        }
        //i=i-range[i];
    }
    cout << ans ;
}
