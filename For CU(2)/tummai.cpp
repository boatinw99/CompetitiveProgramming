#include<stdio.h>
int s[60001];
main()
{
    int a,jump,b,i,count=0,max,j ;
    scanf("%d %d",&a,&jump);
    for(i=0;i<a;i++)
    {
        scanf("%d",&s[i]);
    }
    b=s[0]+jump;
    for(i=0;b>=s[i];i++)count++;
    count--;
    for(i=1;i<a;i++)
    {
        
        if(s[i+count]<s[i]+jump)
        {
            b=s[i]+jump;
            for(j=i+count+1;s[j]<=b&&j<a;j++){count++;}
        }
    }
    printf("%d\n",count);
}
