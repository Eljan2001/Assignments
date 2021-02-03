#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define BUF_SIZE 100000000
typedef struct Node
{
	char data[BUF_SIZE];
	struct Node* next;
}node;
void append(node* head, char* newdata)
{
	node* newnode = (node*) malloc(sizeof(node));
	node* head1 = head;
	strcpy(newnode->data, newdata);
	newnode->next = NULL;
	while (head1->next!=NULL)
	{
		head1 = head1->next;
	}
	head1->next = newnode;
}
void printlist(node* iter)
{
	while (iter!=NULL)
	{
		printf("%s", iter->data);
		iter=iter->next;
	}
}
void myfgets(node* head, char* buf, size_t bufsize, FILE* stream)
{
	size_t line = getline(&buf, &bufsize, stream);
        strcpy(head->data, buf);
        while (true)
        {
                line = getline(&buf,&bufsize, stream);
                int lineref = line;
                if (*buf=='\n' || lineref<0 || *buf=='\0')
                {
                        break;
                }
                append(head, buf);
        }	
        printlist(head);
}
int main(int argc, char** argv)
{
	if (argc<2)
	{
		fprintf(stderr, "needs at least two arguments");
		exit(1);
	}
	FILE* stream = fopen(argv[1], "r");
	if (stream==NULL)
	{
		fprintf(stderr, "file doesnt exist");
		exit(2);
	}
	node* head = (node*) malloc(sizeof(node));
	char* buf;
	size_t bufsize = BUF_SIZE;
	myfgets(head, buf, bufsize, stream);
	return 0;
}
