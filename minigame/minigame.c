#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minigame.h"

#define BUF_SIZE 1250
void function(char* arr1, char* arr2, int arrSIZE)
{
	int i,j;



	
	for (i=0; i<arrSIZE; i++)
	{
		int plus=0;
		int qmark=0;
		int dot = 0;
		for (j=0; j<arrSIZE; j++)
		{

			if ( (i==j) && (arr1[i]==arr2[j]) )
			{
				plus++;
			}	
			else if ( (i!=j) && (arr1[i]==arr2[j]) )
			{

				qmark++;
			}
			else if ( arr1[i]!=arr2[j] )
			{

				dot++;
			}
			if (plus>0)
			{
				printf("+");
				break;
			}
			else if (qmark>0)
                        {
                                printf("?");
				break;
                        }
			else if (dot==arrSIZE)
                        {
                                printf(".");
				break;
				
                        }
		}
	}
	
}
int main()
{
	FILE* infile = fopen("settings.ini", "r");
	printf("Welcome to Fallout 3 hacking minigame!\n");
	char* numoflet;
	char buf[BUF_SIZE];
	fread(buf, 1,9, infile);
	char* tmp = strtok(buf, " ");
	int i=0;

	char* passwd;
	char* numoftrys;
	while( tmp != NULL ) {
		if (i==0)
		{
			passwd = tmp;
		}
		else if (i == 1)
		{
			numoflet = tmp;
		}
		else
		{
			numoftrys = tmp;
		}

      		tmp = strtok(NULL, " ");
		i++;
   	}

	printf("The passphrase contains %s letters\n", numoflet);
	int arrSize = strlen(passwd);
	int number = atoi(numoftrys);
	int bonustrys = 2;
	while (number!=0)
	{

		printf("you have %d tries left: ", number);


		char input[256];
		scanf("%s", input);
		if (strcmp(input, passwd) == 0)
		{
			printf("correct, here's how you did:\n");
			printf("%s\n", input);
			break;
		}
		else if (strcmp(input, "!quit")==0)
		{
			printf("game over.");
			break;
		}
		else 
		{
                        if (strlen(input)==strlen(passwd))
			{
				printf("incorrect, here's how you did:\n");
				printf("%s\n", input);
				function(input, passwd, arrSize);
				printf("try again.\n");
				
			}
			if (bonustrys==0 && (strlen(input)!=strlen(passwd)))
                        {
				printf("incorrect, here's how you did:\n");
                                printf("%s\n", input);
                                function(input, passwd, arrSize);
                                printf("try again.\n");

			}
			if (bonustrys>0 && (strlen(input)!=strlen(passwd)))
                        {
                                printf("Wrong number of characters, try again.\n");
                                bonustrys--;

                        }

			if (bonustrys==0)
			{
				number--;
			}
			if (number == 0)
			{
				printf("game over.\n");
				break;
			}

			continue;
		}
	}
	return 0;
	
}
