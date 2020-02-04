#include<stdio.h>
#include<stdlib.h>
//Hii this the another change
struct Node
{
 int data;
  struct Node* next;
};

struct Node* swap(struct Node* p1,struct Node* p2)
{
  struct Node*next;
  next=p2->next;
  p2->next=p1;
  p1->next=next;
 return p2;
}


struct Node* bubblesort(struct Node* head,int n)
{
 struct Node* ptr,*lptr,*prev;
 int i,j,d1;
 for(i=0;i<n-1;i++)
 {
   ptr=head;
   prev=NULL;
  for(j=0;j<n-1-i;j++)
  {
    d1=(ptr->next)->data;
    if(ptr->data > d1)
   {
     lptr=swap(ptr,ptr->next);
     if(prev==NULL)
     {
      head=lptr;
      prev=lptr;
     }
     else
     {
      prev->next=lptr;
      prev=lptr;
      }
   }
   ptr=ptr->next;
  }
}
return head;
}

struct Node* createlist(int n)
{
  int i,m;
   struct Node* ptr,*lptr=NULL;
   for(i=0;i<n;i++)
  { 
    ptr=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data");
    scanf("%d",&m);
    ptr->data=m;
    ptr->next=lptr;
    lptr=ptr;
  }
 return lptr;
}

void printlist(struct Node* head)
{
 struct Node* ptr;
ptr=head;
 while(ptr!=NULL)  
  {
  printf("%d \n",ptr->data);
  ptr=ptr->next;
 }
}

void main()
{
 int n;
 struct Node* ptr; 
printf("Enter the size of linbkedlist");
 scanf("%d",&n);
 ptr=createlist(n);
 ptr=bubblesort(ptr,n);
 printlist(ptr);
} 
    
