#include<bits/stdc++.h>
using namespace std;
vector<int> B[100000];
vector<int> C;
vector<int>::iterator itC,itB;
main()
{
	int a,i,N=0,M=180000,K,d=-1,D;
	bool q,r ;
	scanf("%d ",&a);
	char s[a];
	gets(s);
	for(i=0;i<a;i++)
	{
		if(s[i]=='P')
		{
			C.push_back(i);
		}
		if(s[i]=='*'&&d==-1)d=i;
	}
//	printf("%d\n",d);
	for(itC=C.begin();itC<C.end()-1;itC++)
	{
		for(i=*itC+1;i<*(itC+1);++i)
		{
			if(s[i]=='*')
			{
				B[*itC].push_back(i-*itC);
			}
		}
	}
	for(i=*itC;i<a;++i)
	{
		if(s[i]=='*')
		{
			B[*itC].push_back(i-*itC);
		}
	}
	for(itC=C.begin();itC<C.end();)
	{
		for(itB=B[*itC].begin();itB!=B[*itC].end();itB++)
		{
		//	printf("%d %d\n",*itC,*itB);
		}
		itC++;	
		//printf("\n");
	}
	//d position 1
	//q r <- bool
	while(N+1<M)
	{
		K=(N+M)/2;
		D=d;
		r=0;
		for(itC=C.begin();itC!=C.end();itC++)
		{
			if(D>*itC)
			{
				if(D-*itC>K)
				{
					
				}
				else if(D>*(itC+1)&&itC<C.end()-1)
				{
					
				}
				else
				{
					itB=B[*itC].end()-1;
					if(*itB<=K)
					{
						for(itC=itC+1;itC<C.end()&&B[*itC].size()==0;itC++);
						
						if(itC>=C.end())
						{
							r=1;
							break;
						}
						else 
						{
							D=B[*(itC)][0]+*(itC);
						//	printf("%d\n",D);
							itC--;
						}
						///printf("%d\n",D);
					}
					else
					{
						itB--;
						for(itB;itB>=B[*itC].begin();itB--)
						{
							if(*itB<=K)
							{
								D=*(itB+1)+*itC;
							///	printf("%d\n",D);
								break;
							}
						}	
					}
					
				}
			}
			else if(D<*itC)
			{
				if(*itC-D>K)
				{
					break;
				}
				else if(B[*itC].size()==0)
				{
					if(*itC-D<=K)
					{
						for(itC;itC<C.end()&&B[*itC].size()==0;itC++);
						if(itC>=C.end())
						{
							r=1;
							break;
						}
						else 
						{
							for(itC;itC<C.end()&&B[*itC].size()==0;itC++);
						if(itC>=C.end())
						{
							r=1;
							break;
						}
						else 
						{
							D=B[*(itC)][0]+*(itC);
							itC--;
						}
						}
					}
					else break;
				}
				else
				{
					itB=B[*itC].begin();
					if(*itC-D>=*itB&&*itB*2+*itC-D>K)
					{
						D=*itB+*itC;
					}
					else if(*itB>=*itC-D&&(*itC-D)*2+*itB>K)
					{
						D=*itB+*itC;
					}
					else
					{
						itB=B[*itC].end()-1;
						if(*itC-D>=*itB&&*itB*2+*itC-D<=K)
						{
							for(itC=itC+1;itC<C.end()&&B[*itC].size()==0;itC++);
						if(itC>=C.end())
						{
							r=1;
							break;
						}
						else 
						{
							D=B[*(itC)][0]+*(itC);
							itC--;
						}
						}
						else if(*itB>=*itC-D&&(*itC-D)*2+*itB<=K)
						{
							for(itC=itC+1;itC<C.end()&&B[*itC].size()==0;itC++);
						if(itC>=C.end())
						{
							r=1;
							break;
						}
						else 
						{
							D=B[*(itC)][0]+*(itC);
							itC--;
						}
						}
						else
						{
							itB--;
							for(itB;itB>=B[*itC].begin();itB--)
							{
								if(*itB>=*itC-D&&(*itC-D)*2+*itB<=K)
								{
									D=*(itB+1)+*itC;
									break;
								}
								else if(*itC-D>=*itB&&*itB*2+*itC-D<=K)
								{
									D=*(itB+1)+*itC;
									break;
								}
							}
						}	
					}
				}
			}
		}
		if(r==0)
		{
			N=K;
		}
		else 
		{
			M=K;
		}
	}
	printf("%d",M);
}
