#include <stdio.h>
void swapArrays(int a1[], int a2[],int temp[], int len);
void print2DArr(int *arr2D[], int rows, int columns);

int main(){
    int a1[] = {1,2,3,4,5};
    int a2[] = {0,0,0,0,0};
    
    int temp[] = {};
    int len = sizeof(a1)/sizeof(int);
    int *arr2D[2] = {a1,a2};                    
    print2DArr(arr2D, 2, len);
    swapArrays(a1, a2, temp, len);
  
    return 0;
}
void swapArrays(int a1[], int a2[], int temp[], int len){

    for (int i=0; i<len; i++){
	temp[i]=a1[i];
    }
    for (int i=0; i<len; i++){
	a1[i]=a2[i];
	

    }
    printf("\n");
    for (int i=0; i<len; i++){
	a2[i]=temp[i];
	
	

    }
    int *arr2D[2] = {a1,a2};
    print2DArr(arr2D, 2, len);

}
void print2DArr(int *arr2D[], int rows, int columns){
    for (int i=0; i<rows; i++){
	   for (int q=0; q<columns; q++){
		   printf("%d ", arr2D[i][q]);
	   }

}
}
