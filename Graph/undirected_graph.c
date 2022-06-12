//
// Created by Programmer on 2022/6/12.
//
//定义最大顶点数量
#define MaxVertex 10
#include <stdio.h>
#include <string.h>
//定义顶点名称
typedef char VertexInfo[9];
//定义边的关系数组
typedef int EdgeInfo[MaxVertex][MaxVertex];
//定义图的结构体
typedef struct graph{
    //定义图和边的数量
    int vertexNum;
    int edgeNum;
    //定义顶点（vertex）的名称,这里等价于char vertex[MaxVertex][9],即每一行对应的是一个顶点的名称
    VertexInfo vertex[MaxVertex];
    //定义二维数组用于定义边（edge）
    EdgeInfo Edge;
}MakeMyGraph;
//之前想直接用&引用，发现不能用，查阅资料之后发现这个好像是c++特有的功能，因此我们还是往里面传指针
int findLocation(MakeMyGraph *graph,VertexInfo v){
    int temp = -1;
    for(int i=0;i<graph->vertexNum;i++){
        if(strcmp(graph->vertex[i],v) == 0)
            temp = i;
    }
    return temp;//若返回值为-1说明没找到
}
void test1(){
    MakeMyGraph myGraph;
    printf("请输入顶点（vertex）的数量和边（edge）的数量：\n");
    scanf("%d %d",&myGraph.vertexNum,&myGraph.edgeNum);
    printf("请依次输入每个顶点的名称\n");
    for(int i=0;i<myGraph.vertexNum;i++){
        scanf("%s",myGraph.vertex[i]);
    }
    //初始化所有边的值
    for(int i=0;i<myGraph.edgeNum;i++){
        for(int j=0;j<myGraph.edgeNum;j++){
            myGraph.Edge[i][j] = 0;
        }
    }
    for(int i=0;i<myGraph.edgeNum;i++) {
        printf("请依次输入两个顶点来表示两个点具有关系\n");
        VertexInfo temp1, temp2;//定义两个临时变量储存输入值
        scanf("%s %s", temp1, temp2);
        int v1 = findLocation(&myGraph, temp1);
        int v2 = findLocation(&myGraph, temp2);
        //对于无向图，如果输入的这两个定点存在，那么对两个顶点来说肯定是相连关系
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