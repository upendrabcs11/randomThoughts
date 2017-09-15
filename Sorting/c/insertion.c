#include<stdio.h>
#define MAX 8
void insertionsort(int[] );
void display(int[]);
bool MiddleOfLinkedList(struct list *head){
   
}
int NthFromLast(struct list **head,int n){
   
}
void DeleteList(struct list **head){
   
}
UPENDRA • Now
UPENDRA KUMAR (upendrakumarpatel7@gmail.com)



int  main()
{
	int a[MAX];
	int k;
	printf("enter value in array");
	for(k=0;k<MAX;k++)
	scanf("%d",&a[k]);
	insertionsort(a);
	display(a);
	return 0;
}
void insertionsort(int a[])
{
	int k;
	for(k=1;k<MAX;k++)
	{ int T,p;
	T=a[k];
	p=k-1;
	while(T<a[p]&&p>=0)
	{
		a[p+1]=a[p];
		p=p-1;
	}
	a[p+1]=T;
}	
	
}
void display(int a[])
{
	int k;
	printf("display sorted list");
	for(k=0;k<MAX;k++)
	printf("%d\n",a[k]);
}


