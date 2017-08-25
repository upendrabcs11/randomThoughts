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

struct list *addTwoNoRepresentedByLinklist(struct list *head1,struct list *head2){
  head1 = ReverseListIterative(head1);
  head2 = ReverseListIterative(head2);
  struct list *newHead = NULL ,*cur;
  int carry = 0, data = 0;
   
  while(head1 != NULL || head2 != NULL || carry > 0){
    data = carry;
    if(head1 != NULL){
      data += head1->data; 
      head1 = head1->next;
    }
    if(head2 != NULL){
      data += head2->data; 
      head2 = head2->next;
    }
    carry = data/10;
    data = data % 10;    
    struct list *newNode = (struct list*)malloc(sizeof(struct list));
       newNode->data = data;
       newNode->next = NULL;
    if(newHead == NULL)
        cur = newHead = newNode;
    else{
        cur->next = newNode;
        cur = cur->next;
    }
  }
  return ReverseListIterative(newHead);
}

struct list *CharToLinkedList(char *number){
    int n = strlen(number);
    struct list *newHead = NULL;
    for(int i=0 ;i < n;i++){
        int data =  number[i] - '0';
        InsertAtEnd(&newHead,data);
    }
    return newHead;
}

int main() {
    
    char str1[100],str2[100];
    scanf("%s%s",str1,str2);
    struct list *number1 = CharToLinkedList(str1);
    struct list *number2 = CharToLinkedList(str2);    
    PrintList(number1);
    PrintList(number2);
    struct list *addNumber = addTwoNoRepresentedByLinklist(number1,number2);
    PrintList(addNumber);
    return 0;
}
