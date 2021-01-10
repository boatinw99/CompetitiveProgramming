#include<stdio.h>
int a[10]={5,6,3,4,7,1,0,8,2,9};
int merge(int left,int mid,int right)
{  int l=left,m = mid+1,i=0,b[right-left+1],j;
   	    
		   for(l;l!=mid+1&&m!=right+1;)
   	    {
   	    	if(a[l]>a[m])
   	    	{
   	    		b[i]=a[m];
   	    		m++;
   	    		i++;
			}
			else if(a[l]<a[m])
			{
				b[i]=a[l];
				l++;
				i++;
			}
		}
     if(m<=right)
     {
     	for(;m<=right;m++)
		 {
		 	b[i]=a[m];
		 	i++;
		 }
	 }
	 else if(l<mid+1)
	 {
	 	for(;l<mid+1;l++)
	 	{
	 		b[i]=a[l];
			i++;	
		}
	 }
	 for(j=0;left<=right;j++,left++)
	 {
	 	a[left]=b[j];
	 }

}
	int divide(int first,int last)
{   
	int left;
    int right;
    int mid;
	if(left!=right)
	{   left=first;
		right = last;
		mid=(left+right)/2;
		divide(left,mid);
		divide(mid+1,right);
		merge(left,mid,right);
	}
		
	
}
main()
{   int i;
	divide(0,9);
	for(i=0;i<=9;i++)
	printf("%d ",a[i]);
}
