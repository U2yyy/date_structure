#include<stdio.h>

int median3(int A[],int left,int right);
void Swap(int *a,int *b);
void qSort(int A[],int left,int right);
void quickSort(int A[],int N);

int main(){
    int a[] = {-99,1,3,55,9,12,3,4,90,0,12,32};
    const int length = sizeof(a)/sizeof(a[0]);
    quickSort(a,length);
    for(int i=0;i<length;i++){
        printf("%d ",a[i]);
    }
    return 0 ;
}

int median3(int A[],int left,int right){
    int center = (left+right)/2;
    if(A[left]>A[center])
        Swap(&A[left],&A[center]);
    if(A[left]>A[right])
        Swap(&A[left],&A[right]);
    if(A[center]>A[right])
        Swap(&A[center],&A[right]);
    Swap(&A[center],&A[right-1]);
    return A[right-1];
}

void Swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void qSort(int A[],int left,int right){
    if(right>left){
        int pivot = median3(A,left,right);
        int i = left;
        int j = right-1;
        while(1){
            while(A[++i]<pivot){}
            while(A[--j]>pivot){}
            if(i<j){
                Swap(&A[i],&A[j]);
            }else{
                break;
            }
        }
        Swap(&A[i],&A[right-1]);
        qSort(A,left,i-1);
        qSort(A,i+1,right);
    }
}

void quickSort(int A[],int N){
    qSort(A,0,N-1);
}