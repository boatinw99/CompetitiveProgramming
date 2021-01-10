#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
map<string,int>::iterator it;
string w[70009];
main()
{
	int i,n,j,k;
	string s,q;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		cin >> s;
		w[i]=s;
		for(j=0;j<9;j++)
		{
			q=s[j];
			if(m[q]==0||m[q]==i+1)
			m[q]=i+1;
			else m[q]=-1;	
			for(k=j+1;k<9;k++)
			{
				q+=s[k];
				if(m[q]==0||m[q]==i+1)
				m[q]=i+1;
				else m[q]=-1;
			}
		}
	}
	for(it=m.begin();it!=m.end();it++)
	{	
		if(it->second!=-1&&w[it->second-1].size()>it->first.size())
		{
		
			w[it->second-1]=it->first;
		}
	}
	for(i=0;i<n;i++)
	{
		cout << w[i] << endl;
	}
	
	
	
}
