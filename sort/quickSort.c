#include<stdio.h>

void Swap(int* a,int* b);
int median3(int A[],int left,int right);
void qSort(int A[],int left,int right);
void quickSort(int A[],int N);

int main(){
    int a[] = {680,459,761,813,84,322,891,156,752,771,683,961,347,513,321,168,643,455,264,234,219,541,90,302,493,472,844,653,857,616,560,34,858,425,263,905,164,470,120,374,405,576,956,193,78,967,641,230,247,146,346,865,987,475,327,450,698,986,739,222,817,823,377,568,524,925,474,941,143,94,933,724,656,391,315,677,573,434,647,107,385,121,29,135,895,988,756,935,303,61,763,398,356,257,500,787,5,12,68,676};
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
    if(left>=right)
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
    qSort(A,left,i-1);
    qSort(A,i+1,right);
}

void quickSort(int A[],int N){
    qSort(A,0,N-1);
}