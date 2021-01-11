#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int num;
    struct node *next;
} Node;

Node* deleteKey(Node *head,int low, int high)
{  
    Node* tmp = head;	
    if (head == NULL)
    {
    	head = head->next;
    }	
        
    while (tmp->next != NULL)
    {	
        if (tmp->next->num <= high && tmp->next->num >= low)
        {
            tmp->next = tmp->next->next;
        }
        else
        {	
            tmp = tmp->next;
        }

    }
    return head;
}
void append(Node* iter, int num){
    while(iter->next!=NULL){
        iter = iter->next;
    }
    iter->next = (Node*) malloc(sizeof(Node));
    iter->next->num = num;
    iter->next->next = NULL;
}

void printLL(Node* iter){
    while(iter->next!=NULL){
        iter = iter->next;
        printf("%d, ",iter->num);
    }
    printf("\n");
}
int main(){
    Node* head = (Node*) malloc(sizeof(Node));
    head->next = NULL;
    append(head, 1);
    append(head, 5);
    append(head, 11);
    append(head, 19);
    append(head, 4);
    append(head, 2);
    
    printLL(head);

    deleteKey(head, 1, 11);

    printLL(head);

    return 0;
}
