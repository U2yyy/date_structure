#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
//插入数组元素
void insert_dynamicArray(struct dynamicArray *array,int pos,void* date){
    //先针对非法的位置请求做处理，这里采用变为尾插的方法
    if(pos<0||pos>array->arr_size)
        pos = array->arr_size;
    //判断是否需要进行动态扩展
    if(pos == array->arr_capacity){
        //1.计算新空间大小
        int newCapacity = array->arr_capacity * 2;
        //2.分配新的内存空间
        void ** newSpace = malloc(sizeof(void*)*newCapacity);
        //3.拷贝
        memcpy(newSpace,array->pArr, sizeof(void*)*array->arr_capacity);
        //4.释放原内存空间
        free(array->pArr);
        //5.让数组指针指向正确的地方
        array->pArr = newSpace;
        //6.更新容量
        array->arr_capacity =newCapacity;
    }
    //进行数据插入
        //先把原来的数据进行右移
    for(int i=array->arr_size;i>=pos;i--){
        array->pArr[i+1] = array->pArr[i];
    }
        //进行数据的插入
    array->pArr[pos] = date;
    //更新数组元素个数
    array->arr_size++;
}
//定义一个结构体，例如成绩单
struct Studentsore{
    char name[99];
    int score;
};
//在这里定义一下我的回调函数
void myPrintscore(void *date){
    struct Studentsore *p = date;
    printf("name:%s  score:%d\n",p->name,p->score);
}
//数组元素遍历,这里使用了回调函数，让用户决定传入数据的类型
void foreach_dynamicArray(struct dynamicArray *array,void(* myPrint)(void*)){
    for(int i=0;i<array->arr_size;i++){
        myPrint(array->pArr[i]);
    }
}
int main() {
    int n;
    struct dynamicArray *Array = init_dynamicArray(5);
    printf("size = %d\ncapacity = %d\n",Array->arr_size,Array->arr_capacity);
    //数据处理
    struct Studentsore stu1 = {"yme",100};
    struct Studentsore stu2 = {"ljd",99};
    struct Studentsore stu3 = {"MC",10};
    //将数据插入
    insert_dynamicArray(Array,-1,&stu1);
    insert_dynamicArray(Array,0,&stu2);
    insert_dynamicArray(Array,4,&stu3);
    //遍历数据
    foreach_dynamicArray(Array,myPrintscore);
    return 0;
}
