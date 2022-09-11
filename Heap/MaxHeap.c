#include<stdio.h>

#define MaxWeight 1000

struct MyHeap{
	int *weight;
	int size;
	int capacity;
};

typedef struct MyHeap *MaxHeap;

MaxHeap init_MaxHeap(int MaxSize);//��ʼ������ 
void Insert_MaxHeap(MaxHeap H,int MyWeight);//����
int Delete_MaxHeap(MaxHeap H);//ɾ�� 

int main(){
	
}

MaxHeap init_MaxHeap(int MaxSize){
	MaxHeap H = malloc(sizeof(struct MyHeap));
	H->weight = malloc(sizeof(int)*(MaxSize+1));
	H->weight[0] = MaxWeight;
	H->size = 0;
	H->capacity = MaxSize;
	return H;
}

void Insert_MaxHeap(MaxHeap H,int MyWeight){
	int i;
	i = ++H->size;
	//���ﻹ���б�Ҫдһ���ж϶��Ƿ���������������ʽ 
	for( ;MyWeight > H->weight[i/2];i /= 2){
		H->weight[i] = H->weight[i/2];
	}
	H->weight[i] = MyWeight;
}

int Delete_MaxHeap(MaxHeap H){
	int MaxItem = H->weight[1];
	int temp = H->weight[H->size--];
	int Parent,Child;
	for(Parent = 1;Parent*2 <= H->size;Parent = Child){
		Child = 2*Parent;
		if(Child != H->size&&H->weight[Child]<H->weight[Child+1])
			Child++;
		if(H->weight[Child]<temp)
			break;
		else
			H->weight[Parent] = H->weight[Child];
	}
	H->weight[Parent] = temp;
	return MaxItem;
}
