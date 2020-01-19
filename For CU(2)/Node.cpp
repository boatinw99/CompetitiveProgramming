#include<stdio.h>
#include<stdlib.h>
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
	p->next = NULL ;
	return p ; 
}
main()
{
	NPTR p,head,q,z,y ;
	int d;
	scanf("%d",&d);
	head = getnode();
	head->data=d;
	p = head ;
	while(!0)
	{
		scanf("%d",&d);
		if(d==-1) break;
		q=getnode();
		q->data = d ;
		if(p->data<=q->data)
			{
			p->next = q ;
			p=p->next ; 
			} 
		else if(head->data>=q->data)
		{
			q->next = head ;
			head = q;
		}
		else 
		{
			for(z=head;z->next->data<q->data;z=z->next);
				q->next = z->next ;
				z->next = q ;	
		}	
	}
	for(p=head;p!=NULL;p=p->next)
	{
		printf("%d\n",p->data);
	}
}
