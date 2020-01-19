#include<bits/stdc++.h>
using namespace std ;
struct node
{
	int data ;
	struct node *next ;
};
typedef struct node * NPTR ;
NPTR getnode()
{
	NPTR p ;
	p=(NPTR)malloc(sizeof(struct node));
	p->next = NULL;
	return p ;
}
main()
{
	NPTR head,p,q ;
	int a,b,i,k=0;
	scanf("%d %d",&a,&b);
	head=getnode();
	head->data=1;
	p=head;
	for(i=1;i<a;i++)
	{
		q=getnode();
		p->next=q;
		p=p->next;
	}
	while(a--)
	{
		i=0;
		while(!0)
		{
			
		}
	}
	
}
