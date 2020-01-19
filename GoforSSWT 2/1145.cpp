#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const ll pb = 98765431 ; ///prime base
const int N = 59;
ll p[256];
char S[4][N];
void change()
{
    int i,j ;
    for(i=0;i<4;i++)
        for(j=0;j<strlen(S[i]);j++)if(S[i][j]<'a')S[i][j]+='a'-'A';
}
int finds(ll hash1,int mid)
{
    int i,j;
    ll hash=0,sub=1;
    int x=0;
    for(i=1;i<4;i++)
    {
        hash=0; sub=1 ;
        if(strlen(S[i])<mid-1)continue ;
        for(j=0;j<mid;j++)
        {
            hash+=p[S[i][j]];
            hash*=pb;
            sub*=pb;
        }
        if(hash==hash1)
        {
            //printf("aa %d || \n",i);
            x++;continue;
        }
        for(j=mid;j<strlen(S[i]);j++)
        {
            hash-=p[S[i][j-mid]]*sub;
            hash+=p[S[i][j]];
            hash*=pb;
            if(hash==hash1)
            {
                x++;
                //printf("aa cc %d || %d -> %lld %d\n",i,j,hash1,mid);
                break;
            }
        }
    }
    //printf("dddd %d\n",x);
    return x;
}
int finds1(ll hash1,int mid)
{
    int i,j;
    ll hash=0,sub=1;
    int x=0;
    for(i=2;i<4;i++)
    {
        hash=0; sub=1 ;
        if(strlen(S[i])<mid-1)continue ;
        for(j=0;j<mid;j++)
        {
            hash+=p[S[i][j]];
            hash*=pb;
            sub*=pb;
        }
        if(hash==hash1)
        {
            //printf("aa %d || \n",i);
            x++;continue;
        }
        for(j=mid;j<strlen(S[i]);j++)
        {
            hash-=p[S[i][j-mid]]*sub;
            hash+=p[S[i][j]];
            hash*=pb;
            if(hash==hash1)
            {
                x++;
                //printf("aa cc %d || %d -> %lld %d\n",i,j,hash1,mid);
                break;
            }
        }
    }
    //printf("dddd %d\n",x);
    return x;
}
main()
{
    int i,j,l=0,r=51,x,st,k ;
    string ans,temp,ans1 ;
    ll hash=0 ;
    scanf("%s%s%s%s",&S[0],&S[1],&S[2],&S[3]);
    change();
    p[0]=1;
    for(i=1;i<256;i++)p[i]=p[i-1]*pb,ans+="a",ans1+="a";
    r=strlen(S[0])+1;
    while(l+1<r)
    {
        int mid=l+r>>1;
        bool b=0;
        //printf("%d %d %d\n",l,mid,r);
        ll sub=1;
        hash=0;
        for(i=0;i<mid;i++)
        {
            hash+=p[S[0][i]];
            hash*=pb;
            sub*=pb;
        }
        x=finds(hash,mid);
        if(x>=2)
        {
            ans="";
            for(i=0;i<mid;i++)ans+=S[0][i];
            b=1;
        }
        for(i=mid;i<strlen(S[0]);i++)
        {
            hash-=p[S[0][i-mid]]*sub;
            hash+=p[S[0][i]];
            hash*=pb;
            x=finds(hash,mid);
            if(x>=2&&b==0)
            {
                ans="";
                for(k=i-mid+1;k<=i;k++)
                {
                    ans+=S[0][k];
                }
                b++;
            }
            else if(x>=2)
            {
                temp="";
                for(k=i-mid+1;k<=i;k++)
                {
                    temp+=S[0][k];
                }
                if(temp<ans)ans=temp;
            }
        }
        if(b==1)l=mid;
        else r=mid;
    }
    l=0; r=strlen(S[1])+1;
    while(l+1<r)
    {
        int mid=l+r>>1;
        bool b=0;
        ll sub=1;
        hash=0;
        for(i=0;i<mid;i++)
        {
            hash+=p[S[1][i]];
            hash*=pb;
            sub*=pb;
        }
        x=finds1(hash,mid);
        if(x>=2)
        {
            ans1="";
            for(i=0;i<mid;i++)ans1+=S[1][i];
            b=1;
        }
        for(i=mid;i<strlen(S[1]);i++)
        {
            hash-=p[S[1][i-mid]]*sub;
            hash+=p[S[1][i]];
            hash*=pb;
            x=finds1(hash,mid);
            if(x>=2&&b==0)
            {
                ans1="";
                for(k=i-mid+1;k<=i;k++)
                {
                    ans1+=S[1][k];
                }
                b++;
            }
            else if(x>=2)
            {
                temp="";
                for(k=i-mid+1;k<=i;k++)
                {
                    temp+=S[1][k];
                }
                if(temp<ans1)ans1=temp;
            }
        }
        if(b==1)l=mid;
        else r=mid;
    }
    if(ans.size()>200&&ans1.size()>200);
    else if(ans.size()>200)
    {
        cout << ans1 ;
    }
    else if(ans1.size()>200)
    {
        cout << ans ;
    }
    else if(ans.size()<ans1.size())
    {
        cout << ans1;
    }
    else if(ans.size()>ans1.size())
    {
        cout << ans ;
    }
    else
    {
        cout << min(ans,ans1);
    }
}
