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
int main() {
    struct TreeNode *myTree;
    myTree = Insert("A",6,myTree);
    myTree = Insert("B",10,myTree);
    myTree = Insert("C",99,myTree);
    myTree = Insert("D",11,myTree);
    myTree = Insert("E",76,myTree);
    struct TreeNode *p = FindLocation(99,myTree);
    printf("%s",p->name);
}
