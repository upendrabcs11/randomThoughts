#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

struct list{
    int data;
    struct list *next;
};
void PrintList(struct list *head){
    while(head){
        printf("%d->",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void InsertAtEnd(struct list **head,int data){
    struct list *newNode = (struct list*)malloc(sizeof(struct list));
    if(newNode){
        newNode->data = data; 
        newNode->next = NULL;
        if(*head == NULL)
            *head = newNode;
        else {
            struct list *cur = *head,*prev;
            while(cur != NULL){
                prev = cur;
                cur = cur->next ;
            }
            prev->next = newNode;
        }        
    }
}

void InsertAtBeggning(struct list **head,int data){
    struct list *newNode = (struct list*)malloc(sizeof(struct list));
    if(newNode){
        newNode->data = data;
        newNode->next = *head;
        *head = newNode;
    }
}

void InsertAtPosition(struct list **head,int pos,int data){
    if(pos <= 1)
        InsertAtBeggning(head,data);
    else{
        struct list *cur = *head,*prev = NULL;
        struct list *newNode = (struct list*)malloc(sizeof(struct list));
        if(newNode){
            newNode->data = data;
            newNode->next = NULL;
            if(*head == NULL)
                *head = newNode;
            else{
                int k = 1;
                while(cur != NULL && k < pos){
                    prev = cur ;
                    cur = cur->next;
                    k++;
                }
                prev->next = newNode;
                if(cur != NULL){
                    newNode->next = cur;
                }
            }
        }
    }
}

void InsertInSortedLinkedList(struct list **head,struct list *node){
   if(*head == NULL){
    *head = node;
   }
   else{
        struct list *cur = *head ,*prev = NULL;
        while(cur != NULL && cur->data < node->data){
          prev = cur;
          cur = cur->next;
        }
        node->next = cur;
        if(prev == NULL){
          *head = node;
        }else{
          prev->next = node;
        }
   }
}

void InsertionSort(struct list **head){
   struct list *temp = NULL, *cur = *head ;
   while(cur != NULL){
       struct list *nextElement = cur->next;
       cur->next = NULL;
       InsertInSortedLinkedList(&temp,cur) ;
       cur = nextElement;
   }
   *head = temp;
}

struct list *MiddleOfLinkedList(struct list *head){ // middle of linked list if two middle element then avg of them else middle
   if(head == NULL && head->next == NULL)
       return head;
   struct list *fast = head, *slow = head;
   while(fast != NULL && fast->next != NULL){
      if(fast != slow)
          slow=slow->next;
      fast = fast->next->next;       
   }   
     return slow;
}

struct list *MergeSortedList(struct list *left,struct list *right){
  struct list *newList = NULL;
  if(left == NULL)
    return right;
  else if(right == NULL)
    return left;
  else if(left->data < right->data){ 
       newList =  left;
       newList->next = MergeSortedList(left->next,right);
   }
   else{
       newList =  right;
       newList->next = MergeSortedList(left,right->next);
   }
   return newList;
 }

struct list *MergeSortedListIterative(struct list *left,struct list *right){
  struct list *newHead = NULL ,*newNode;
  if(left == NULL)
    return right;
  else if(right == NULL)
    return left;
  else if(left->data < right->data){ 
       newHead = newNode =  left;
       left = left->next;
   }
   else{
       newHead = newNode =  right;
       right = right->next;
   }
   while(left != NULL && right != NULL){
      if(left->data < right->data){
          newNode->next = left;
          left = left->next;
          newNode = newNode->next;
       }else{
          newNode->next = right;
          right = right->next;
          newNode = newNode->next;
       }
   }
   if(left == NULL)
     newNode->next = right;
  else if(right == NULL)
    newNode->next = left;

  return newHead;
 }

struct list *MergeSort(struct list *head){
  if(head == NULL || head->next == NULL){
      return head; 
   }
  //find middle and split it 
   struct list *middle = MiddleOfLinkedList(head);
   struct list *left = head;
   struct list *right = middle->next;
          middle->next = NULL;
   left = MergeSort(left);
   right = MergeSort(right); 
   return MergeSortedList(left,right);
}


int main() {
    int n; 
    scanf("%d", &n);
    struct list *head = NULL;
    for(int i=0;i<n;i++){
        int data ;
        scanf("%d",&data);
          InsertAtEnd(&head,data);
    }

    return 0;
}
