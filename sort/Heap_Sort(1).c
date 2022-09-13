#include<stdio.h>

void PercDown(int A[],int p,int N);
void BuildHeap(int A[],int N);
void Swap(int *a,int *b);
int PopHeap(int A[],int N);

int main(){
    int a[] = {999999,9,10,28,92,11,28,83,92,32,46,78};
    int len = sizeof(a)/sizeof(a[0]) - 1;
    BuildHeap(a,len);
    /* for(int i=1;i<=len;i++){
        printf("%d ",a[i]);
    } */
    int k = 1;
    int tempA[len];
    int tempLen = len;
    for(int k=1;k<=len;k++){
        tempA[k] = PopHeap(a,tempLen--);
    }
    for(int i=1;i<=len;i++){
        printf("%d ",tempA[i]);
    } 
    return 0;
}


void PercDown(int A[],int p,int N){
    int temp = A[p];//将A[p]作为根节点，使其成为一个堆
    int Child,Parent;
    for(Parent=p;Parent*2<=N;){
        Child = Parent*2;
        if(Child<N&&A[Child+1]>A[Child])
            Child++;
        if(temp>=A[Child])
            break;
        A[Parent] = A[Child];
        Parent = Child;
    }
    A[Parent] = temp;
}
void BuildHeap(int A[],int N){
    for(int i=N/2;i>0;i--){
        PercDown(A,i,N);
    }
}
int PopHeap(int A[],int N){
    int tar = A[1];
    Swap(&A[1],&A[N]);
    BuildHeap(A,N-1);
    return tar;
}
void Swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}