#ifndef _HEADERNAME_H
#define _HEADERNAME_H 
#include<stdio.h>
#include<stdlib.h>
#endif

#ifndef _STATUS_H
#define _STATUS_H 
 
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -1

#endif 

#ifndef _TYPE_H
#define _TYPE_H

typedef int Status;
typedef int BOOL;
typedef char ElemType;

#endif 


typedef struct LNode { //结点类型
  ElemType data;
  struct LNode *next;
}LNode,*Link,*Postion;

typedef struct{   //链表类型
  Link head,tail;  //分别指向线性链表的头结点和最后一个结点
  int len;          //指示线性链表中的数据元素的个数
}LinkList;

Status InsFirst(Link h,Link s);
Status DelFirst(Link h,Link q);
Status Append(LinkList* L,Link s);
Status Remove(LinkList* L,Link q);
Status InsBefore(LinkList* L,Link p,Link s);
Status InsAfter(LinkList* L,Link p,Link s);
Status SetCurElem(Link p,ElemType e);
ElemType GetCurElem(Link p);
BOOL ListEmpty(LinkList L);
int ListLength(LinkList L);
Postion GetHead(LinkList L);
Postion GetLast(LinkList L);
Postion PriorPos(LinkList L,Link p);
Postion NextPos(Link p);
Status LocatePos(LinkList L,int i,Link p);
Postion LocateElem(LinkList L,ElemType e,Status (*compare)(ElemType,ElemType));
Status ListTraverse(LinkList L,Status (*visit)(ElemType));

Status max(ElemType e1,ElemType e2){
  return e1>e2?TRUE:FALSE;
}

Status min(ElemType e1,ElemType e2){
  return e1<e2?TRUE:FALSE;
}

Status equal(ElemType e1,ElemType e2){
  return e1==e2?TRUE:FALSE;
}

Status visit(ElemType e){
  printf("%c\t",e);
  return OK;
}
Status MakeNode(Link p,ElemType e){ //分配有p指向的值为e的结点，并返回OK，若分配失败，则返回ERROR
   p=(Link)malloc(sizeof(LNode)); 
   if(!p)
     exit(OVERFLOW);
   p->data=e;
   return OK;
}

void FreeNode(Link p){ //释放p所指结点
  free(p);
}

Status InitList_Link(LinkList* L){ //构造一个空的线性链表L
  L=(LinkList*)malloc(sizeof(LinkList));
  if(!L)
     exit(OVERFLOW);
  Link h=(Link)malloc(sizeof(LNode));
  L->head=h;
  L->tail=h;
  GetHead(*L)->next=NULL;
  L->len=0;
  return OK;
}

Status DestroyList_Link(LinkList* L){  //销毁线性链表L，L不再存在
   Link p,q;
   if(!L){
      printf("the LinkList is unexist\n");
      return ERROR;
   }
   p=GetHead(*L);
   for(q=p;p!=NULL;){
       p=p->next;
       FreeNode(q);
       q=p;
   }
   printf("Destroy LinkList scussessfully\n");
   return OK;
}

Status ClearList_Link(LinkList* L){ //将线性表L重置为空表，并释放原链表的结点空间
  if(!L){
    printf("the LinkList is unexist\n");
    return ERROR;
  }

  Link q;
  while(GetHead(*L)->next){
    if(!DelFirst(GetHead(*L),q)){
        exit(ERROR);   
    }
  }
  (*L).len=0;  
  (*L).tail=GetHead(*L);
  printf("clearing the LinkList is successfully\n");
  return OK;
}

Status InsFirst(Link h,Link s){ //已知h指向链表的头结点，将s所指结点插入在第一个结点之前
  (*s).next=(*h).next;
  (*h).next=s;
  return OK;
}

Status DelFirst(Link h,Link q){  //已知h指向线性链表的头结点，删除链表中的第一个结点并以q返回
  if(!(*h).next){
     printf("the LinkList is empty\n");
     return ERROR;
  }

  q=(*h).next;
  Link p=(*h).next;
  (*h).next=p->next;
  FreeNode(p);
  return OK;
}

Status Append(LinkList* L,Link s){  //将指针s所指（彼此以指针相连） 的一串结点链接在线性链表L的最后一个结点，之后，并改变链表L的尾指针指向新的新的尾结点
   if(!L){
     printf("the LinkList is unexist\n");
     return ERROR;
   }
  
   GetLast(*L)->next=s;
   Link p;
   for(p=GetLast(*L);p->next!=NULL;p=p->next){
        (*L).len++;
   }
   (*L).tail=p;
   return OK;
}

