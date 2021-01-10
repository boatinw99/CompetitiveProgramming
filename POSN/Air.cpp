#include<bits/stdc++.h>
using namespace std;
int a,g=0,k=0 ;
char c[14] ;
vector<string> v[14]; 
vector<string>::iterator it,it1; 
int Call(int i,string q,int count)
{
	int i1 ;
	if(i==a)
	{
		v[count].push_back(q);
		return 0;
	}
	else 
	{
	string d=q,e=q ;
	d[i]='0';
	e[i]='1';	
	Call(i+1,d,count);
	Call(i+1,e,count+1);
	}

}
main()
{
	int i,i1,i2,i3,i4,k=0 ;
	scanf("%d",&a);
	int s[a];
	for(i=0;i<a;i++)c[i]=65+i;
	Call(0,c,0);
	for(it=v[1].begin();it!=v[1].end();it++)
	{
		cout << *v[0].begin() << " " << *it ;
		printf("\n");
	}
	//begin
	for(i=1;i<a-1;i++)
	{
		i1=0;
		i3=0;
		for(it=v[i].begin();it!=v[i].end();it++,i1++)
		{
			for(i2=0;i2<a;i2++)
			{
				if(v[i][i1][i2]=='1')
				{
					s[i3]=i2;
					i3++;
				}
				if(i3>=i)break;
			}
			i2=0;
			for(it1=v[i+1].begin();it1!=v[i+1].end();it1++,i2++)
			{
				k=0;
				for(i4=0;i4<i3;i4++)
				{
					if(v[i+1][i2][s[i4]]!='1')
					{
						k=99;
						break;
					}
				}
				if(k==0)
				{
					cout << *it << " " << *it1  ; 
					printf("\n");	
				}		
			}			
			
			i3=0;	
		}
	}
	//end
	for(it=v[a-1].begin();it!=v[a-1].end();it++)
	{
		cout << *it << " " << *v[a].begin() ;
		printf("\n");
	}
}
