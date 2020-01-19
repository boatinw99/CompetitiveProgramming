#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
char q[10] ;
int min1=9999,k=0;
int Swop2(int i,string s,int count)
{
    string t=s,u=s;
    if(count>=min1)
    {
    return 0 ;
    }
    if(s=="0123")
    {
        if(count<min1)min1=count ;
        return 0;
    }
    if(m.find(s)==m.end()||count<m[s])
    {
        m[s]=count;
    }
    if(i==3)
    {
        t[3]=t[1];
        t[1]='0';
        if((m.find(t)!=m.end()&&m[t]>count+1)||m.find(t)==m.end())
        Swop2(1,t,count+1);
        u[3]=u[2];
        u[2]='0';
        if((m.find(u)!=m.end()&&m[u]>count+1)||m.find(u)==m.end())
        Swop2(2,u,count+1);
    }
    else if(i==2)
    {
        t[2]=t[3];
        t[3]='0';
        if((m.find(t)!=m.end()&&m[t]>count+1)||m.find(t)==m.end())
        Swop2(3,t,count+1);
        u[2]=u[0];
        u[0]='0';
        if((m.find(u)!=m.end()&&m[u]>count+1)||m.find(u)==m.end())
        Swop2(0,u,count+1);
    }
    else if(i==1)
    {
        t[1]=t[0];
        t[0]='0';
        if((m.find(t)!=m.end()&&m[t]>count+1)||m.find(t)==m.end())
        Swop2(0,t,count+1);
        u[1]=u[3];
        u[3]='0';
        if((m.find(u)!=m.end()&&m[u]>count+1)||m.find(u)==m.end())
        Swop2(3,u,count+1);
    }
    else if(i==0)
    {
        t[0]=t[1];
        t[1]='0';
        if((m.find(t)!=m.end()&&m[t]>count+1)||m.find(t)==m.end())
        Swop2(1,t,count+1);
        u[0]=u[2];
        u[2]='0';
        if((m.find(u)!=m.end()&&m[u]>count+1)||m.find(u)==m.end())
        Swop2(2,u,count+1);
    }
}
///2->3
int Swop3(int i,string s,int count)
{
	string t=s,u=s,v=s,w=s;
    cout << s << endl ;
    if(count>=min1)
    {
    return 0 ;
    } 
    if(s=="012345678")
    {
        if(count<min1){min1=count;}
        return 0;
    }
    if(m.find(s)==m.end()||count<m[s])
    {
        m[s]=count;
    }
    if(i==0)
    {
        t[0]=t[1];
        t[1]='0';
        if((m.find(t)!=m.end()&&m[t]>count+1)||m.find(t)==m.end())
        Swop3(1,t,count+1);
        u[0]=u[3];
        u[3]='0';
        if((m.find(u)!=m.end()&&m[u]>count+1)||m.find(u)==m.end())
        Swop3(3,u,count+1);
    }
    else if(i==1)
    {
        t[1]=t[0];
        t[0]='0';
         if((m.find(t)!=m.end()&&m[t]>count+1)||m.find(t)==m.end())
        Swop3(0,t,count+1);
        u[1]=u[2];
        u[2]='0';
        if((m.find(u)!=m.end()&&m[u]>count+1)||m.find(u)==m.end())
        Swop3(2,u,count+1);
        v[1]=v[4];
        v[4]='0';
        if((m.find(v)!=m.end()&&m[v]>count+1)||m.find(v)==m.end())
        Swop3(4,v,count+1);
    }
    else if(i==2)
    {
        t[2]=t[1];
        t[1]='0';
         if((m.find(t)!=m.end()&&m[t]>count+1)||m.find(t)==m.end())
        Swop3(1,t,count+1);
        u[2]=u[5];
        u[5]='0';
        if((m.find(u)!=m.end()&&m[u]>count+1)||m.find(u)==m.end())
        Swop3(5,u,count+1);
    }
    else if(i==3)
    {
        t[3]=t[0];
        t[0]='0';
         if((m.find(t)!=m.end()&&m[t]>count+1)||m.find(t)==m.end())
        Swop3(0,t,count+1);
        u[3]=u[4];
        u[4]='0';
        if((m.find(u)!=m.end()&&m[u]>count+1)||m.find(u)==m.end())
        Swop3(4,u,count+1);
        v[3]=v[6];
        v[6]='0';
          if((m.find(v)!=m.end()&&m[v]>count+1)||m.find(v)==m.end())
        Swop3(6,v,count+1);
    }
    else if(i==4)
    {
        t[4]=t[1];
        t[1]='0';
         if((m.find(t)!=m.end()&&m[t]>count+1)||m.find(t)==m.end())
        Swop3(1,t,count+1);
        u[4]=u[3];
        u[3]='0';
        if((m.find(u)!=m.end()&&m[u]>count+1)||m.find(u)==m.end())
        Swop3(3,u,count+1);
        v[4]=v[5];
        v[5]='0';
          if((m.find(v)!=m.end()&&m[v]>count+1)||m.find(v)==m.end())
        Swop3(5,v,count+1);
        w[4]=w[7];
        w[7]='0';
          if((m.find(w)!=m.end()&&m[w]>count+1)||m.find(w)==m.end())
        Swop3(7,w,count+1);
    }
    else if(i==5)
    {
        t[5]=t[2];
        t[2]='0';
         if((m.find(t)!=m.end()&&m[t]>count+1)||m.find(t)==m.end())
        Swop3(2,t,count+1);
        u[5]=u[4];
        u[4]='0';
        if((m.find(u)!=m.end()&&m[u]>count+1)||m.find(u)==m.end())
        Swop3(4,u,count+1);
        v[5]=v[8];
        v[8]='0';
          if((m.find(v)!=m.end()&&m[v]>count+1)||m.find(v)==m.end())
        Swop3(8,v,count+1);
    }
    else if(i==6)
    {
        t[6]=t[3];
        t[3]='0';
         if((m.find(t)!=m.end()&&m[t]>count+1)||m.find(t)==m.end())
        Swop3(3,t,count+1);
        u[6]=u[7];
        u[7]='0';
        if((m.find(u)!=m.end()&&m[u]>count+1)||m.find(u)==m.end())
        Swop3(7,u,count+1);
    }
    else if(i==7)
    {
        t[7]=t[6];
        t[6]='0';
         if((m.find(t)!=m.end()&&m[t]>count+1)||m.find(t)==m.end())
        Swop3(6,t,count+1);
        u[7]=u[4];
        u[4]='0';
        if((m.find(u)!=m.end()&&m[u]>count+1)||m.find(u)==m.end())
        Swop3(4,u,count+1);
        v[7]=v[8];
        v[8]='0';
          if((m.find(v)!=m.end()&&m[v]>count+1)||m.find(v)==m.end())
        Swop3(8,v,count+1);
    }
    else if(i==8)
    {
        t[8]=t[5];
        t[5]='0';
         if((m.find(t)!=m.end()&&m[t]>count+1)||m.find(t)==m.end())
        Swop3(5,t,count+1);
        u[8]=u[7];
        u[7]='0';
        if((m.find(u)!=m.end()&&m[u]>count+1)||m.find(u)==m.end())
        Swop3(7,u,count+1);
    }
}
main()
{
    int a,i,b,i1,i2;
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {	
		scanf("%d",&b);
        for(i1=0;i1<b*b;i1++)
        {
            cin >> q[i1] ;
            if(q[i1]=='0')i2=i1;
        }
        if(b==2)Swop2(i2,q,0);
        else if(b==3)Swop3(i2,q,0);
        cout << min1 << endl;
        min1 = 9999;
        m.clear();
    }
}
