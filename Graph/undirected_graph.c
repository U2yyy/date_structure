//
// Created by Programmer on 2022/6/12.
//
//������󶥵�����
#define MaxVertex 10
#include <stdio.h>
#include <string.h>
//���嶥������
typedef char VertexInfo[9];
//����ߵĹ�ϵ����
typedef int EdgeInfo[MaxVertex][MaxVertex];
//����ͼ�Ľṹ��
typedef struct graph{
    //����ͼ�ͱߵ�����
    int vertexNum;
    int edgeNum;
    //���嶥�㣨vertex��������,����ȼ���char vertex[MaxVertex][9],��ÿһ�ж�Ӧ����һ�����������
    VertexInfo vertex[MaxVertex];
    //�����ά�������ڶ���ߣ�edge��
    EdgeInfo Edge;
}MakeMyGraph;
//֮ǰ��ֱ����&���ã����ֲ����ã���������֮�������������c++���еĹ��ܣ�������ǻ��������洫ָ��
int findLocation(MakeMyGraph *graph,VertexInfo v){
    int temp = -1;
    for(int i=0;i<graph->vertexNum;i++){
        if(strcmp(graph->vertex[i],v) == 0)
            temp = i;
    }
    return temp;//������ֵΪ-1˵��û�ҵ�
}
void test1(){
    MakeMyGraph myGraph;
    printf("�����붥�㣨vertex���������ͱߣ�edge����������\n");
    scanf("%d %d",&myGraph.vertexNum,&myGraph.edgeNum);
    printf("����������ÿ�����������\n");
    for(int i=0;i<myGraph.vertexNum;i++){
        scanf("%s",myGraph.vertex[i]);
    }
    //��ʼ�����бߵ�ֵ
    for(int i=0;i<myGraph.edgeNum;i++){
        for(int j=0;j<myGraph.edgeNum;j++){
            myGraph.Edge[i][j] = 0;
        }
    }
    for(int i=0;i<myGraph.edgeNum;i++) {
        printf("����������������������ʾ��������й�ϵ\n");
        VertexInfo temp1, temp2;//����������ʱ������������ֵ
        scanf("%s %s", temp1, temp2);
        int v1 = findLocation(&myGraph, temp1);
        int v2 = findLocation(&myGraph, temp2);
        //��������ͼ����������������������ڣ���ô������������˵�϶���������ϵ
        if (v1 != -1 && v2 != -1) {
            myGraph.Edge[v1][v2] = 1;
            myGraph.Edge[v2][v1] = 1;
        }
    }
}
int main(){
    test1();
    return 0;
}