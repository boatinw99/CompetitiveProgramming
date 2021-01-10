#include<bits/stdc++.h>
using namespace std;
main()
{
    int a,b,c,i ;
    scanf("%d %d",&a,&b);
    a=a*8;
    for(i=0;i<b;i++)
    {
        scanf("%d",&c);
        if(c%2)
        {
            a-=c+1;
        }
        else a-=c;
    }
    if(a>=0)printf("YES");
    else printf("NO");
}
