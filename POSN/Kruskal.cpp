#include<bits/stdc++.h>
using namespace std;
int s[26][26]={0};
int q,k=0,t=0 ;
int Krus(char i,char j)
{
    int i1,j1;
	if(j==q&&t>0){k=99; return 0;}
	for(j1=0;j1<26;j1++)
	{
		if(j1!=j&&s[i][j1]==1)
		{
			t++;
			Krus(j1,i);
		}
		if(k==99)return 0;
	}
}
main()
{
    int y,i,x,d1,d2 ;
    char c1,c2,c3 ;
    priority_queue<pair<int,pair<char,char> > > pq ;
    scanf("%d",&y);
    for(i=0;i<y;i++)
    {
        scanf(" %c %c %d",&c1,&c2,&x);
        if(c1>c2)
        {
        	c3=c1;
        	c1=c2;
        	c2=c3;
		}
        pq.push({-x,{c1,c2}});
    }
    while(!pq.empty())
    {
        k=0;   
		c1=pq.top().second.first;
        c2=pq.top().second.second;
        d1=c1-65;
        d2=c2-65;
  		s[d1][d2]=1;
		s[d2][d1]=1; 
		q=d1;
		t=0;
		Krus(d2,d1);
		if(k==99)
		{   //printf("%d %d\n",d1,d2);
			s[d1][d2]=0;
			s[d2][d1]=0;
		}
		if(k!=99)
		{printf("%c %c %d\n",c1,c2,pq.top().first*-1);} 
        pq.pop();
    }
}
