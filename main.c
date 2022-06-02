#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 //定义链表的结点
 struct LinkNode{
    void* date;
    struct LinkNode *next;
};
//定义一个结构体为整个链表，在这个结构体中把头结点定义出来
struct LinkList{
    //定义头结点
    struct LinkNode pHeader;
    //定义链表的长度
    int size;
};
//这里用typedef定义void*为linklist，使得整个数据被封装好
typedef void* linklist;
//初始化链表
linklist init_LinkList(){
    //先为整个链表开辟内存
    struct LinkList *myList = malloc(sizeof(struct LinkList));
    myList->pHeader.date = NULL;
    myList->pHeader.next = NULL;
    myList->size = 0;
    return myList;
}
//插入元素
void insert_LinkList(linklist list,int pos,void* date){
    if(list == NULL)
        return;
    if(date == NULL)
        return;
    //还原链表结点，使我们能够访问它的成员
    struct LinkList *myList = list;
    //将不合法的位置转换为合法位置，这里采用尾插
    if(pos<0||pos>myList->size)
        pos = myList->size;
    //遍历到需要插入结点
    struct LinkNode *pCurrent = &myList->pHeader;
    for(int i=0;i<pos;i++){
        pCurrent = pCurrent->next;
    }
    struct LinkNode *newNode = malloc(sizeof(struct LinkNode));
    newNode->date = date;
    newNode->next = pCurrent->next;
    pCurrent->next = newNode;
    myList->size++;
}
//定义用户自己的结构体
struct PC{
    char name[99];
    double price;
    char comment[99];
};
//定义回调函数
void myPrintPC(void* date){
    struct PC *mydate = date;
    printf("Brand:%10s  Price:%15.2f  comment:%s\n",mydate->name,mydate->price,mydate->comment);
}
//遍历的实现
void foreach_LinkList(linklist list,void(*myPrint)(void*)){
    //先把链表还原
    struct LinkList *myList = list;
    struct LinkNode *pCurrent = myList->pHeader.next;
    for(int i=0;i<myList->size;i++){
        myPrint(pCurrent->date);
        pCurrent = pCurrent->next;
    }
}
 int main() {
    linklist myList = init_LinkList();
    //输入数据
    struct PC pc1 ={"Lenovo",4999,"just-so-so"};
    struct PC pc2 ={"Dell",6799,"enough to work and play"};
    struct PC pc3 ={"Alienware",29999,"too expensive but really nice to use"};
    struct PC pc4 ={"HP",13999,"my first own computer,very powerful"};
    struct PC pc5 ={"ASUS",15999,"the lowest Performance-to-Price Ratio"};
    //插入数据
    insert_LinkList(myList,0,&pc1);
    insert_LinkList(myList,0,&pc2);
    insert_LinkList(myList,1,&pc3);
    insert_LinkList(myList,2,&pc4);
    insert_LinkList(myList,1,&pc5);
    //遍历
    foreach_LinkList(myList,myPrintPC);
    return 0;
}
