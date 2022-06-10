//
// Created by Programmer on 2022/6/11.
//
#include <stdio.h>
void insert_sort(int *a,int length){
    for(int i=1;i<length;i++){
        //在这里就定义j是为了能把j的值传出下面的那个循环体
        int j = 0;
        //如果a[i]的前一个数比它大说明需要进行插入排序
        if(a[i-1]>a[i]) {
            int temp = a[i];
            //下面的temp>a[j]不好理解，意思是直到temp比数组元素大都继续右移数组，即让temp插到
            for (j=i-1;temp<a[j] && j>=0;j--) {
                //数组到插入位置前进行后移操作，以便插入数据
                a[j+1] = a[j];
            }
            //这里的a[j+1]即为应该被插入的地方,为什么是j+1呢，因为最后一次数组移动后进行了j--的操作
            a[j+1] = temp;
        }
    }
}
void myPrint(int *a,int length){
    for(int i=0;i<length;i++){
        printf("%d ",a[i]);
    }
}
int main(){
    int arr[] = {9,10,99,88,12,19,2,82,56};
    int length = sizeof(arr) / sizeof(int);
    myPrint(arr,length);
    printf("\n--------------------------------\n");
    insert_sort(arr,length);
    myPrint(arr,length);
    return 0;
}