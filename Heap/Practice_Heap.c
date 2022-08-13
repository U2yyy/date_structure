#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#define MAXDATA 1000
struct heap
{
    int *dataArr;
    int size;
    int capacity;
};
typedef struct heap* MaxHeap;

MaxHeap init_heap(int mysize);
void insert_heap(MaxHeap h,int data);
int delete_heap(MaxHeap h);

int main()
{
    MaxHeap h = init_heap(10);
    for(int i=0;i<10;i++)
    {
        insert_heap(h,rand()%100);
    }
    for(int i=1;i<=10;i++)
    {
        printf("%d ",h->dataArr[i]);
    }
    int max = delete_heap(h);
    printf("\n-----------\n the max element: %d \n",max);
    for(int i=1;i<=9;i++)
    {
        printf("%d ",h->dataArr[i]);
    }
    system("pause");
    return 0;
}

MaxHeap init_heap(int mysize)
{
    MaxHeap H = (MaxHeap)malloc(sizeof(struct heap));
    H->dataArr = (int*)malloc(sizeof(int)*(mysize+1));
    H->capacity = mysize;
    H->size = 0;
    H->dataArr[0] = MAXDATA;
    return H;
}

void insert_heap(MaxHeap h,int data)
{
    int j = ++h->size;
    /* 这里一定是j/2，要与父元素做比较以决定是否进行挪移 */
    for( ;j>1&&h->dataArr[j/2] < data;j/=2)
    {
        h->dataArr[j] = h->dataArr[j/2];
    }
    h->dataArr[j] = data;
}

int delete_heap(MaxHeap h)
{
    int target = h->dataArr[1];
    int temp = h->dataArr[h->size--];
    int p,c;
    for(p=1;p*2<=h->size;p=c)
    {
        c = 2*p;
        if(h->dataArr[c+1]>h->dataArr[c]&&c<h->size)
            c++;
        if(temp>=h->dataArr[c])
            break;
        h->dataArr[p] = h->dataArr[c];
    }
    h->dataArr[p] = temp;
    return target;
}