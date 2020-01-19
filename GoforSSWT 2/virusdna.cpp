#include<bits/stdc++.h>
using namespace std ;
const int N =  1e6+60000;
int size;
int del[N];
int pos[N];
int junk[N];
void updatepos(int i,int co)
{
    for(;i<=size;i+=i&-i)pos[i]+=co;
}
void updatejunk(int i,int co)
{
    for(;i<=size;i+=i&-i)junk[i]+=co;
}
void updatedel(int i,int co)
{
    for(;i<=size;i+=i&-i)del[i]+=co;
}
int posnow(int i)
{
    int sum=0;
    for(;i;i-=i&-i)sum+=pos[i];
    return sum;
}
int junknow(int i)
{
    int sum=0;
    for(;i;i-=i&-i)sum+=junk[i];
    return sum;
}
int delq(int i)
{
    int sum=0;
    for(;i;i-=i&-i)sum+=del[i];
    return sum;
}
int findpos(int in)
{
    int w=0,j=size/2;
    for(;j;j/=2)
    {
        if(pos[w+j]<in)
        {
            in-=pos[w+j];
            w+=j;
        }
    }
    return w+1;
}
main()
{
    int n,m,i,j,x,k1,k2,y,x1 ;
    char c;
    scanf("%d %d",&n,&m);
    n++;
    for(size=1;size<n;size*=2);
    for(i=1;i<=n;i++)
    {
        updatepos(i,1);
    }
    for(i=1;i<=m;i++)
    {
        cin >> c;
        if(c=='d')///delete
        {
            cin >> x;
            x++;
            y=findpos(x);
            if(posnow(y)!=x)
            {
                //printf("isjunk %d\n",y);
                updatepos(y,-1);
                updatejunk(y,-1);
            }
            else
            {
                //printf("notjunk %d\n",y);
                updatepos(y,-1);
                updatedel(y+1,1);
            }
        }
        if(c=='g')
        {
            cin >> x;
            x++; x++;
            y=findpos(x);
            updatepos(y,1);
            updatejunk(y,1);
            //printf("there %d\n",y);
        }
        if(c=='i')
        {
            cin>>k1>>k2;
           // while(k1==-1);
            y=junknow(k2)-junknow(k1);
            x=delq(k2);
            x1=delq(k1);
            printf("%d\n",y+x-x1);
        }
    }
}
