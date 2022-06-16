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
	//ͷ�巨 
	p->Next = List->pHeader.Next;
	List->pHeader.Next = p;
	List->length++;
}
void sortof(LinkList* List,char firstAddress[5]){
	Node *p = List->pHeader.Next;
	Node *pAfter = p->Next;
	Node *pBefore = List->pHeader.Next;
	//�Ȱ�Ӧ���ǵ�һ�����Ľ�����ȥ
	while(p->Next != NULL){
		if(strcmp(p->Address,firstAddress) == 0){
			//�����������Ĺ�ϵ�����ﻭͼ�������� 
			pBefore->Next = p->Next;
			p->Next = List->pHeader.Next;
			List->pHeader.Next = p;
			break;
		}
		//������� 
		pBefore = p;
		p = p->Next;
	}
	//��p����ָ�ص�һ�������ݵĵ�
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
				//��ʱ�����˳��ڲ�ѭ���� 
				break;
			}
			slength--; 
			pAfter = pAfter->Next;			
		}
		//��������ƶ���˫ָ��˼�룩
		pBefore = p;
		p = p->Next;
		pAfter = p->Next;
		length--;
		//������ʱ��pAfter->NextAddress == -1,˵���Ѿ����������
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
	//��ʼ������
	LinkList *myList = init_LinkList();
	char firstAddress[5];
	int NodeNum;
	int ReverseNum;
	cin>>firstAddress>>NodeNum>>ReverseNum;
	//�Ȱ����е������������� 
	for(int i=0;i<NodeNum;i++){
		insert(myList);
	}
	cout<<"------------------------------"<<endl;
	sortof(myList,firstAddress);
	foreach(myList);
	return 0;
}
