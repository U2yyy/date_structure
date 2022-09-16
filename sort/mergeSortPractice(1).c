#include<stdio.h>
#include<stdlib.h>

void merge(int A[],int tempA[],int l,int r,int rEnd);
void mergeSort(int A[],int N);
void mergePass(int A[],int tempA[],int N,int length);

int main(){
    int a[] = {9,2,33,12,13,4,23,44,89,44,123,89,1};
    const int length = sizeof(a) / sizeof(a[0]);
    mergeSort(a,length);
    for(int i=0;i<length;i++){
        printf("%d ",a[i]);
    }
    return 0;
}

void merge(int A[],int tempA[],int l,int r,int rEnd){
    int k = l;
    int lEnd = r - 1;
    while(l <= lEnd&&r <= rEnd){
        if(A[l] <= A[r])
            tempA[k++] = A[l++];
        else
            tempA[k++] = A[r++];
    }
    while(l <= lEnd){
        tempA[k++] = A[l++];
    }
    while(r <= rEnd){
        tempA[k++] = A[r++];
    }
}

void mergePass(int A[],int tempA[],int N,int length){
    int k;
    for(k=0;k<N-2*length;k+=2*length){
        merge(A,tempA,k,k+length,k+2*length-1);
    }
    if(k<N-length){
        merge(A,tempA,k,k+length,N-1);
    }else{
        for(int j=k;j<N;j++){
            tempA[j] = A[j];
        }
    }
}

void mergeSort(int A[],int N){
    int* tempA = malloc(sizeof(int)*N);
    if(tempA){
        int l = 1;
        while(l<N){
            mergePass(A,tempA,N,l);
            l *= 2;
            mergePass(tempA,A,N,l);
            l *= 2;
        }
        free(tempA);
    }else{
        printf("out of RAM");
    }
}