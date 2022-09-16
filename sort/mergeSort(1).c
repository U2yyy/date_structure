#include<stdio.h>
#include<stdlib.h>

void merge(int A[],int tempA[],int l,int rEnd,int r);
void mSort(int A[],int tempA[],int l,int rEnd);
void mergeSort(int A[],int len);

int main(){
    int a[] = {9,88,20,12,98,77,57,74,90,22,34,56,75,33};
    const int len = sizeof(a)/sizeof(a[0]);
    mergeSort(a,len);
    for(int i=0;i<len;i++){
        printf("%d ",a[i]);
    }
    return 0;
}

void merge(int A[],int tempA[],int l,int rEnd,int r){
    int lEnd = r - 1;
    int k = l;
    int num = rEnd - l + 1;
    while(l <= lEnd&&r <=rEnd){
        if(A[l] <= A[r]){
            tempA[k++] = A[l++]; 
        }else{
            tempA[k++] = A[r++];
        }
    }
    while(l <= lEnd){
        tempA[k++] = A[l++];
    }
    while(r <= rEnd){
        tempA[k++] = A[r++];
    }
    for(int i = 0;i < num;i++,rEnd--){
        A[rEnd] = tempA[rEnd];
    }
}

void mSort(int A[],int tempA[],int l,int rEnd){
    int center;
    if(l < rEnd){
        center = (l + rEnd)/2;
        mSort(A,tempA,l,center);
        mSort(A,tempA,center+1,rEnd);
        /* 下面的merge中参数r一定要填center+1，因为当从两个元素开始归并时，
            rEnd此时为1，center为0，如果把r=0作为参数传入merge中，则lEnd会变为-1，最后会造成数组越界
         */
        merge(A,tempA,l,rEnd,center+1);
    }
}

void mergeSort(int A[],int len){
    int* tempA = malloc(sizeof(int)*len);
    if(tempA!=NULL){
        mSort(A,tempA,0,len-1);
        free(tempA);
    }else{
        printf("out of RAM");
    }
}