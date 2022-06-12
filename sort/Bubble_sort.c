//
// Created by Programmer on 2022/6/11.
//
#include <stdio.h>
void bubble_sort(int *a,int length){
    for(int i=0;i<length;i++){
        for(int j=0;j<length;j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
void myPrint(int *a,int length){
    for(int i=0;i<length;i++){
        printf("%d ",a[i]);
    }
}
int main(){
    int arr[] = {9,10,99,88,12,19,2,82,56};
    int length = sizeof(arr) / sizeof(int);
    myPrint(arr,length);
    printf("\n--------------------------------\n");
    bubble_sort(arr,length);
    myPrint(arr,length);
    return 0;
}