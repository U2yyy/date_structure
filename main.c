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
//定义一个用来初始化的数组，有点类似于函数的功能
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
    if(array->arr_size == array->arr_capacity){
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
//删除数组元素
    //按位置删除
void deletebypos_dynamicArray(struct dynamicArray *array,int pos){
    if(array == NULL)
        return;
    if(pos<0||pos>array->arr_size-1)
        return;
    for(int i=pos;i<array->arr_size;i++){
        array->pArr[i] = array->pArr[i+1];
    }
    array->arr_size--;
}
//定义回调函数用于比较
int myCompareval(void* date1,void* date2){
    struct Studentsore *p1 = date1;
    struct Studentsore *p2 = date2;

    if(strcmp(p1->name,p2->name)==0&&p1->score==p2->score)
        return 1;
    else
        return 0;
}
    //按元素删除，这里使用回调函数进行比较，因为比较两个指针是没有意义的
void deletebyval_dynamicArray(struct dynamicArray *array,void* date,int(myComepare)(void*,void*)){
    if(array == NULL)
        return;
    if(date == NULL)
        return;
    for(int i=0;i<array->arr_size;i++){
        if(myComepare(array->pArr[i],date))
            deletebypos_dynamicArray(array,i);
    }
}
//整个数组的销毁
void destroy(struct dynamicArray *array){
    if(array == NULL)
        return;
    if(array->pArr == NULL) {
        free(array->pArr);
        array->arr_size == NULL;
    }
    free(array);
    array == NULL;
}
int main() {
    int n;
    struct dynamicArray *Array = init_dynamicArray(5);
    printf("before adding:size = %d  capacity = %d\n",Array->arr_size,Array->arr_capacity);
    //数据处理
    struct Studentsore stu1 = {"yme",100};
    struct Studentsore stu2 = {"ljd",99};
    struct Studentsore stu3 = {"MC",10};
    struct Studentsore stu4 = {"QM",30};
    struct Studentsore stu5 = {"WXS",0};
    struct Studentsore stu6 = {"lbw",66};
    struct Studentsore stu7 = {"pdd",22};
    struct Studentsore stu8 = {"sekiro",101};
    //将数据插入
    insert_dynamicArray(Array,-1,&stu1);
    insert_dynamicArray(Array,0,&stu2);
    insert_dynamicArray(Array,4,&stu3);
    insert_dynamicArray(Array,20,&stu4);
    insert_dynamicArray(Array,99,&stu5);
    insert_dynamicArray(Array,2,&stu6);
    insert_dynamicArray(Array,3,&stu7);
    insert_dynamicArray(Array,0,&stu8);
    //遍历数据
    foreach_dynamicArray(Array,myPrintscore);
    //看一下数组的容量和元素个数是否更新
    printf("after adding:size = %d  capacity = %d\n",Array->arr_size,Array->arr_capacity);
    //按位置删除,pos=3,因此删除第四个元素
    deletebypos_dynamicArray(Array,3);
    printf("---------------------------------------\n");
    foreach_dynamicArray(Array,myPrintscore);
    printf("after deleting1:size = %d  capacity = %d\n",Array->arr_size,Array->arr_capacity);
    //按值删除元素
    printf("---------------------------------------\n");
    struct Studentsore badguy = {"WXS",0};
    deletebyval_dynamicArray(Array,&badguy,myCompareval);
    foreach_dynamicArray(Array,myPrintscore);
    printf("after deleting2:size = %d  capacity = %d\n",Array->arr_size,Array->arr_capacity);
    printf("---------------------------------------\n");
    //释放掉全部的内存空间，没有什么实际的效果，但是过一段时间也许就会被别的程序占用了
    destroy(Array);
    foreach_dynamicArray(Array,myPrintscore);
    printf("after destroy:size = %d  capacity = %d\n",Array->arr_size,Array->arr_capacity);
    return 0;
}
