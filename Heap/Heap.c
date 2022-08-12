#include<stdio.h>
#include<windows.h>
#define MAXDATA 9999
struct Heap
{
    int *arr;
    int size;
    int capacity;
};
typedef struct Heap *MaxHeap;

MaxHeap init_Heap(int mysize);
int delete_Heap(MaxHeap H);
void insert_Heap(MaxHeap H,int data);

int main()
{
    MaxHeap H = init_Heap(10);
    insert_Heap(H,10);
    insert_Heap(H,103);
    insert_Heap(H,33);
    insert_Heap(H,14);
    insert_Heap(H,123);
    insert_Heap(H,222);
    insert_Heap(H,12);
    insert_Heap(H,1);
    insert_Heap(H,144);
    insert_Heap(H,34);
    for(int i=1;i<=H->size;i++)
    {
        printf("%d ",H->arr[i]);
    }
    int Max = delete_Heap(H);
    printf("\nthe max element of the arr is %d",Max);
    printf("\n------------------------------------\n");
    for(int i=1;i<=H->size;i++)
    {
        printf("%d ",H->arr[i]);
    }
    system("pause");
}

MaxHeap init_Heap(int mysize)
{
    MaxHeap H = (MaxHeap)malloc(sizeof(struct Heap));
    H->arr = (int*)malloc(sizeof(int)*(mysize+1));
    H->capacity = mysize;
    H->size = 0;
    H->arr[0] = MAXDATA;
    return H;
}

void insert_Heap(MaxHeap H,int data)
{
    int i = ++H->size;
    for( ;H->arr[i/2]<=data;i/=2)
    {
        H->arr[i] = H->arr[i/2];
    }
    H->arr[i] = data;
}

int delete_Heap(MaxHeap H)
{
    int Parent,Child;
    int temp = H->arr[H->size--];
    int target = H->arr[1];
    for(Parent = 1;Parent*2 <= H->size;Parent = Child)
    {
        Child = Parent*2;
        if(Child<H->size&&H->arr[Child+1]>H->arr[Child])
            Child++;
        if(H->arr[Child]<=temp)
            break;
        H->arr[Parent] = H->arr[Child];
    }
    H->arr[Parent] = temp;
    return target;
}