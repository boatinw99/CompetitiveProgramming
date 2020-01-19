//TrieDatastructure
#include<bits/stdc++.h>
using namespace std ;
struct TrieNode
{
	struct TrieNode *child[26];
	bool End;
};
struct TrieNode *getnode()
{
	struct TrieNode *p=new TrieNode ;
	p->End=0;
	for(int i=0;i<26;i++)p->child[i]=NULL;
	return p;
}
void construct(struct TrieNode *p,string key)
{
	int index;
	for(int i=0;i<key.length();i++)
	{
		index=key[i]-'a';
		if(!p->child[index])p->child[index]=getnode();
		p=p->child[index];
	}
	p->End=1;
}
bool find(struct TrieNode *p,string key)
{
	int index;
	for(int i=0;i<key.length();i++)
	{
		index=key[i]-'a';
		if(!p->child[index])return 0;
		p=p->child[index];
	}
	return p->End&&p!=NULL ;
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
			p->End=1;
			return Isleaf(p);
		}
		int index=key[lvl]-'a';
		if(deleter(p->child[index],key,lvl+1))
		{
			free(p->child[index]);
			p->child[index]=NULL;
			return !p->End&&Isleaf(p);
		}
	}
	return 0;
}
main()
{
	int m;
	string key;
	struct TrieNode *root=getnode();
	scanf("%d",&m);
	while(m--)
	{
		cin >> key;
		construct(root,key);
	}
	scanf("%d",&m);
	char c;
	while(m--)
	{
		scanf(" %c",&c);
		cin >> key ;
		if(c=='A')
		printf("%d \n",find(root,key));
		else
		{
			deleter(root,key,0);
		}
	}
}
