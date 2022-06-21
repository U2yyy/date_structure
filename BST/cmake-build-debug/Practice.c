//
// Created by Programmer on 2022/6/21.
//
//This .c file is for practicing BinTree operations
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct TreeNode{
    char name[99];
    int date;
    struct TreeNode *Left;
    struct TreeNode *Right;
}*BinTree;
BinTree Insert(const char name[99],const int date,BinTree root){
    if(!root){
        root = malloc(sizeof(BinTree));
        root->date = date;
        strcpy(root->name,name);
        root->Left = root->Right = NULL;
    }
    else if(date<root->date)
        root->Left = Insert(name,date,root->Left);
    else if(date>root->date)
        root->Right = Insert(name,date,root->Right);
    else
        return root;
}
BinTree FindLocation(int date,BinTree root){
    if(!root)
        return NULL;
    else if(date<root->date)
        return FindLocation(date,root->Left);
    else if(date>root->date)
        return FindLocation(date,root->Right);
    else
        return root;
}
BinTree FindMax(BinTree root){
    if(!root)
        return NULL;
    if(root->Right)
        return FindMax(root->Right);
    else
        return root;
}
BinTree FindMin(BinTree root){
    if(!root)
        return NULL;
    if(root->Left)
        return FindMin(root->Left);
    else
        return root;
}
BinTree Delete(const int date,BinTree root){
    BinTree Temp;
    if(!root)
        return NULL;
    else if(date<root->date)
        root->Left = Delete(date,root->Left);
    else if(date>root->date)
        root->Right = Delete(date,root->Right);
    else{
        if(root->Left&&root->Right){
            Temp = FindMax(root->Left);
            root->date = Temp->date;
            strcpy(root->name,Temp->name);
            root->Left = Delete(root->date,root->Left);
        } else {
            Temp = root;
            if (!root->Left)
                root = root->Right;
            if (!root->Right)
                root = root->Left;
            free(Temp);
        }
    }
    return root;
}