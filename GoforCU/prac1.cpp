//TrieDatastructure
#include<bits/stdc++.h>
using namespace std ;
struct TrieNode 
{
	struct TrieNode *child[26];
	bool ENDofword;	
};
struct TrieNode * getnode()
{
	struct TrieNode *p=new TrieNode ;
	p->ENDofword=0;
	for(int i=0;i<26;i++)p->child[i]=0;
	return p;
}
void insert(struct TrieNode *p,string key)
{
	for(int i=0;i<key.length();i++)
	{
		int index=key[i]-'a';
		if(!p->child[index])p->child[index]=getnode();
		p=p->child[index];
	}
	p->ENDofword=1;
}
bool search(struct TrieNode *p,string key)
{
	for(int i=0;i<key.length();i++)
	{
		int index=key[i]-'a';
		if(!p->child[index])return 0;
		p=p->child[index];
	}
	return p!=NULL&&p->ENDofword;
}
bool Isleaf(struct TrieNode *p)
{
	for(int i=0;i<26;i++)if(p->child[i])return 0;
	return 1;
}
bool deleter(struct TrieNode *p,string key,int lvl)
{
	if(p!=NULL)
	{
		if(lvl==key.length())
		{
			p->ENDofword=0;
			if(Isleaf(p))return 1;
		}
		else
		{	
			int index=key[lvl]-'a';
			if(deleter(p->child[index],key,lvl+1))
			{
				free(p->child[index]);
				if(Isleaf(p)&&p->ENDofword)return 1;
			}
		}
	}
	return 0;
}
main()
{
	int m;
	string key;
	printf("Insert : ");
	struct TrieNode *root=getnode();
	for(scanf("%d",&m);m;m--)
	{
		cin >> key;
		insert(root,key);
	}
	printf("Seacrh : ");
	for(scanf("%d",&m);m;m--)
	{
		cin>> key;
		printf("%d\n",search(root,key));
	}
	printf("Delete : ");
	for(scanf("%d",&m);m;m--)
	{
		cin >> key;
		deleter(root,key,0);
	}
	printf("Seacrh : ");
	for(scanf("%d",&m);m;m--)
	{
		cin>> key;
		printf("%d\n",search(root,key));
	}
	
}
