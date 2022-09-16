#include<stdio.h>
#include<stdlib.h>

void merge(int A[],int tempA[],int l,int r,int rEnd);
void mergePass(int A[],int tempA[],int N,int length);
void mergeSort(int A[],int N);

int main(){
    int a[] = {9,1,2,88,23,31,31,332,99};
    int length = sizeof(a)/sizeof(a[0]);
    mergeSort(a,length);
    for(int i=0;i<length;i++){
        printf("%d ",a[i]);
    }
    return 0;
}

void merge(int A[],int tempA[],int l,int r,int rEnd){
    int lEnd = r - 1;
    int k = l;
    while(l <= lEnd&&r <= rEnd){
        if(A[r] <= A[l])
            tempA[k++] = A[r++];
        else
            tempA[k++] = A[l++];
    }
    while(l <= lEnd){
        tempA[k++] = A[l++];
    }
    while(r <= rEnd){
        tempA[k++] = A[r++];
    }
}

void mergePass(int A[],int tempA[],int N,int length){
    int i;
    for(i=0;i<N-length*2;i+=2*length){
        merge(A,tempA,i,i+length,i+length*2-1);
    }
    if(i<N-length){
        merge(A,tempA,i,i+length,N-1);
    }else{
        for(int j=i;j<N;j++){
            tempA[j] = A[j];
        }
    }
}

void mergeSort(int A[],int N){
    int* tempA = malloc(sizeof(int)*N);
    int k = 1;
    if(tempA){
        while(k<N){
            mergePass(A,tempA,N,k);
            k *= 2;
            mergePass(tempA,A,N,k);
            k *= 2;
        }
        free(tempA);
    }else{
        printf("out of RAM");
    }
}