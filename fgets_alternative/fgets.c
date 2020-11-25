#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 4000
void readLine(char* buffer, int num, FILE* stream)
{
    char buf[BUF_SIZE];
    buf[BUF_SIZE-1] = '\0';  
    int N = 0;

    for(int i = N; i < num; i++)
    {
        fread(buf, N, i - N, stream);
        
	if(buf[i] != '\n' || buf[i] != '\0' || buf[i] != 0)
	{
	    N=i;
            fprintf(stdout,"%s",buf);
            memset(buf, 0, BUF_SIZE);
        }
    }
}
int main()
{
	FILE* stream = fopen("binarytree.txt", "r");
	char buf[BUF_SIZE];
	int N = 1000;
	readLine(buf, N, stream);
	return 0;
}