Status Remove(LinkList* L,Link q){  //删除线性链表L中的尾结点并以q返回，改变链表L的尾指针指向新的尾结点
  if(!L){
    printf("the LinkList is unexist\n");
    return ERROR;
  }
  Link p;
  for(p=GetHead(*L);p->next!=GetLast(*L);p=p->next);  
  if(p!=GetHead(*L)){
    p->next=GetLast(*L)->next;
    q=GetLast(*L);
    (*L).len--;
    FreeNode(q);
    (*L).tail=p;
  }
  return OK;
}

Status InsBefore(LinkList* L,Link p,Link s){ //已知p指向线性链表L中的一个结点，将s所指结点插入到p所指结点之前，并修改指针p执行新插入的结点
  if(!L){
    printf("the LinkList is unexist\n");
    return ERROR;
  }

  if(p!=GetHead(*L)){
    Link q;
    for(q=GetHead(*L);q->next!=p;q=q->next);
    s->next=q->next;
    q->next=s;
    (*L).len++;
  }
  return OK;
}

Status InsAfter(LinkList* L,Link p,Link s){ //已知p指向线性链表L中的一个结点，将s所指结点插入在p所指结点之后，并修改指针p指向新插入的结点
  if(!L){
    printf("the LinkList is unexist\n");
    return ERROR;
  }

  if(p!=GetHead(*L)){
    s->next=p->next;
    p->next=s;
    (*L).len++;
  }

  return OK;
}

Status SetCurElem(Link p,ElemType e){ //已知p指向线性表中的一个结点，用e更新p所指结点中的值
   if(!p){
     printf("the pointer p is null\n");
     return ERROR;
   }
   p->data=e;
   printf("reset the pointer p's value successfully\n");
   return OK;
}

ElemType GetCurElem(Link p){ //已知p指向线性链表中的一个结点，返回p所指结点中数据元素的值
   if(!p){
     printf("the pointer p is null\n");
     return ERROR;
   }

   return p->data;
}

BOOL ListEmpty(LinkList L){  //若线性链表L为空表，则返回TRUE，否则返回FALSE
  if(GetHead(L)==GetLast(L))
    return OK;
  return FALSE;
}

int ListLength(LinkList L){  //返回线性链表L中元素个数
   return L.len;   
}

Postion GetHead(LinkList L){ //返回线性链表L中头结点的位置
  return L.head;
}

Postion GetLast(LinkList L){  //返回线性表L中最后一个结点的位置
  return L.tail;
}

Postion PriorPos(LinkList L,Link p){  //已知p指向线性链表L中的一个结点，返回p所指结点的直接前驱的位置
  Link q;
  for(q=GetHead(L);q->next!=p;q=q->next);
  return q;
}

Postion NextPos(Link p){  //已知p指向线性链表L中的一个结点，返回p所指结点的直接后继的位置
  return p->next;
}

Status LocatePos(LinkList L,int i,Link p){ //返回p指示线性链表L中第i个结点的位置并返回OK，i值不合法时返回ERROR
   if(i<1||i>ListLength(L))
     return FALSE;
   Link q=GetHead(L)->next;
   for(int j=1;j<i;j++){
     q=q->next;
   }
   p=q;
   return OK;
}

Postion LocateElem(LinkList L,ElemType e,Status (*compare)(ElemType,ElemType)){ 
//返回线性链表L中的第1个与e满足函数compare()判定关系的元素的位置，若不存在这样的元素，则返回NULL
   if(!ListLength(L))
      return NULL;
   Link p=GetHead(L)->next;
   for(int i=0;i<ListLength(L);i++){
     if((*compare)(e,GetCurElem(p)))
	  return p;
     p=p->next;
   }

   return NULL;
}

Status ListTraverse(LinkList L,Status (*visit)(ElemType)){ //依次对L的每个元素调用visit()，一旦visit()失败，则操作失败
   Link q=GetHead(L)->next;
   for(int i=0;i<ListLength(L);i++){
     if((*visit)(GetCurElem(q)))
        q=q->next;
     else
	return FALSE;
   }
   return OK;
}

Status ListInsert_Link(LinkList* L,int i,ElemType e){
  Link h=NULL,s=NULL;
  if(!LocatePos(*L,i,h))
     return ERROR;
  if(!MakeNode(s,e))
     return ERROR;
  InsFirst(h,s);
  (*L).len++;
  return OK;
}
