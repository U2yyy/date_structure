#include<stdio.h>

void PercDown(int A[],int i,int N);
void MakeHeap(int A[],int N);
int PopHeap(int A[],int N);
void MakeHeap(int A[],int N);
void swap(int *a,int *b);

int main(){
    int a[] = {9999999999,1,9,8,7,9,8,4,82,99,213,98,102,329,222,114514,14514,1919};
    const int len = sizeof(a)/sizeof(a[0]) - 1;
    int tempLen = len;
    MakeHeap(a,len);
    for(int i=1;i<len;i++){
        printf("%d ",a[i]);
    }
    printf("\n-----------------\n");
    int tempA[len];
    for(int i=1;i<len;i++){
        tempA[i] = PopHeap(a,tempLen--);
    }
    for(int i=1;i<len;i++){
        printf("%d ",a[i]);
    }
    printf("\n-----------------\n");
    for(int i=1;i<len;i++){
        printf("%d ",tempA[i]);
    }
}

void PercDown(int A[],int i,int N){
    int Child,Parent;
    int temp = A[i];
    for(Parent = i;Parent*2<N;){
        Child = Parent*2;
        if(A[Child+1]>A[Child])
            Child++;
        if(temp >= A[Child])
            break;
        A[Parent] = A[Child];
        Parent = Child;
    }
    A[Parent] = temp;
}

void MakeHeap(int A[],int N){
    for(int i=N/2;i>0;i--){
        PercDown(A,i,N);
    }
}

int PopHeap(int A[],int N){
    int tar = A[1];
    swap(&A[1],&A[N]);
    PercDown(A,1,N-1);
    return tar;
}

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}