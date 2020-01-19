#include<bits/stdc++.h>
using namespace std ;
int q[1009][1009];
main()
{
    int a,b,x,n,i,j ;
    scanf("%d %d %d",&n,&a,&b);
    if(a!=1&&b!=1)printf("NO");
    else if(a==1&&b==1&&n<=3&&n>=2)printf("NO");
    else
    {
        printf("YES\n");
        x=max(a,b);
        x=n-x;
        for(i=1;x>0;i++,x--)
        {
            q[i][i+1]++;
            q[i+1][i]++;
        }
        if(a<b)
        {
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                {
                    if(i!=j)
                    {
                        q[i][j]=q[i][j]^1;
                    }
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                printf("%d",q[i][j]);
            }
            printf("\n");
        }
    }
}
