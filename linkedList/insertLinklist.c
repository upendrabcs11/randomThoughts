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

bool DeleteElement(struct list **head,int data){
    if(*head != NULL){
        struct list *cur = *head,*prev = NULL ;    
        while(cur != NULL && cur->data != data){
            prev = cur;
            cur = cur->next;
        }
        if(cur != NULL){
            if(prev != NULL)
                prev->next = cur->next;
            else
                *head = cur->next;
            free(cur);
            return true;
        }
    }
   return false;     
}

bool DeleteAtIndex(struct list **head,int index){
    if(index > 0){
        struct list *cur = *head, *prev = NULL;
        int k = 1;
        while(cur != NULL && k < index){
            prev = cur;
            cur = cur->next;
            k++;
        }
        if(cur != NULL){
            if(prev != NULL)
                prev->next = cur->next;
            else
                *head = cur->next;
            free(cur);
            return true;
        }
    }
      return false;  
}

int LengthOfLinkedList(struct list *head){
    // iterative  length; more efficient
        int count = 0;
        while(head != NULL){
            head = head->next;
            count++;
        }
        return count;
    // recursive use stack memory so less eficient
    /*
     if(head == NULL)
         return 0;     
      return 1 + LengthOfLinkedList(head->next);
    */
}

bool SearchElement(struct list *head, int data){
    //iterative method more efficient
    while(head != NULL && head->data != data){
        head = head->next;
    }
    return (head != NULL);
    // recursive method use function call stack less efficient
   /* 
    if(head == NULL)
        return false;
    if(head->data == data)
        return true;
    else 
        return SearchElement(head->next, data);
    */
    
}

bool SwapNodeLinkedList(struct list **head,int x,int y){
    if(x==y) // both refer to same element no need to swap
        return false;
   struct list *curx = *head,*cury = *head, *prevx = NULL ,*prevy = NULL;
   while(curx != NULL && curx->data != x){ // find x and keep track of prevx
       prevx = curx;
       curx = curx->next;
   }
   while(cury != NULL && cury->data != y) // find y and keep track of prevy
   {
       prevy = cury;
       cury = cury->next;
   }
   if(curx == NULL || cury == NULL) // either x or y or both not found in list
       return false;
    // swap nodes
      struct list *temp = curx->next;
      curx->next = cury->next;
      cury->next = curx->next;    
    if(prevx == NULL){
        *head = cury;
    }else{
        prevx->next = cury;        
    }
    if(prevy == NULL){
        *head = curx;
    }else{
        prevy->next = curx;
    }
    return true;
}

int  MiddleOfLinkedList(struct list *head){ // middle of linked list if two middle element then avg of them else middle
   if(head==NULL)
       return -1;
   struct list *fast = head, *slow = head;
   while(fast != NULL && fast->next != NULL){
        if(fast != slow)
            slow=slow->next;
       fast=fast->next->next;       
   }
   if(fast==NULL){
        return (slow->data + slow->next->data)/2;
   }
   else{
     return slow->data;
   } 
}

int NthFromLast(struct list *head,int n){ // Nth node from last node
   struct list *fast = head,*slow = NULL;
   for(int i=1; fast != NULL && i<=n; i++){ //find Nth from first
       fast=fast->next;
   }
   while(fast){ // move both Nth and first node
       if(slow == NULL)
           slow = head;
       else
           slow = slow->next;
       fast = fast->next ;
   }
   if(slow == NULL) 
       return -1;
  return slow->data;
}

void DeleteList(struct list **head){ // delete all node from list
   struct list *next,*cur=*head;
   while(cur){
       next = cur->next;
       free(cur);
       cur = next;
   }
   *head = NULL;
}
struct list *ReverseListRecursive(struct list *head){
  if(head == NULL || head->next == NULL)
     return head;
   struct list *nextNode = head->next ;
   struct list *rev = ReverseListRecursive(nextNode);
   nextNode->next = head;
   head->next = NULL;
   return rev;
   /*
     struct list *rev = ReverseListRecursive(head->next);
     head->next->next = head;
     head->next = NULL;
     return rev; 
   */ 
}
struct list *ReverseListIterative(struct list *head){
  struct list *curHead = NULL ,*nextNode;
  while(head != NULL){
     nextNode = head->next;
     head->next = curHead ;
     curHead = head;
     head = nextNode; 
  }
   return curHead; 
}
int main() {
    int n; 
    scanf("%d", &n);
    struct list *head = NULL;
    for(int i=0;i<n;i++){
        int data ;
        scanf("%d",&data);
        if(data % 2 == 0)
          InsertAtEnd(&head,data);
        else
            InsertAtBeggning(&head,data);
    }
    InsertAtPosition(&head,7,111);
    PrintList(head);
    DeleteElement(&head,111);
    PrintList(head);
    DeleteElement(&head,112);
    PrintList(head);
    DeleteElement(&head,33);
    PrintList(head);
    DeleteAtIndex(&head,4);
    PrintList(head);
    return 0;
}
