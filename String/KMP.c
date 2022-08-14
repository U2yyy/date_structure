#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

void getNext(int* next,char pattern[],int length);
int KMP_search(char *s,char *p,int pos,int p_length,int s_length);

int main()
{
    char p[] = "abcabx";
    char s[] = "babcabxss";
/*     int l = sizeof(p)/sizeof(p[0]) - 1;
    int next[l];
    getNext(next,p,l);
    for(int i =0;i<l;i++)
    {
        printf("%d ",next[i]);
    } */
    int p_length = sizeof(p)/sizeof(p[0])-1;
    int s_length = sizeof(s)/sizeof(s[0])-1;
    int pos = KMP_search(s,p,0,p_length,s_length);
    printf("%d ",pos);
    system("pause");
}

void getNext(int* next,char pattern[],int length)
{
    next[0] = 0;
    int i = 0,j = 1;
    while(j<length)
    {
        if(pattern[j] == pattern[i])
        {   
            next[j] = i+1;
            j++;
            i++;
        }
        else if(i == 0)
        {
            next[j] = i;
            j++;
        }
        else
        {
            i = next[i];
        }
    }
}

int KMP_search(char *s,char *p,int pos,int p_length,int s_length)
{
    int i = pos;
    int j = 0;
    int next[256];
    getNext(next,p,p_length);
    while(i<s_length&&j<p_length)
    {
        if(s[i] == p[j])
        {
            i++;
            j++;
        }
        else if(j == 0)
        {
            i++;
        }
        else
        {
            j = next[j];
        }
    }
    if(j == p_length)
    {
        return i-j;
    }
    else
    {
        return -1;
    }
}