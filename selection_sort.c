//
// Created by Programmer on 2022/6/11.
//
#include <stdio.h>
void selection_sort(int *a,int length){
    for(int i=0;i<length-1;i++) {
        int min = i;
        for (int j=i+1;j<length;j++) {
            if (a[j] < a[min])
                min = j;
        }
        //这里一定要进行swap，否则会让所有的数值都变得一样啦
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
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
    selection_sort(arr,length);
    myPrint(arr,length);
    return 0;
}