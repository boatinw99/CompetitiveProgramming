#include<bits/stdc++.h>
using namespace std ;
struct TrieNode
{
	struct TrieNode *child[26];
	bool End;
};
struct TrieNode *getNode()
{
	struct TrieNode *p=new TrieNode;
	p->End=0;
	for(int i=0;i<26;i++)p->child[i]=NULL;
	return p;
}
void insert(struct TrieNode *p,string key)
{
	for(int i=0;i<key.length();i++)
	{
		int index=key[i]-'a';
		if(!p->child[index])p->child[index]=getNode();
		p=p->child[index];
	}
	p->End=1;
}
bool search(struct TrieNode * p,string key)
{
	for(int i=0;i<key.length();i++)
	{
		int index=key[i]-'a';
		if(!p->child[index])return 0;
		p=p->child[index];
	}
	return p!=NULL&&p->End;
}
bool Isleaf(struct TrieNode *p)
{
	for(int i=0;i<26;i++)if(p->child[i])return 0;
	return 1;
}
bool deleter(struct TrieNode *p,string key,int level)
{
	if(p!=NULL)
	{
		if(level==key.length())
		{
			printf("%d",p->End);
			p->End=0;
			if(Isleaf(p))return 1;
			return 0;
		}
		else
		{
			int index=key[level]-'a';
			if(deleter(p->child[index],key,level+1))
			{
				free(p->child[index]);
				if(Isleaf(p)&&p->End)return 1;
			}
		}
	}
	return 0;
}
void deletekey(struct TrieNode *root,string key)
{
	deleter(root,key,0);
}
int dictionary(struct TrieNode *p ,string key)
{
	for(int i=0;i<key.length();i++)
	{
		int index=key[i]-'a';
		if(!p->child[index])return i;
		p=p->child[index];
	}
	if(p->End)return key.length();
	return 0;
}
main()
{
	string key;
	int m;
	struct TrieNode *root =getNode();
	printf("Insert : ");
	scanf("%d",&m);
	while(m--)
	{
		cin >> key;
		insert(root,key);
	}
	printf("dictionary : ");
	scanf("%d",&m);
	while(m--)
	{
		cin >> key;
		int x=dictionary(root,key);
		if(x==0)printf("Empty");
		else
		for(int i=0;i<x;i++)printf("%c",key[i]);
		printf("\n");
	}
	
}
