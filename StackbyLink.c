//
// Created by Programmer on 2022/6/7.
//
#include <stdio.h>
#include <stdlib.h>
//定义链表结点结构体
struct Node{
    struct Node *next;
};
//定义链表结构体，这里只维护链表的指针量，其余数据由用户自己维护
struct LStack{
    struct Node pHeader;
    int size;
};
//将返回值定义为容易理解的量
typedef void* makeStack;
//初始化函数
makeStack init_LStack(){
    struct LStack *myStack = malloc(sizeof(struct LStack));
    if(myStack == NULL)
        return NULL;
    myStack->size = 0;
    myStack->pHeader.next = NULL;
    return myStack;
}
//入栈（实质上是头插）
void push_LStack(makeStack Stack,void* date){
    //还原数据类型
    struct LStack *myStack = Stack;
    if(myStack == NULL || date == NULL)
        return;
    //数据的前四个字节是用来存储指针的，这里还原
    struct Node *p = date;
    //改变数据之间的关系，进行头插
    p->next = myStack->pHeader.next;
    myStack->pHeader.next = p;
    //更新size
    myStack->size++;
}
//出栈（实质上是头删）
void pop_LStack(makeStack Stack){
    //还原
    struct LStack *myStack = Stack;
    if(myStack == NULL || myStack->size == 0 || myStack->pHeader.next == NULL)
        return;
    //表示出要删除的结点
    struct Node *delNode = myStack->pHeader.next;
    //改变数据间的关系，进行头删
    myStack->pHeader.next = delNode->next;
    delNode->next = NULL;
    //这里不用进行free，因为并没有在堆上为数据开辟内存
    //直接进行size的更新即可
    myStack->size--;
}
//返回栈顶元素
void* top_ele(makeStack Stack){
    //还原
    struct LStack *myStack = Stack;
    if(myStack == NULL || myStack->pHeader.next == NULL || myStack->size == 0)
        return NULL;
    //这里实质上返回的是用户数据的前四个字节，即用于存储指针的地方
    return myStack->pHeader.next;
}
//返回栈的元素个数
int amount_ele(makeStack Stack){
    //还原
    struct LStack *myStack = Stack;
    if(myStack == NULL)
        return -1;
    return myStack->size;
}
//判断栈是否为空
int isEmpty(makeStack Stack){
    //还原
    struct LStack *myStack = Stack;
    if(myStack == NULL)
        return -1;
        else if(myStack->pHeader.next == NULL || myStack->size == 0)
            return 1;
            else
                return 0;
}
//销毁栈
void destroy(makeStack Stack){
    //其实可以直接free掉，但是这样free可能造成size不变的情况，因此这里还原数据后再free
//    struct LStack *myStack = Stack;
    if(Stack == NULL)
        return;
//    while(myStack->size > 0){
//        pop_LStack(myStack);
//    }
//    free(myStack);
//    myStack = NULL;
    free(Stack);
}
//用户的数据类型
typedef struct{
    void *p;
    char name[99];
    int score;
}myTea;
//用户自己的输出函数
void myPrint(void* date){
    myTea *p = date;
    printf("name:%s  score:%d\n",p->name,p->score);
}
int main(){
    myTea Greentea = {NULL,"Greentea",8};
    myTea Redtea = {NULL,"Redtea",9};
    myTea Blacktea = {NULL,"Blacktea",5};
    myTea Teamilk = {NULL,"Tea mixed with milk",2};
    struct LStack *myStack = init_LStack();
    push_LStack(myStack,&Greentea);
    push_LStack(myStack,&Redtea);
    push_LStack(myStack,&Blacktea);
    push_LStack(myStack,&Teamilk);
    myPrint(top_ele(myStack));
    pop_LStack(myStack);
    myPrint(top_ele(myStack));
    if(isEmpty(myStack) == 0)
        printf("Ur Stack is working well\n");
    printf("%d", amount_ele(myStack));
//    pop_LStack(myStack);
//    pop_LStack(myStack);
//    if(isEmpty(myStack) == 1)
//        printf("There is no element in Ur Stack\n");
//    push_LStack(myStack,&Greentea);
//    destroy(myStack);
//    if(isEmpty(myStack) == -1)
//        printf("Ur Stack has been destroyed\n");

//isEmpty函数似乎有点问题，不能正确判断是否为空
    return 0;
}