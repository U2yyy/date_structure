#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    struct Node* next;
    char* data;
} Node;

Node* init(){
    Node* pHeader = (Node*)malloc(sizeof(Node));
    pHeader->next = NULL;
    if(!pHeader)
        return NULL;
    return pHeader;
}

void insert(Node* pHeader,char* data){
    //ͷ�巨 
    /* Node* p = (Node*)malloc(sizeof(Node));
    p->data = data;
    p->next = pHeader->next;
    pHeader->next = p; */
    //β�巨 
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = data;
    Node* pOld = pHeader;
    while(pOld->next != NULL){
        pOld = pOld->next;
    }
    p->next = pOld->next;
    pOld->next = p;
}

void* myPrint (void* node){
    Node* realNode = node;
    printf("-%s-",realNode->data);
}

void showData(Node* pHeader,void *myPrint(void*)){
    Node* p = pHeader->next;
    while(p != NULL){
        myPrint(p);
        p = p->next;
    }
}
//ʵ�������������ת���� 
void reverse(Node* pHeader){
	Node* newp = pHeader->next;
	Node* old = pHeader->next->next;
	while(old != NULL){
		Node* temp = old->next;
		old->next = newp;
		newp = old;
		old = temp;
	}
	pHeader->next->next = NULL;
	pHeader->next = newp;
}

int main(){
    Node* Linklist = init();
    insert(Linklist,"hello");
    insert(Linklist,"world");
    insert(Linklist,"U2yyy");
    showData(Linklist,myPrint);
    printf("\n--------\n");
    reverse(Linklist);
    showData(Linklist,myPrint);
    return 0;
}
