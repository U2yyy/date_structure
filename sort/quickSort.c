#include<stdio.h>

void Swap(int* a,int* b);
int median3(int A[],int left,int right);
void qSort(int A[],int left,int right);
void quickSort(int A[],int N);

int main(){
    int a[] = {-99,-3,-999,-2212,1,3,55,9,12,3,4,90,0,12,32};
    const int length = sizeof(a)/sizeof(a[0]);
    quickSort(a,length);
    for(int i=0;i<length;i++){
        printf("%d ",a[i]);
    }
    return 0;
}

void Swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
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
void qSort(int A[],int left,int right){
    /* 
    如果不想使用限流的做法的话，可以设置这样一个返回条件
    当然，100以下的数据用别的排序效率会更好
     */
    if(right-left<=1)
        return;
    int pivot = median3(A,left,right);
    int i = left;
    int j = right-1;
    for(;;){
        while(A[++i]<pivot){}
        while(A[--j]>pivot){}
        if(i<j)
            Swap(&A[i],&A[j]);
        else
            break;
    }
    Swap(&A[i],&A[right-1]);
    qSort(A,left,i);
    qSort(A,i+1,right);
}

void quickSort(int A[],int N){
    qSort(A,0,N-1);
}