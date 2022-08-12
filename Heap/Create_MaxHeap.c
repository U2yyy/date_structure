#include<stdio.h>
#include<windows.h>

void HeapAdjust(int *a,int s,int length);

int main()
{
    int a[] = {9,8,0,10,220,30,23,29,19};
    int length = sizeof(a)/sizeof(a[0]);
    for(int i=length/2;i>=0;i--)
    {
        HeapAdjust(a,i,length);
    }
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
        if(a[j]<=temp)
            break;
        a[s] = a[j];
        s = j;
    }
    a[s] = temp;
}