#include<stdio.h>

void MakeHeap(int A[],int N);
void PercDown(int A[],int i,int N);
void PopHeap(int A[],int N);
void Swap(int *a,int *b);

int main(){
    int a[] = {1,2,3,4,5,9,8,7,11,28,34,84,67,99,112};
    const int len = sizeof(a)/sizeof(a[0]);
    MakeHeap(a,len);
    int tempLen = len;
    for(int i=0;i<len;i++){
        printf("%d ",a[i]);
    }
    printf("\n---------------------------------------\n");
    for(int i=0;i<len;i++){
        PopHeap(a,tempLen--);
    }
    for(int i=0;i<len;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
void PercDown(int A[],int i,int N){
    int temp = A[i];
    int Parent,Child;
    for(Parent = i;Parent*2<=N-1;){
        Child = Parent*2;
        if(Child<N-1&&A[Child+1]>A[Child])
            Child++;
        if(temp >= A[Child])
            break;
        A[Parent] = A[Child];
        Parent = Child;
    }
    A[Parent] = temp;
}
void MakeHeap(int A[],int N){
    for(int i=N/2;i>=0;i--){
        PercDown(A,i,N);
    }
}
void PopHeap(int A[],int N){
	Swap(&A[0],&A[N-1]);
	PercDown(A,0,N-1);
}
void Swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}