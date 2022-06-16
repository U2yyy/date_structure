#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
struct Node{
	char Address[5];
	int Date;
	char NextAddress[5];
	Node *Next;
};
struct LinkList{
	Node pHeader;
	int length;
};
LinkList* init_LinkList(){
	LinkList *myList = (LinkList*)malloc(sizeof(LinkList));
	myList->length = 0;
	myList->pHeader.Next = NULL;
	if(myList == NULL)
		return NULL;
	return myList;
}
void insert(LinkList* List){
	Node *p = (Node*)malloc(sizeof(Node));
	cin>>p->Address>>p->Date>>p->NextAddress;
	//头插法 
	p->Next = List->pHeader.Next;
	List->pHeader.Next = p;
	List->length++;
}
void sortof(LinkList* List,char firstAddress[5]){
	Node *p = List->pHeader.Next;
	Node *pAfter = p->Next;
	Node *pBefore = List->pHeader.Next;
	//先把应该是第一个结点的结点接上去
	while(p->Next != NULL){
		if(strcmp(p->Address,firstAddress) == 0){
			//更改链表结点间的关系，这里画图会更好理解 
			pBefore->Next = p->Next;
			p->Next = List->pHeader.Next;
			List->pHeader.Next = p;
			break;
		}
		//往后递推 
		pBefore = p;
		p = p->Next;
	}
	//让p重新指回第一个存数据的点
	p = List->pHeader.Next;
	pAfter = p->Next;
	pBefore = p; 
	int length = List->length;
	while(length>0){
		int slength = length-1;
		while(slength>0){
			if(strcmp(p->NextAddress,pAfter->Address) == 0){
				pBefore->Next = pAfter->Next;
				pAfter->Next = p->Next;
				p->Next = pAfter;
				//此时可以退出内部循环了 
				break;
			}
			slength--; 
			pAfter = pAfter->Next;			
		}
		//整体向后移动（双指针思想）
		pBefore = p;
		p = p->Next;
		pAfter = p->Next;
		length--;
		//如果这个时候pAfter->NextAddress == -1,说明已经排序完毕了
		if(pAfter->NextAddress[0] == '-')
			break; 
	}
}
void foreach(LinkList* List){
	int length = List->length; 
	Node *p = List->pHeader.Next;
	while(length>0){
		cout<<p->Address<<" "<<p->Date<<" "<<p->NextAddress<<endl;
		p = p->Next;
		length--;
	}
}
int main(){
	//初始化链表
	LinkList *myList = init_LinkList();
	char firstAddress[5];
	int NodeNum;
	int ReverseNum;
	cin>>firstAddress>>NodeNum>>ReverseNum;
	//先把所有的链表连接起来 
	for(int i=0;i<NodeNum;i++){
		insert(myList);
	}
	cout<<"------------------------------"<<endl;
	sortof(myList,firstAddress);
	foreach(myList);
	return 0;
}
