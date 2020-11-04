#include <stdio.h> 
#include <string.h>
#include <stdbool.h> 
#include <stdlib.h>
bool x=false;
struct Node{
	char data[256];
	struct Node* next;
};
void append(struct Node** tail1, char *newdata)
{
 	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
 	struct Node* tail2 = *tail1;
 	strcpy(new_node->data, newdata);
 	new_node -> next = NULL;
 	while (tail2 -> next != NULL)
 		{
			tail2 = tail2 -> next;
		}	
 	tail2 -> next = new_node;
	
}
void pop(struct Node** tail1, char *newdata)
{
	struct Node *temp = *tail1;
	struct Node *head1;
	if (temp != NULL && strcmp(temp->data, newdata) == 0)
                {
	                *tail1 = temp->next;
        	        free(temp);
                	return;
                }
	while (temp != NULL && strcmp(temp->data, newdata) != 0)
                {
                        head1 = temp;
                        temp = temp->next;
                }

    	if (temp == NULL)
		{
			x=true;
			printf("please select a person from the queue\n");
        		return;
   	 	}
	head1 -> next = temp -> next;
	free(temp);
}	
void addToTail(struct Node *head1, char *newdata)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	strcpy(new_node -> data, newdata);
	new_node -> next = head1 -> next;
        head1 -> next = new_node;
	


}	

void printList(struct Node* iter)
{
	printf("queue:");
 	while( iter != NULL)
		{
			printf("%s ", iter->data);
			iter = iter->next;
 		}
        printf("\n");
}
int main()
{
	char input[256];
	
	bool quit = 0;
	
	struct Node* head = (struct Node*) malloc(sizeof(struct Node));
	
	strcpy(head->data, "Turgut");

	struct Node* tail=head;
	
 	append(&tail,  "Nazrin");

 	append(&tail,  "Nigar");

	append(&tail, "Kamran");

        append(&tail,  "Eljan");
	
	printList(head);
	
	while(!quit) 
		{
		printf("enter a command:");
    		scanf("%s" , input);
    		if (strcmp(input,"quit") == 0) 
			{
        			quit = 1;
				break;
    			}
    		else if (strcmp(input,"admit") == 0) 
			{
				printf("%s was admitted\n", head -> data);
        			pop(&head, head->data);
    			}	
    		else	
    			{
        			pop(&head, input);
        			if(!x)
					{
        					append(&head, input);
        				}
        			x = false;
    			}
    			
    		printList(head);
    		
    		}

    return 0;
}

