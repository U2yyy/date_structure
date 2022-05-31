#include <stdio.h>
#include <stdlib.h>
//定义该动态数组
struct dynamicArray{
    void ** pArr;//这是一个指向数组的指针，负责维护
    int arr_size;//数组的元素个数
    int arr_capacity;//数组的容量
};
//这里的init_dynamicArray结构体定义为指针是为了传值给数组
struct dynamicArray *init_dynamicArray(int capacity){
    if(capacity <= 0)
        return NULL;
    //在堆上开辟空间给该动态数组使用
    struct dynamicArray  *Array= malloc(sizeof(struct dynamicArray));
    if(Array == NULL)
        return NULL;
    //在堆上开辟空间存储指向动态数组的元素的指针，方便维护
    Array->pArr = malloc(sizeof(void*)*capacity);
    Array->arr_capacity = capacity;
    Array->arr_size = 0;
}
int main() {
    struct dynamicArray *Array = init_dynamicArray(5);
    printf("size = %d\ncapacity = %d\n",Array->arr_size,Array->arr_capacity);
    return 0;
}
