#include<stdio.h>
#include<stdlib.h>

void merge(int A[],int tempA[],int l,int r,int rEnd){
    int lEnd = r - 1;
    int k = l;
    int num = rEnd - l + 1;
    while(l <= lEnd&&r <= rEnd){
        if(A[l] <= A[r])
            tempA[k++] = A[l++];
        else
            tempA[k++] = A[r++];
    }
    while (l <= lEnd)
    {
        tempA[k++] = A[l++];
    }
    while(r <= rEnd){
        tempA[k++] = A[r++];
    }
    for(int i=0;i<num;i++,rEnd--){
        A[rEnd] = tempA[rEnd--];
    }
}

void mSort(int A[],int tempA[],int l,int rEnd){
    int center;
    if(l < rEnd){
        center = (rEnd + l) / 2;
        mSort(A,tempA,l,center);
        mSort(A,tempA,center+1,rEnd);
        merge(A,tempA,l,center+1,rEnd);
    }
}

void mergeSort(int A[],int N){
    int* tempA = malloc(sizeof(int)*N);
    if(tempA){
        mSort(A,tempA,0,N-1);
        free(tempA);
    }else{
        printf("out of RAM");
    }
}