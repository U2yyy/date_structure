//
// Created by Programmer on 2022/5/31.
//
#include <stdlib.h>
#include <stdio.h>

struct dynamicArray{
    void ** pArr;
    int ele_size;
    int ele_capacity;
};

struct dynamicArray *initdynamicArray(int capacity){
    struct dynamicArray *Array = malloc(sizeof(struct dynamicArray));
    Array->ele_capacity = capacity;
    Array->ele_size = 0;
    Array->pArr = malloc(sizeof(void*)*capacity);
}

int main(){
    struct dynamicArray *Array = initdynamicArray(5);
    printf("%d%d",Array->ele_size,Array->ele_capacity);
    return 0;
}