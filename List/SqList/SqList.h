#include<stdio.h>
#include<stdlib.h>
//-------线性表的动态分配顺序存储结构-----
#define LIST_INIT_SIZE 100   //线性表存储空间的初始分配量
#define LISTINCREMENT 10     //线性表存储空间的 分配增量
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef char ElemType  
typedef int Status 
typedef int BOOL

typedef struct{
 ElemType *elem; //存储空间地址
 int length;  //当前长度
 int listsize; //当前分配的存储容量
}SqList;

BOOL max(ElemType* e1,ElemType *e2){
  return *e1>*e2:TRUE,FALSE;
}

BOOL min(ElemType *e1,ElemType *e2){
  return *e1<*e2:TRUE,FALSE;
}

BOOL equal(ElemType *e1,ElemType *e2){
  return *e1==*e2:TRUE,FALSE;
}

void visit(ElemType e){
  printf("%c\t",e); 
}

Status InitList_Sq(SqList *L){
  //构造一个空的线性表L
  (*L).elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
  if(!(*L).elem) 
     exit(OVERFLOW);
  (*L).length=0;
  (*L).listsize=LIST_INIT_SIZE;
  return OK;
}

Status DestroyList_Sq(SqList *L){   //线性表已存在，销毁线性表L
  if(!(*L).elem){
    printf("can't destroy sqlist,it's unexist\n");
    return ERROR;
  }

  free((*L).elem);
  printf("destroy sqlist successfully!\n");
  return OK;
}

Status ClearList_Sq(SqList *L){ //线性表已存在，线性表清空
  if(!(*L).elem){
    printf("can't clear sqlist,it's unexist");
    return ERROR;
  }

  (*L).length=0;
  printf("clear sqlist successfully!\n");
  return OK;
}

BOOL ListEmpty_Sq(SqList *L){ //线性表已存在，若线性表为空，返回True，否则返回false
   if(!(*L).elem){
     printf("the sqlist is unexist\n");
     return FALSE;
   }
   if((*L).length==0)
     return TRUE;
   return FALSE;
}

int ListLength_Sq(SqList *L){ //返回线性表中元素个数
   if(!(*L).elem){
     printf("the sqlist is unexist\n");
     return 0;
   }

   return (*L).length;
}

BOOL GetElem_Sq(SqList *L,int i,Elemtype * e){ //用e返回L中第i个数据元素的值 
   if(!(*L).elem){
     printf("the sqlist is unexist\n");
     return FALSE;
   }

   if(i>(*L).length||i<1){
     printf("the locate cursor out of bounds\n");
     return FALSE;
   }

   *e=(*L).elem[i-1];
}

int LocateElem_Sq(SqList *L,Elemtype e,ElemType (*compare)(ElemType*,ElemType*)){ //线性表已经存在，compare()找出L中第一个与e满足关系compare()的数据元素的位序，若这样的元素不存在，则返回0
   if(!(*L).elem){
     printf("the sqlist is unexist\n");
     return 0;
   }

   for(int i=0;i<(*L).length;i++){
     if(*compare(&e,&(*L).elem[i]))
	return i+1;
   }

   //前面未返回，此时已说明要找的元素不存在，返回0
   return 0;
}

Status PriorElem_Sq(SqList * L,ElemType cur_e,ElemType *pre_e){  //若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败，pre_e无定义
   if(!(*L).elem){
     printf("the sqlist is unexist\n");
     return 0;
   }
   
   int i,j;
   if((*L).length<=1){
     printf("the elem haven't priorelem\n");
     return ERROR;
   }
   for(i=j=1;i<(*L).length;j=i,i++){
     if((*L).elem[i]==cur_e){
       *pre_e=(*L).elem[j];
       return OK;
     }
   }

   return ERROR;
}

ElemType NextElem_Sq(SqList *L,ElemType cur_e,ElemType *next_e){ //若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，next_e无定义
  
   if(!(*L).elem){
     printf("the sqlist is unexist\n");
     return 0;
   }
   
   int i,j;
   for(i=1;i<(*L).length;i++){
     if((*L).elem[i]==cur_e&&i<(*L).length-1){
         *next_e=(*L).elem[j];
         return OK;
     }
   }

   return ERROR;
}

Status ListInsert_Sq(SqList *L,int i,ElemType e){  //在L中第i个位置之前插入新的数据元素e，L的长度加1
    SqList* newbase;
    if(i<1||i>(*L).length+1)  return ERROR;
    if((*L).length>=(*L).listsize){ //当前存储空间已满，增加分配
      newbase=(ElemType*)realloc((*L).elem,((*L).listsize+LISTINCREMENT)*sizeof(ElemType));
      if(!newbase)
	 exit(OVERFLOW);
      *L.elem=newbase;
      *L.listsize+=LISTINCREMENT;
    }

    ElemType* q=&(*L.elem[i-1]);
    for(ElemType p=&(*L.elem[*L.length-1]);p>=q;--p)
	*(p+1)=*p;

    *q=e;
    ++(*L).length;
    return OK;
}

Status ListDelete_Sq(SqList* L,int i,ElemType* e){ //删除L的第i个数据元素，并用e返回值，L的长度减1
   if(i<1||i>*L.length)  return ERROR;
   ElemType *p=&(*L.elem[i-1]);
   *e=*p;
   ElemType* q=*L.elem+*L.length-1;
   for(++p;p<=q;++p)
     *(p-1)=*p;
   --(*L).length;
   return OK;
}

Status ListTraverse_Sq(SqList* L,void (*visit)(ElemType)){ //依次对L的每个数据元素调用函数visit(),一旦visit()失败，则操作失败
  if(*L.length<1)
    return ERROR;
  for(int i=0;i<*L.length;i++){
    (*visit)(*L.elem[i]);
  }
  return OK;
}

