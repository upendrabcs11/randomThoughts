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

struct list *ReverseInKGroup(struct list *head,int k){
   if(head == NULL || k <= 1)
       return head;
   struct list *cur=head;
   struct list *temp=NULL;
   struct list *nextElement=NULL;
   int count=0;   
   while(cur != NULL && count < k){
       nextElement = cur->next;
       cur->next = temp;
       temp = cur;
       cur = nextElement;
       count++;
   }   
   head->next = ReverseInKGroup(cur,k);
   return temp;
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
    PrintList(ReverseInKGroup(head));
    return 0;
}
