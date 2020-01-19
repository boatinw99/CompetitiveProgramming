//Trie Datastructure
#include<bits/stdc++.h>
using namespace std ;
struct TrieNode
{
	struct TrieNode *child[26];
	bool END ;
};
struct TrieNode * getnode()
{
	struct TrieNode *p = new TrieNode;	
	p->END = 0;
	for(int i=0;i<26;i++)
	{
		p->child[i]=NULL ;
	}
	return p;
};
void construct(struct TrieNode *p,string key)
{
	int index ;
	for(int i=0;i<key.length();i++)
	{
		index=key[i]-'a';
		if(p->child[index]==NULL)
		{
			p->child[index]=getnode();
		}
		p=p->child[index];
	}
	p->END=1;
}
bool search(TrieNode * p,string key)
{
	int index ;
	for(int i=0;i<key.length();i++)
	{
		index=key[i]-'a';
		if(p->child[index]==NULL)return 0;
		p=p->child[index];
	}
	return p->END&&p!=NULL;
}
bool Isleaf(TrieNode *p)
{
	for(int i=0;i<26;i++)
	{
		if(p->child[i]!=NULL)return 0;
	}
	return 1;
}
bool deletekey(TrieNode *p,string key,int lvl)
{
	if(p!=NULL)
	{
		if(lvl==key.length())
		{
			p->END=0;
			return Isleaf(p);
		}
		else
		{
			int index=key[lvl]-'a';
			if(deletekey(p->child[index],key,lvl+1))
			{
				free(p->child[index]);
				p->child[index]=NULL;
				return Isleaf(p)&&p->END==0;
			}
		}
	}
	return 0;
}
main()
{
	string key ;
	int m;
	scanf("%d",&m);
	struct TrieNode * root = getnode();
	while(m--)
	{
		cin >> key ;
		construct(root,key);
	}
	scanf("%d",&m);
	while(m--)
	{
		cin >> key ;
		deletekey(root,key,0);
	}
	scanf("%d",&m);
	while(m--)
	{
		cin >> key ;
		printf("%s\n",search(root,key)?("yes"):("no"));
	}
}
