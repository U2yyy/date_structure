#include <stdio.h>
#include <windows.h>

void heapAdjust(int *arr,int i,int length);
void swap(int *arr,int m,int n);

int main()
{
    int a[] = {22,90,10,39,48,84,92,20,30,101,30,42,40,26,46};
    int length = sizeof(a)/sizeof(a[0]);
    for(int i=length/2;i>=0;i--)
    {
        heapAdjust(a,i,length);
    }
    for(int i=0;i<length;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n---------------------\n");
    int k = 1;
    for(int i=length-1;i>0;i--)
    {   
        printf("\n number: %d  i : %d\n",k++,i);
        printf("\n---------------------\n");
        swap(a,0,i);//这里传的i是下标i，因此length-1刚刚正确
        printf("swaped:  ");
        for(int j=0;j<length;j++)
        {
            printf("%d ",a[j]);
        }
        printf("\n---------------------\n");
        heapAdjust(a,0,i);//这里传的i应该是数组长度，因为刚刚swap操作后操作数组的长度就应该减去，因此就这样传也是没问题的
        printf("heapAdjusted: ");
        for(int j=0;j<length;j++)
        {
            printf("%d ",a[j]);
        }
        printf("\n---------------------\n");
    }
    for(int i=0;i<length;i++)
    {
        printf("%d ",a[i]);
    }
    system("pause");
    return 0;
}

void heapAdjust(int *arr,int i,const int length)
{   
    int temp = arr[i];
    int j;
    for( ;i*2+1<=length-1; )
    {
        j = 2*i+1;
        if(j<length-1&&arr[j+1]>arr[j])
            j++;
        if(temp>arr[j])
            break;
        arr[i] = arr[j];
        i = j;
    }
    arr[i] = temp;
}

void swap(int *arr,int m,int n)
{
    int temp = arr[m];
    arr[m] = arr[n];
    arr[n] = temp;
}