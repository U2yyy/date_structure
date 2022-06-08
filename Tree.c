//
// Created by Programmer on 2022/6/8.
//
//创建树结点的结构体
#include <stdio.h>
struct TreeNode{
    char Cha;
    struct TreeNode *lChild;
    struct TreeNode *rChild;
};
//树结点占用的数据很少，不用初始化在堆上开辟内存
//遍历函数
void foreach_Tree(struct TreeNode *root){
    if(root == NULL)
        return;
    //这里采用中序遍历
    foreach_Tree(root->lChild);
    printf("%c",root->Cha);
    foreach_Tree(root->rChild);
}
//求树的叶子数量
void Leafnums(struct TreeNode *root,int *num){
    if(root == NULL)
        return;
    if(root->rChild == NULL && root->lChild == NULL)
        (*num)++;
    Leafnums(root->lChild,num);
    Leafnums(root->rChild,num);
}
//求树的深度
int TreeHeight(struct TreeNode *root){
    if(root == NULL)
        return 0;
    int lHeight = TreeHeight(root->lChild);
    int rHeight = TreeHeight(root->rChild);
    int height = lHeight > rHeight ? lHeight : rHeight;
    return height+1;
}
//创建一个测试函数
void test1(){
    //把树的各结点初始化
    struct TreeNode nodeA = {'A',NULL,NULL};
    struct TreeNode nodeB = {'B',NULL,NULL};
    struct TreeNode nodeC = {'C',NULL,NULL};
    struct TreeNode nodeD = {'D',NULL,NULL};
    struct TreeNode nodeE = {'E',NULL,NULL};
    struct TreeNode nodeF = {'F',NULL,NULL};
    struct TreeNode nodeG = {'G',NULL,NULL};
    struct TreeNode nodeH = {'H',NULL,NULL};
    //分配关系
    nodeA.lChild = &nodeB;
    nodeA.rChild = &nodeF;

    nodeB.rChild = &nodeC;

    nodeC.lChild = &nodeD;
    nodeC.rChild = &nodeE;

    nodeF.rChild = &nodeG;

    nodeG.lChild = &nodeH;
    //遍历
    foreach_Tree(&nodeA);
    //求叶子数量
    int num = 0;
    Leafnums(&nodeA,&num);
    printf("\n");
    printf("Amounts of leaves: %d\n",num);
    //求树的深度
    int height = TreeHeight(&nodeA);
    printf("The height of the tree is: %d",height);
}
int main(){
    test1();
    return 0;
}