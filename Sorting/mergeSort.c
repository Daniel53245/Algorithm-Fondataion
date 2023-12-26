#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int i_begin, int i_middle, int i_end){
        int i,j,k;
        int n1 = i_middle - i_begin + 1;
        int n2 = i_end - i_middle;
        int L[n1], R[n2];
        for(i = 0; i < n1; i++){
                L[i] = arr[i_begin + i];
        }
        for(j = 0; j < n2; j++){
                R[j] = arr[i_middle + 1 + j];
        }
        i = 0;
        j = 0;
        k = i_begin;
        while(i < n1 && j < n2){
                if(L[i] <= R[j]){
                        arr[k] = L[i];
                        i++;
                }
                else{
                        arr[k] = R[j];
                        j++;
                }
                k++;
        }
        while(i < n1){
                arr[k] = L[i];
                i++;
                k++;
        }
        while(j < n2){
                arr[k] = R[j];
                j++;
                k++;
        }
}

void mergeSort(int* arr,int i_begin, int i_middle, int i_end){
        printf("i_begin: %d, i_middle: %d, i_end: %d\n",i_begin,i_middle,i_end);
        //base case(single element)
        if(i_begin == i_middle & i_middle+1 == i_end){
                return;
        }
        //if one array is singel element the other is 2 element
        if(i_begin == i_middle){
                if(arr[i_middle+1] > arr[i_end]){
                        int temp = arr[i_middle+1];
                        arr[i_middle+1] = arr[i_end];
                        arr[i_end] = temp;
                }
                return;
        }
        //assuing i_begin to i_middle is not sorted
        //assuming i_middle+1 to i_end is not sorted

        mergeSort(arr,i_begin,(i_begin+i_middle)/2 -1 ,i_middle);
        mergeSort(arr,i_middle+1,(i_middle+i_end)/2 -1,i_end);
        //recursion, assuming it is sorted
        merge(arr,i_begin,i_middle,i_end);
        return;
}


int main(){
        int arr[] = {5, 2, 4, 6, 1, 3};
        printf("Sorted array: \n");
        mergeSort(arr,0,6/2-1,6);
        for (int i = 0; i < 6; i++) {
                printf("%d ", arr[i]);
        }
        return 0;
}