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

void deleteAlternate(struct list **head){
   struct list *delete  = NULL;
   struct list *cur = *head;
   while(cur != NULL && cur->next != NULL){
       delete = cur->next;
       cur->next = delete->next;
       free(delete);
       cur=cur->next;

   }
}

struct list *deleteAlternateRecur(struct list *head)
 {
   if(head == NULL || head->next == NULL)
         return head;
   struct list *delete = head->next;
   head->next = deleteAlternateRecur(delete->next);
   free(delete);
   return head;
 }

void splitAlterNodeList(struct list *head){
  struct list *newHead = NULL , *newCur = NULL;
  struct list *cur = head;
  while(cur != NULL && cur->next != NULL){

        struct list *alternateNode = cur->next; 
        cur->next = alternateNode->next ; 
        alternateNode->next = NULL; // breking link to alternate node
        cur = cur->next;
      
        if(newCur == NULL){
          newCur = newHead = alternateNode;
        }else{
          newCur->next = alternateNode;
          newCur = newCur->next;
        } 
  }
  PrintList(head);
  PrintList(newHead);
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
    PrintList(head);
    //PrintList(deleteAlternateRecur(head));
    splitAlterNodeList(head);
    PrintList(head);
    return 0;
}
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

void deleteAlternate(struct list **head){
   struct list *delete  = NULL;
   struct list *cur = *head;
   while(cur != NULL && cur->next != NULL){
       delete = cur->next;
       cur->next = delete->next;
       free(delete);
       cur=cur->next;

   }
}

struct list *deleteAlternateRecur(struct list *head)
 {
   if(head == NULL || head->next == NULL)
         return head;
   struct list *delete = head->next;
   head->next = deleteAlternateRecur(delete->next);
   free(delete);
   return head;
 }

void splitAlterNodeList(struct list *head){
  struct list *newHead = NULL , *newCur = NULL;
  struct list *cur = head;
  while(cur != NULL && cur->next != NULL){

        struct list *alternateNode = cur->next; 
        cur->next = alternateNode->next ; 
        alternateNode->next = NULL; // breking link to alternate node
        cur = cur->next;
      
        if(newCur == NULL){
          newCur = newHead = alternateNode;
        }else{
          newCur->next = alternateNode;
          newCur = newCur->next;
        } 
  }
  PrintList(head);
  PrintList(newHead);
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
    PrintList(head);
    //PrintList(deleteAlternateRecur(head));
    splitAlterNodeList(head);
    PrintList(head);
    return 0;
}
