#include <stdio.h>
void Integers(int val1, int val2){
	
	int term;
        term=val1;
        val1=val2;
        val2=term;
	printf("after swap\n");
	printf("i is:%d", val1);
        printf("\nj is:%d", val2);

}

int main(){
	int i;
	int j;
	printf("initial value for i is:");
	scanf("%d", &i);
	printf("initial value for j is:");
	scanf("%d", &j);

	Integers(i,j);
	return 0;
}


# Assignment1
