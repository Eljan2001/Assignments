#include <stdio.h>
void swapStrings(char *destination, char *source, char *t);           

int main(){
    char *str1="Hello";
    char *str2="Hi";
    char *term="";
    printf("str1: %s, str2: %s\n",str1,str2);
    swapStrings(str1,str2,term);
    

    return 0;
}

void swapStrings(char *destination, char *source, char *t){
    t=destination;
    destination=source;
    source=t;
    printf("str1: %s, str2: %s\n", destination, source);

}
