//
// Created by Programmer on 2022/6/12.
//
#include <stdio.h>
#include <string.h>
#define MaxVertex 10
//��������洢�Ƿ����
int visited[MaxVertex];
//�����ڽӵ�ṹ��
struct EdgeNode{
    //��¼�������λ��
    int position;
    //ָ���������ָ��
    struct EdgeNode *next;
};
//���춥��ṹ��
struct Vertex{
    //��������
    char name[99];
    //ָ���һ���ڽӵ��ָ��
    struct EdgeNode *first;
};
//���������ڽӱ�ͼ�Ľṹ��
struct LinkGraph{
    //����ÿ�����������
    struct Vertex vertex[MaxVertex];
    //�������
    int VertexNum;
    //������
    int EdgeNum;
};
int findLocation(struct LinkGraph *graph,char v[99]){
    int temp = -1;
    for(int i=0;i<graph->VertexNum;i++){
        if(strcmp(graph->vertex[i].name,v) == 0)
            temp = i;
        break;
    }
    return temp;//������ֵΪ-1˵��û�ҵ�
}
void DFS(struct LinkGraph *myGraph,int i){
    visited[i] = 1;
    printf("%s",myGraph->vertex[i].name);
    struct EdgeNode *p = myGraph->vertex[i].first;
    while(p){
        if(visited[p->position]==0)
            DFS(myGraph,p->position);
        p = p->next;
    }
}
void DFSreverse(struct LinkGraph *myGraph){
    for(int i=0;i<myGraph->VertexNum;i++){
        visited[i] = 0;
    }
    for(int i=0;i<myGraph->VertexNum;i++){
        if(visited[i]==0)
            DFS(myGraph,i);
    }
}
void test1(){
    struct LinkGraph myGraph;
    printf("�����붥�㣨vertex���������ͱߣ�edge����������\n");
    scanf("%d %d",&myGraph.VertexNum,&myGraph.EdgeNum);
    printf("����������ÿ�����������\n");
    for(int i=0;i<myGraph.VertexNum;i++){
        scanf("%s",myGraph.vertex[i].name);
        myGraph.vertex[i].first = NULL;
    }
    for(int i=0;i<myGraph.EdgeNum;i++) {
        char v1[99],v2[99];
        printf("�����뻥Ϊ�ڽӵ����������\n");
        scanf("%s%s",v1,v2);
        int temp1 = findLocation(&myGraph,v1);
        int temp2 = findLocation(&myGraph,v2);
        if(temp1!=-1&&temp2!=-1) {
            //�½����
            struct EdgeNode *newEdge;
            newEdge->position = temp2;
            //����ͷ�巨��Ч�ʸ���
            newEdge->next = myGraph.vertex[temp1].first;
            myGraph.vertex[temp1].first = newEdge;
        }
    }
    DFSreverse(&myGraph);
}
int main(){
    test1();
    return 0;
}