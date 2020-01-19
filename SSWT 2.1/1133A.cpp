#include<bits/stdc++.h>
using namespace std ;
char s[10],t[10];
main()
{
    int i,j;
    ios::sync_with_stdio(0),cin.tie(0);
    for(i=1;i<=5;i++)cin >> s[i];
    for(i=1;i<=5;i++)cin >> t[i];
    int sum1=0,sum2=0,sum3=0,sum4=0;
    for(i=1;i<=2;i++)
    {
        sum1=sum1*10+(s[i]-'0');
        sum2=sum2*10+(t[i]-'0');
        sum3=sum3*10+(s[i+3]-'0');
        sum4=sum4*10+(t[i+3]-'0');
    }
    int times=((sum1+sum2)*60+sum3+sum4)/2;
    int hr=(times/60),mn=(times)%60;
    if(hr<10)
    {
        printf("0%d",hr);
    }
    else printf("%d",hr);
    printf(":");
    if(mn<10)printf("0%d",mn);
    else printf("%d",mn);

}
