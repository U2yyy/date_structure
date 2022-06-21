#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct TreeNode{
    char name[9];
    int date;
    struct TreeNode *Left;
    struct TreeNode *Right;
};
struct TreeNode* Insert(const char name[9],int date,struct TreeNode *root){
    if(!root){
        root = malloc(sizeof(struct TreeNode));
        strcpy(root->name,name);
        root->date = date;
        root->Left = root->Right = NULL;
    }else if(date<root->date)
        root->Left = Insert(name,date,root->Left);
    else if(date>root->date)
        root->Right = Insert(name,date,root->Right);
    return root;
}
struct TreeNode* FindLocation(int date,struct TreeNode *root){
    if(!root)
        return NULL;
    else if(date<root->date)
        return FindLocation(date,root->Left);
    else if(date>root->date)
        return FindLocation(date,root->Right);
    else
        return root;
}
struct TreeNode* FindMin(struct TreeNode *root){
    if(!root)
        return NULL;
    if(root->Left)
        FindMin(root->Left);
    else
        return root;
}
struct TreeNode* FindMax(struct TreeNode *root){
    if(!root)
        return NULL;
    if(root->Right)
        FindMax(root->Right);
    else
        return root;
}
struct TreeNode* Delete(int date,struct TreeNode *root){
    struct TreeNode *Temp;
    if(!root)
        printf("Not Found\n");
    else if(date<root->date)
        root->Left = Delete(date,root->Left);
    else if(date>root->date)
        root->Right = Delete(date,root->Right);
    else if(root->Left&&root->Right){//有两个儿子时，将右子树的最小结点替换这个结点
        Temp = FindMin(root->Right);
        root->date = Temp->date;
        root->Right = Delete(root->date,root->Right);
    }else{
        Temp = root;
        if(!root->Left)
            root = root->Right;
        else if(!root->Right)
            root = root->Left;
        free(Temp);
    }
    return root;
}
int main() {
    struct TreeNode *myTree;
    myTree = Insert("A",6,myTree);
    myTree = Insert("B",10,myTree);
    myTree = Insert("C",99,myTree);
    myTree = Insert("D",11,myTree);
    myTree = Insert("E",76,myTree);
    Delete(99,myTree);
    struct TreeNode *p = FindLocation(99,myTree);
    struct TreeNode *pMax = FindMax(myTree);
    struct TreeNode *pMin = FindMin(myTree);
    printf("%s\n",p->name);
    printf("The max:%s\n",pMax->name);
    printf("The min:%s\n",pMin->name);
}
