#include <stdio.h>

void function(char *source, char *integers, char *nonintegers)
{
int i = 0;
int q = 0;
int p = 0;
for (; source[i]!='\0'; i++)
	{
		if (48<=source[i] && source[i]<=57)
		{
			integers[q] = source[i];
			q++;
		}
		else
		{
			nonintegers[p] = source[i]; 
			p++;
		}
		integers[q]='\0';
		nonintegers[p]='\0';
	}
}

int main()
{
	char src[] = "abc123def99!";
	char intgrs[256];
	char nonintgrs[256];
	function(src, intgrs, nonintgrs);
	printf("integers:%s, nonintegers:%s",intgrs, nonintgrs);
	return 0;
}
