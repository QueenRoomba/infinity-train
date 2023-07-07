#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* arr, int n){
    int temp = 0;
    int indexCount = 0;
    int swapCheck = 0;
    int* indexArray = (int*)calloc((n+1), sizeof(int));
    
    printf("Number of swaps: \n");
    for (int i = 0; i < n-1; i++) {
        indexCount = 0;
        swapCheck = 0;
        for (int z = 0; z < n-i-1; z++) {
            if (arr[z] > arr[z + 1]) {
                temp = arr[z];
                arr[z] = arr[z + 1];
                arr[z + 1] = temp;
                swapCheck = 1;
                indexCount++;
                indexArray[z]++;
                indexArray[z+1]++;
                
            }
        }
        printf("%d, ", indexCount);
        if (swapCheck == 0) {
            break;
        }

    }
    printf("\nNumber of times indexes are switched: \n");
    for (int j = 0; j<n;j++) {
        printf("%d, ", indexArray[j]);
    }
}

int main() {
    int array[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int *ptr = array;
    int arrsize = sizeof(array) / sizeof(array[0]);
    bubbleSort (ptr, arrsize);
    
    printf("\nSorted array: \n");
    for (int i = 0; i<arrsize;i++) {
        printf("%d, ", array[i]);
    }
}