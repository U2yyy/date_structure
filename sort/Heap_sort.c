#include<stdio.h>
#include<windows.h>

void HeapAdjust(int *a,int s,int length);
void swap(int *a,int m,int n);

int main(){
    int a[] = {99,19,2,98,103,3,9,20,78,201,88,9,23,46,77,59,67,69,75,38};
    int length = sizeof(a)/sizeof(a[0]);
    for(int i=length/2;i>=0;i--)
    {
        HeapAdjust(a,i,length);
    }
    for(int i=length;i>0;i--)
    {
        swap(a,0,i-1);
        HeapAdjust(a,0,i-2);
    }
    /* Show the result of Heap_sort */
    for(int i=0;i<length;i++)
    {
        printf("%d ",a[i]);
    }
    system("pause");
}

void HeapAdjust(int *a,int s,int length)
{
    int temp = a[s];
    for(int j=s*2;j<=length;j*=2)
    {
        if(j<length&&a[j+1]>a[j])
            j++;
        if(temp>=a[j])
            break;
        a[s] = a[j];
        s = j;
    }
    a[s] = temp;
}

void swap(int *a,int m,int n)
{
    int temp = a[m];
    a[m] = a[n];
    a[n] = temp;
}