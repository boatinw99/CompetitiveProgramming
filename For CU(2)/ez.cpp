#include<stdio.h>
main()
{
    int i,a,j,k,p;
    char s[250];
    for(i=0;i<20;i++)
    {
        k=0;
        scanf("%d ",&a);
            gets(s);

        if(s[0]!='0')printf("no\n");
        else
        {
            //if(a>4)printf("yes");
             if(s[1]=='2')
            {
                if(a==2)printf("yes");
                else if(a==3&&s[2]=='0')printf("no");
                else if(a==4&&s[3]=='2')printf("no");
                else printf("yes");
            }
            else if(s[1]=='0')
            {
                if(a==2)printf("no");
                else if(a==4&&s[2]=='0'&&s[3]=='0')printf("no");
                else if(a==4&&s[2]=='2'&&s[3]=='2')printf("no");
                else if(a==4&&s[2]=='1'&&s[3]=='1')printf("no");                
                else if(a>4&&s[2]=='2'&&s[3]=='2')
                {
                	for(p=4;p<a;p++)
                	{
                		if(s[p]!='1')k=99;
                		break;
					}
					if(k==99)printf("yes");
					else printf("no");
				}
				else 
				printf("yes");
            }
            else if(s[1]=='1')
            {
                if(a==2)printf("no");
                else if(a==3&&(s[2]=='1'||s[2]=='2'))printf("no");
                else if(a==4)
                {
                    if(s[2]=='0'&&s[3]=='0')printf("no");
                    else if(s[2]=='1'&&s[3]=='1')printf("no");
                    else if(s[2]=='1'&&s[3]=='2')printf("no");
                    else if(s[2]=='2'&&s[3]=='1')printf("no");
                    else if(s[2]=='2'&&s[3]=='2')printf("no");
                    else printf("yes");
                }
                else printf("yes");
            }
            printf("\n");
        }

    }
}
