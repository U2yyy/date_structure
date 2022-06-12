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
//根据位置删除结点
void deletebypos(linklist list,int pos){
    struct LinkList *myList = list;
    if(list == NULL)
        return;
    if(pos < 0 || pos > myList->size-1)
        return;
    struct LinkNode *pCurrent = &myList->pHeader;
    for(int i=0;i<pos;i++){
        pCurrent = pCurrent->next;
    }
    struct LinkNode *delNode = pCurrent->next;
    pCurrent->next = delNode->next;
    delNode->next = NULL;
    free(delNode);
    myList->size--;
}
//定义回调比较函数
int myComparebyvalue(void* date1,void* date2){
    struct PC *p1 = date1;
    struct PC *p2 = date2;
    if(strcmp(p1->name,p2->name)==0&&p1->price==p2->price)
        return 1;
    else
        return 0;
}
//根据值删除结点
void deletebyvalue(linklist list,void* date,int (*myCompare)(void*,void*)){
    if(list == NULL)
        return;
    if(date == NULL)
        return;
    struct LinkList *myList = list;
    struct LinkNode *pCurrent = myList->pHeader.next;
    struct LinkNode *pPre = &myList->pHeader;
    while(myCompare(pCurrent->date,date) != 1){
        pCurrent = pCurrent->next;
        pPre = pPre->next;
    }
    pPre->next = pCurrent->next;
    pCurrent->next = NULL;
    free(pCurrent);
    myList->size--;
}
//清除所有链表结点数据及释放空间
void clear(linklist list){
    if(list == NULL)
        return;
    struct LinkList *myList = list;
    struct LinkNode *pCurrent = myList->pHeader.next;
    for(int i=0;i<myList->size;i++){
        struct LinkNode *pmid = pCurrent;
        free(pCurrent);
        pCurrent = pmid;
        myList->size--;
    }
}
//销毁链表
void destroy(linklist list){
    if(list == NULL)
        return;
    clear(list);
    free(list);
}
//返回链表结点数
int retsize(linklist list){
    if(list == NULL)
        return NULL;
    struct LinkList *myList = list;
    return myList->size;
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
    deletebypos(myList,1);
    printf("--------------------------------------------------------------------------------------\n");
    foreach_LinkList(myList,myPrintPC);
    struct PC test1 = {"Lenovo",4999,"just-so-so"};
    deletebyvalue(myList,&test1,myComparebyvalue);
    printf("--------------------------------------------------------------------------------------\n");
    foreach_LinkList(myList,myPrintPC);
    printf("now the size of the Linklist is %d", retsize(myList));
    return 0;
}
//Cool