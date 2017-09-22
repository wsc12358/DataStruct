#include<stdio.h>
//-------线性表的动态分配顺序存储结构-----
#define LIST_INIT_SIZE 100   //线性表存储空间的初始分配量
#define LISTINCREMENT 10     //线性表存储空间的 分配增量
typedef struct{
 ElemType *elem;
 int length;
 int listsize;
}SqList;


