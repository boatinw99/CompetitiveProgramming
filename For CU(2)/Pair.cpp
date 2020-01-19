#include<bits/stdc++.h>
using namespace std;
vector<int> v(100000);
struct node
{
    int data ;
    struct node * next ;
};
typedef struct node * Node ;
Node getnode()
{
    Node p;
    p=(Node)malloc(sizeof(struct node));
    return p;
}
main()
{
    Node head,p,q,s,e,d;
    int a,i,j,x,y,check,k,g=0,c=0;
    int sum=0,count;
    scanf("%d",&a);
    for(i=1;i<=a;i++)
    {
        scanf(" %d %d",&x,&y);
        v[y]=x;
    }
    head=getnode();
    head->data = v[a];
    head->next=NULL;
    s=head;
    check=v[a];
    for(i=a-1;i>0;i--)
    {
		p=getnode();
        p->data=v[i];
        if(p->data>s->data)
        {
            sum=sum+(p->data)*(a-i)+check;
            s->next=p;
            p->next=NULL;
            s=p;
        }
        else if(p->data<head->data)
        {
            p->next=head;
            head=p;
        }
        else
        {
              if(g==99){
              	g=0;
			  	for(q=e;q->next->data<p->data;q=q->next)
              {c+=q->data; k++;}
              p->next=q->next;
              q->next=p;
              k++;
              sum=sum+(p->data)*(k)+c;
              c+=p->data;
            	if(v[i-1]>v[i]){e=p;g=99;}
            	
			  }
			  else{
			  k=1; count=0;
              for(q=head;q->next->data<p->data;q=q->next)
              {count+=q->data; k++; if(q->next->data>v[i-1])d=q;c=count;}
              count+=q->data;
              p->next=q->next;
              q->next=p;
              sum=sum+(p->data)*(k)+count;
			  if(v[i-1]>v[i]){e=p;g=99;c=count;c+=v[i-1]-1;}
			  else if(v[i-1]<v[i]){e=d;g=99;}
			 }
        }
    /*    printf("\n");
		for(q=head;q!=NULL;q=q->next)
    			{
    				printf("%d ",q->data);
				}
			printf("\n%d",sum);*/
        check+=v[i];
    }
    	printf("%d",sum);


}
