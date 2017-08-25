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

void DeleteIfNextListhaveGreterValue(struct list **head){
 struct list *reverse = ReverseListIterative(*head);
 struct list *newHead = NULL, *next = NULL;
 while(reverse != NULL){
    next = reverse->next;
    if(newHead == NULL || newHead->data < reverse->data){
        reverse->next = newHead ;
        newHead = reverse;
      }else{
        free(reverse);
      }
    reverse = next ;
  }
  *head = newHead;
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
    DeleteIfNextListhaveGreterValue(&head) ;
    PrintList(head);
    return 0;
}
