#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
struct Node
{
	char data[256];
	struct Node* next;
};
void swapNodes(struct Node **head_ref, int x) 
{
   struct Node *prevX = NULL, *currX = *head_ref; 
   struct Node *prevY = NULL, *currY = *head_ref;
   int y; 
   while (atoi(currX->data) != x) 
   { 
       prevX = currX; 
       currX = currX->next;
       if (atoi(currX->data) == x)
       {
       	   y = atoi(currX->next->data);
       }
   }
   while (atoi(currY->data) != y)
   {
       prevY = currY;
       currY = currY->next;
   }
   if (currX == NULL || currY == NULL)
   {   
       return; 
   }
   if (prevX != NULL)
   {	   
       prevX->next = currY; 
   }
   else
   { 
       *head_ref = currY;   
   }
   if (prevY != NULL)
   { 
       prevY->next = currX;
   } 
   else
   {  
       *head_ref = currX; 
   }
   struct Node *temp = currY->next; 
   currY->next = currX->next; 
   currX->next  = temp; 
} 
void append(struct Node* head_ref, char* newdata)
{
	struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
	struct Node* head2 = head_ref;
	strcpy(newnode->data, newdata);
	newnode->next = NULL;

	while (head2->next!=NULL)
	{
		head2 = head2->next;
	}
	head2->next = newnode;
}
void printList(struct Node* iter)
{
	while (iter!=NULL)
	{
		printf("%s ",iter->data);
		iter = iter->next;
	}
	printf("\n");
}
int main()
{
	struct Node* head = (struct Node*) malloc(sizeof(struct Node));
	printf("Enter numbers to add to your list:\n");
	char input[256];
	scanf("%s", input);
	head->next = NULL;
	int numofcases = 0;
	strcpy(head->data, input);
	strcpy(input,"");

	while (true)
	{
		scanf("%s", input);
		if (strcmp(input, "DONE")==0)
                {
                        break;
                }
		else if (*input>=48 && *input<=57)
		{
			append(head, input);
			strcpy(input,"");	
		}
	}
	printList(head);
	char input2[256];
	strcpy(input2,"");
	
	int z[256];
	int i, ncase=0;
	printf("Type two numbers to swap them around:\n");
	while (true)
        {
                scanf("%s", input2);
		if (atoi(input2) == z[i-1])
		{
			ncase = 1;
			printf("No swap candidates found. Try again:\n");
		}
		else
		{
			ncase = 0;
		}
		z[i] = atoi(input2);
                if (strcmp(input2, "DONE")==0)
                {
                        break;
                }
                else if (*input>=48 && *input<=57)
                {
                        append(head, input);
                        strcpy(input,"");
                }
		if (ncase == 0)
		{
			printf("\nresult:");
			swapNodes(&head, atoi(input2));
			printList(head);
			strcpy(input2, "");
		}
		i++;
	}
	return 0;
}

