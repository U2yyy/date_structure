#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 1024
//定义该数组的数据结构
struct SStack{
    void* date[MAX];
    //m_size用于存储元素个数，便于出入栈的操作
    int m_size;
};
//初始化该栈
void* init_Stack(){
    struct SStack *myStack = malloc(sizeof(struct SStack));
    if(myStack == NULL)
        return NULL;
    //调用memset用于初始化所有数组里面的值
    memset(myStack->date,0, sizeof(void*)*MAX);
    myStack->m_size = 0;
    return myStack;
}
//void*看起来太抽象，不好理解，我们把它用好挺好理解的名字定义掉
typedef void* makeStack;
//实现入栈操作
void push_Stack(makeStack Stack,void* date){
    //还原Stack数据类型
    struct SStack *myStack = Stack;
    if(date == NULL)
        return;
    if(myStack == NULL)
        return;
    //容易忽略的一点是数组越界是有可能出现的，应该避免
    if(myStack->m_size == MAX)
        return;
    //入栈
    myStack->date[myStack->m_size] = date;
    //更新元素个数
    myStack->m_size++;
}
//实现出栈操作
void pop_Stack(makeStack Stack){
    //还原Stack数据类型
    struct SStack *myStack = Stack;
    if(myStack == NULL)
        return;
    if(myStack->m_size == 0)
        return;
    //出栈
    myStack->date[myStack->m_size-1] = NULL;
    //更新元素个数
    myStack->m_size--;
}
//返回栈顶
void* top_ele(makeStack Stack){
    //还原Stack数据类型
    struct SStack *myStack = Stack;
    if(myStack == NULL)
        return NULL;
    if(myStack->m_size == 0)
        return NULL;
    return myStack->date[myStack->m_size-1];
}
//判断栈是否为空
int isEmpty(makeStack Stack){
    //还原Stack数据类型
    struct SStack *myStack = Stack;
    if(myStack == NULL || myStack->m_size == 0)
        return 1;
    else
        return 0;
}
//返回栈的元素个数
int amounts(makeStack Stack){
    //还原Stack数据类型
    struct SStack *myStack = Stack;
    if(myStack == NULL || myStack->m_size == 0)
        return 0;
    else
        return myStack->m_size;
}
//定义用户的数据结构
struct tea{
    char color[10];
    int score;
};
//定义一个输出函数（用户的数据不好用%输出）
void myPrint(void* date){
    struct tea *p = date;
    printf("color: %s   score: %d\n",p->color,p->score);
}
//销毁操作
void destroy(makeStack Stack){
    //还原
    struct SStack *myStack = Stack;
    while(top_ele(myStack) != NULL){
        pop_Stack(myStack);
    }
    free(myStack);
}
int main(){
    //初始化我的栈
    makeStack myStack = init_Stack();
    //定义用户自己的数据
    struct tea redtea = {"red",5};
    struct tea blacktea = {"black",3};
    struct tea greentea = {"green",4};
    //实现入栈操作
    push_Stack(myStack,&redtea);
    push_Stack(myStack,&blacktea);
    push_Stack(myStack,&greentea);
    //返回栈顶元素
    struct tea * top = top_ele(myStack);
    myPrint(top);
    //出栈
    pop_Stack(myStack);
    //再次返回栈顶元素，查看出栈操作是否正常
    struct tea * top2 = top_ele(myStack);
    myPrint(top2);
    //返回栈总元素个数
    printf("amounts of element is:%d\n", amounts(myStack));
    //销毁该栈
    destroy(myStack);
    printf("amounts of element is:%d\n", amounts(myStack));
    if(isEmpty(myStack) == 1){
        printf("now U destroy the Stack");
    }
    return 0;
}