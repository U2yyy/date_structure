#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
 
struct linkNode
{
    int data;
    struct linkNode *next;
};
typedef struct linkNode Node;
struct linkList
{
    Node pHeader;
    int length;
};
typedef struct linkList* List;

List init_linkList();
void insert_linkListbyTop(List mylist,int data);
void insert_linkListbyLast(List mylist,int data);
void forEach_linkList(List mylist);
void deletebyPos(List mylist,const int pos);

int main()
{
    List myList = init_linkList();
    insert_linkListbyLast(myList,10);
    insert_linkListbyLast(myList,20);
    insert_linkListbyTop(myList,99);
    forEach_linkList(myList);
    deletebyPos(myList,0);
    printf("\n--------------\n");
    forEach_linkList(myList);
    deletebyPos(myList,1);
    printf("\n--------------\n");
    forEach_linkList(myList);
    deletebyPos(myList,99);
    printf("\n--------------\n");
    forEach_linkList(myList);
    system("pause");
    return 0;
}


List init_linkList()
{
    List list = (List)malloc(sizeof(List));
    if(list==NULL)
        return NULL;
    list->length = 0;
    list->pHeader.data = -1;
    list->pHeader.next = NULL;
    return list;
}

void insert_linkListbyTop(List mylist,int data)
{
    /* 头插法 */
    if(!data||mylist==NULL)
        return;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = mylist->pHeader.next;
    mylist->pHeader.next = newNode;
    mylist->length++;
}

void insert_linkListbyLast(List mylist,int data)
{
    /* 尾插法 */
    if(!data||mylist==NULL)
        return;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    Node* pTmp = mylist->pHeader.next;
    /* 这里必须对这种特殊情况进行判定，否则就会造成野指针 */
    if(pTmp == NULL)
    {   
        newNode->next = pTmp;
        mylist->pHeader.next = newNode;
        mylist->length++;
    }else
        {
            while(pTmp->next != NULL)
            {
                pTmp = pTmp->next;
            }
            newNode->next = pTmp->next;
            pTmp->next = newNode;
            mylist->length++;
        }
}

void forEach_linkList(List mylist)
{
    Node* p = mylist->pHeader.next;
    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}

void deletebyPos(List mylist,const int pos)
{
    int i = 0;
    if(pos>mylist->length-1)
    {
        printf("out_of_range");
        return;
    }
    Node* pBefore = mylist->pHeader.next;
    Node* p = pBefore->next;
    if(pos == 0)
    {
        mylist->pHeader.next = pBefore->next;
        pBefore->next = NULL;
        free(pBefore);
        mylist->length--;
        return;
    }
    while(i != pos-1)
    {
        i++;
        pBefore = pBefore->next;
        p = pBefore->next;
    }
    pBefore->next = p->next;
    p->next = NULL;
    free(p);
    mylist->length--;
    return;
}