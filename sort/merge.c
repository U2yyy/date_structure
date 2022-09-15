#include<stdio.h>
#include<stdlib.h>

void merge(int A[],int tempA[],int rEnd,int r,int l);
void mSort(int A[],int tempA[],int rEnd,int l);
void mergeSort(int A[],int len);

int main(){
    int a[] = {0,99,28,92,17,27,33,67,90,12,91,77};
    const int len = sizeof(a)/sizeof(a[0]);
    mergeSort(a,len);
    for(int i=0;i<len;i++){
        printf("%d ",a[i]);
    }
}

void merge(int A[],int tempA[],int rEnd,int r,int l){
    int lEnd = r - 1;
    int k = l;
    int num = rEnd - l + 1;
    while(r<=rEnd && l<=lEnd){
        if(A[r]>A[l])
            tempA[k++] = A[r++];
        else
            tempA[k++] = A[l++];
    }
    while(r<=rEnd){
        tempA[k++] = A[r++];
    }
    while(l<=lEnd){
        tempA[k++] = A[l++];
    }
    for(int i=0;i<num;i++,rEnd--){
        A[rEnd] = tempA[rEnd]; 
    }
}

void mSort(int A[],int tempA[],int rEnd,int l){
    int center;
    if(l<rEnd){
        center = (l+rEnd)/2;
        mSort(A,tempA,center,l);
        mSort(A,tempA,rEnd,center+1);
        merge(A,tempA,rEnd,center+1,l);
    }
}

void mergeSort(int A[],int len){
    int* tempA = malloc(sizeof(int)*len);
    if(tempA!=NULL){
        mSort(A,tempA,len-1,0);
        free(tempA);
    }   
    else
        printf("out of RAM");
}