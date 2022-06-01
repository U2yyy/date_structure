//
// Created by Programmer on 2022/5/31.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

void insert_dynamicArray(struct dynamicArray* array,int pos,void *date){
    if(pos<0||pos>array->ele_size)
        pos = array->ele_size;
    if(array->ele_size == array->ele_capacity){
        int newCapacity = array->ele_capacity * 2;
        void ** newSpace = malloc(sizeof(void*)*newCapacity);
        memcpy(newSpace,array->pArr, sizeof(void*)*array->ele_capacity);
        free(array->pArr);
        array->pArr = newSpace;
        array->ele_capacity = newCapacity;
    }
    for(int i=array->ele_size;i>=pos;i--){
        array->pArr[i+1] = array->pArr[i];
    }
    array->pArr[pos] = date;
    array->ele_size++;
}

struct date_structure{
    int date;
    char name[99];
    char hard[99];
};

void myPrintdate(void* date){
    struct date_structure *p = date;
    printf("date is %d  name is %s  hard is %s\n",p->date,p->name,p->hard);
}

void foreach_dynamicArray(struct dynamicArray* array,void(*myPrint)(void*)){
    for(int i=0;i<array->ele_size;i++){
        myPrint(array->pArr[i]);
    }
}

int main(){
    struct dynamicArray *Array = initdynamicArray(5);
    printf("%d%d\n",Array->ele_size,Array->ele_capacity);
    struct date_structure date1 = {1,"dynamicArray","easy"};
    struct date_structure date2 = {2,"linklist","middle-level"};
    struct date_structure date3 = {3,"tree","hard"};
    insert_dynamicArray(Array,-1,&date1);
    insert_dynamicArray(Array,0,&date2);
    insert_dynamicArray(Array,3,&date3);
    foreach_dynamicArray(Array,myPrintdate);
    printf("%d%d\n",Array->ele_size,Array->ele_capacity);
    return 0;
}