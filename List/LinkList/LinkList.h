#include<stdio.h>

#define int ElemType
typedef struct LNode{
  ElemType data;
  struct LNode *next;
}LNode,*LinkList;

LinkList CreateList(LinkList *L){
  LNode *s;
  int x;
  L=(linkList)malloc(sizeof(LNode));
  L->next=NULL;
  scanf("%d",&x);
  while(x!=9999){
    s=(LNode*)malloc(sizeof(LNode));
    s->data=x;
    s->next=L->next;
    L->next=s;
    scanf("%d",&x);
  }
  return L;
}
//链表头结点
int main(){
  LinkList();
  exit();
}
